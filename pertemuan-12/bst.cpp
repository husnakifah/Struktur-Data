#include <iostream>
using namespace std;

// Struktur node
struct Node {
    int data;
    Node* left;
    Node* right;
};
// Membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Fungsi insert
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
// Fungsi inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    }
}
// Fungsi search
bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    cout << "Inorder Traversal: ";

    inorder(root);
    cout << endl;
    int key = 60;
    if (search(root, key)) {
        cout << "Data ditemukan" << endl;
    }
    else {
        cout << "Data tidak ditemukan" << endl;
    }
    return 0;
}
