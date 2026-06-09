#include <iostream>
#include <vector>
using namespace std;

// Struktur node dasar B-Tree
class BTreeNode {
public:
    vector<int> keys; 
    vector<BTreeNode*> children;
    int m;       // Menyimpan Orde dari B-Tree
    bool leaf;   // Penanda apakah ini leaf node

    BTreeNode(int _m, bool _leaf) {
        m = _m;
        leaf = _leaf;
    }

    // Traverse data secara terurut
    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!leaf) children[i]->traverse();
            cout << " " << keys[i];
        }
        if (!leaf) children[i]->traverse();
    }

    // Fungsi Insert ketika node belum penuh
    void insertNonFull(int k) {
        int i = keys.size() - 1;

        if (leaf) {
            keys.push_back(0); // Buat ruang kosong
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
        } else {
            while (i >= 0 && keys[i] > k) i--;
            // Jika child yang akan dituju penuh, lakukan Split
            if (children[i + 1]->keys.size() == m - 1) {
                splitChild(i + 1, children[i + 1]);
                if (keys[i + 1] < k) i++;
            }
            children[i + 1]->insertNonFull(k);
        }
    }

    // Memecah child yang penuh
    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->m, y->leaf);
        int mid = (m - 1) / 2;
        
        // Memindahkan setengah keys ke node baru (z)
        for (int j = mid + 1; j < y->keys.size(); j++)
            z->keys.push_back(y->keys[j]);
        
        if (!y->leaf) {
            for (int j = mid + 1; j <= y->keys.size(); j++)
                z->children.push_back(y->children[j]);
        }
        
        int midKey = y->keys[mid];
        
        y->keys.resize(mid);
        if (!y->leaf) y->children.resize(mid + 1);
        
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, midKey);
    }
};

// Pengelola utama B-Tree
class BTree {
public:
    BTreeNode* root;
    int m; // Orde (Maksimal child)

    BTree(int _m) {
        root = NULL;
        m = _m;
    }

    void traverse() { if (root != NULL) root->traverse(); }

    // Memasukkan key dengan algoritma preventif split
    void insert(int k) {
        if (root == NULL) {
            root = new BTreeNode(m, true);
            root->keys.push_back(k);
        } else {
            // Jika kapasitas key root sudah mencapai batas maksimal (m - 1)
            if (root->keys.size() == m - 1) {
                BTreeNode* s = new BTreeNode(m, false);
                s->children.push_back(root);
                s->splitChild(0, root);
                
                int i = 0;
                if (s->keys[0] < k) i++;
                s->children[i]->insertNonFull(k);
                
                root = s; // Root lama dipecah, node baru menjadi root
            } else {
                root->insertNonFull(k);
            }
        }
    }
};

int main() {
    // Membuat B-Tree dengan orde m = 3
    // Batas maksimum key per node adalah (3 - 1) = 2 keys.
    BTree t(3); 
    
    cout << "=== TESTING B-TREE (Order m = 3) ===" << endl;
    
    // Memasukkan data acak untuk memicu split internal berkali-kali
    cout << "Inserting elements: 10, 20, 5, 6, 12, 30, 7, 17" << endl;
    t.insert(10);
    t.insert(20);
    t.insert(5);  // Memicu pembelahan root pertama kali karena max key = 2
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    // Menampilkan seluruh isi B-Tree lewat pencetakan terurut
    cout << "Traversal B-Tree (Sorted Product):";
    t.traverse();
    cout << "\n====================================" << endl;

    return 0;
}
