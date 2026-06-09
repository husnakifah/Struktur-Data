#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur Node untuk merepresentasikan Folder
struct FolderNode {
    string name;
    FolderNode* parent;             // Pointer ke induk untuk mempermudah pencarian path
    vector<FolderNode*> children;   // Menyimpan banyak sub-folder (General Tree)

    FolderNode(string folderName, FolderNode* parentNode = nullptr) {
        name = folderName;
        parent = parentNode;
    }
};

class ComputerFolderSystem {
private:
    FolderNode* root;

    // Fungsi Helper Rekursif untuk Menampilkan Struktur Hierarki
    void displayHierarchyHelper(FolderNode* current, int depth) {
        if (current == nullptr) return;

        // Membuat indentasi visual menyerupai sistem operasi
        for (int i = 0; i < depth; i++) {
            if (i == depth - 1) cout << "└── ";
            else cout << "    ";
        }
        cout << current->name << "\n";

        for (FolderNode* child : current->children) {
            displayHierarchyHelper(child, depth + 1);
        }
    }

    // Fungsi Helper Rekursif untuk Mencari Folder Berdasarkan Nama
    FolderNode* findFolderHelper(FolderNode* current, string targetName) {
        if (current == nullptr) return nullptr;
        if (current->name == targetName) return current;

        for (FolderNode* child : current->children) {
            FolderNode* found = findFolderHelper(child, targetName);
            if (found != nullptr) return found; // Jika ketemu di sub-folder, langsung kembalikan
        }
        return nullptr;
    }

    // Fungsi Helper Rekursif untuk Menghitung Jumlah Folder
    int countFoldersHelper(FolderNode* current) {
        if (current == nullptr) return 0;
        
        int count = 1; // Hitung dirinya sendiri
        for (FolderNode* child : current->children) {
            count += countFoldersHelper(child);
        }
        return count;
    }

    // Fungsi Helper Rekursif untuk Menghapus Seluruh Isi Folder (Memory Cleansing)
    void deleteTree(FolderNode* current) {
        if (current == nullptr) return;
        for (FolderNode* child : current->children) {
            deleteTree(child);
        }
        delete current;
    }

public:
    ComputerFolderSystem(string rootName) {
        root = new FolderNode(rootName);
    }

    ~ComputerFolderSystem() {
        deleteTree(root);
    }

    // 1. Membuat Folder Baru
    bool createFolder(string parentName, string newFolderName) {
        FolderNode* parentNode = findFolderHelper(root, parentName);
        if (parentNode == nullptr) {
            cout << "Error: Folder induk '" << parentName << "' tidak ditemukan.\n";
            return false;
        }
        
        // Cek apakah nama folder sudah ada di dalam direktori yang sama
        for (FolderNode* child : parentNode->children) {
            if (child->name == newFolderName) {
                cout << "Error: Folder '" << newFolderName << "' sudah ada di dalam '" << parentName << "'.\n";
                return false;
            }
        }

        FolderNode* newFolder = new FolderNode(newFolderName, parentNode);
        parentNode->children.push_back(newFolder);
        cout << "Sukses: Folder '" << newFolderName << "' berhasil dibuat di dalam '" << parentName << "'.\n";
        return true;
    }

    // 2. Menghapus Folder beserta isinya
    bool deleteFolder(string folderName) {
        if (folderName == root->name) {
            cout << "Error: Root folder '" << folderName << "' tidak boleh dihapus.\n";
            return false;
        }

        FolderNode* targetNode = findFolderHelper(root, folderName);
        if (targetNode == nullptr) {
            cout << "Error: Folder '" << folderName << "' tidak ditemukan.\n";
            return false;
        }

        FolderNode* parentNode = targetNode->parent;
        
        // Hapus targetNode dari daftar children milik parent-nya
        for (auto it = parentNode->children.begin(); it != parentNode->children.end(); ++it) {
            if ((*it)->name == folderName) {
                parentNode->children.erase(it);
                break;
            }
        }

        // Hapus secara rekursif semua sub-folder di dalamnya dari memori
        deleteTree(targetNode);
        cout << "Sukses: Folder '" << folderName << "' beserta seluruh isinya berhasil dihapus.\n";
        return true;
    }

    // 3. Menampilkan Struktur Direktori Hierarki
    void displayHierarchy() {
        cout << "\n=== STRUKTUR DIREKTORI ===\n";
        displayHierarchyHelper(root, 0);
        cout << "==========================\n";
    }

    // 4. Mencari Folder
    void searchFolder(string folderName) {
        FolderNode* found = findFolderHelper(root, folderName);
        if (found != nullptr) {
            cout << "Folder '" << folderName << "' Ditemukan!\n";
        } else {
            cout << "Folder '" << folderName << "' Tidak Ditemukan.\n";
        }
    }

    // 5. Menghitung Jumlah Total Folder
    int getTotalFolders() {
        return countFoldersHelper(root);
    }

    // 6. Menampilkan Path Lengkap
    void displayFullPath(string folderName) {
        FolderNode* targetNode = findFolderHelper(root, folderName);
        if (targetNode == nullptr) {
            cout << "Error: Folder '" << folderName << "' tidak ditemukan.\n";
            return;
        }

        // Mundur ke atas menggunakan pointer parent untuk merakit path
        string path = "";
        FolderNode* current = targetNode;
        while (current != nullptr) {
            path = "/" + current->name + path;
            current = current->parent;
        }
        cout << "Full Path dari '" << folderName << "': " << path << "\n";
    }

    // Traversal: Preorder (Induk -> Anak-anak)
    void preorderTraversal(FolderNode* current) {
        if (current == nullptr) return;
        cout << current->name << " ";
        for (FolderNode* child : current->children) {
            preorderTraversal(child);
        }
    }

    void showPreorder() {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << "\n";
    }

    // Traversal: Postorder (Anak-anak -> Induk)
    void postorderTraversal(FolderNode* current) {
        if (current == nullptr) return;
        for (FolderNode* child : current->children) {
            postorderTraversal(child);
        }
        cout << current->name << " ";
    }

    void showPostorder() {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << "\n";
    }
};

int main() {
    // Inisialisasi Root utama komputer (misal folder "C:")
    ComputerFolderSystem system("C:");

    // --- 1. Membuat Folder Baru ---
    system.createFolder("C:", "Users");
    system.createFolder("C:", "ProgramFiles");
    system.createFolder("Users", "Alice");
    system.createFolder("Users", "Bob");
    system.createFolder("Alice", "Documents");
    system.createFolder("Documents", "Tugas_Strukdat");

    // --- 3. Menampilkan Struktur Direktori Awal ---
    system.displayHierarchy();

    // --- 4. Mencari Folder ---
    system.searchFolder("Tugas_Strukdat");
    system.searchFolder("Downloads");

    // --- 5. Menghitung Jumlah Folder ---
    cout << "Total jumlah folder saat ini: " << system.getTotalFolders() << "\n\n";

    // --- 6. Menampilkan Path Lengkap ---
    system.displayFullPath("Tugas_Strukdat");
    system.displayFullPath("Bob");

    // --- Implementasi Traversal ---
    system.showPreorder();
    system.showPostorder();

    // --- 2. Menghapus Folder (Misal menghapus folder Alice beserta isinya) ---
    system.deleteFolder("Alice");
    
    // Tampilkan kembali setelah dihapus
    system.displayHierarchy();
    cout << "Total jumlah folder setelah penghapusan: " << system.getTotalFolders() << "\n";

    return 0;
}
