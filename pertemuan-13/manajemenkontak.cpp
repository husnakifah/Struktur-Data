#include <iostream>
#include <string>
using namespace std;

// Setiap Node menyimpan Nama Kontak dan Nomor Telepon
struct ContactNode {
    string name;
    string phoneNumber;
    ContactNode* left;
    ContactNode* right;
};

// Fungsi untuk membuat kontak baru
ContactNode* createContact(string name, string phone) {
    ContactNode* newContact = new ContactNode();
    newContact->name = name;
    newContact->phoneNumber = phone;
    newContact->left = nullptr;
    newContact->right = nullptr;
    return newContact;
}

// Fungsi insert: Mengurutkan kontak otomatis berdasarkan Abjad Nama (A-Z)
ContactNode* insertContact(ContactNode* root, string name, string phone) {
    if (root == nullptr) {
        return createContact(name, phone);
    }

    // Jika abjad nama baru lebih kecil (misal: 'Alice' < 'Charlie'), taruh di kiri
    if (name < root->name) {
        root->left = insertContact(root->left, name, phone);
    }
    // Jika abjad nama baru lebih besar (misal: 'Zack' > 'Charlie'), taruh di kanan
    else if (name > root->name) {
        root->right = insertContact(root->right, name, phone);
    }
    
    return root;
}

// Fungsi search: Mencari nomor telepon berdasarkan nama dengan cepat
ContactNode* searchContact(ContactNode* root, string targetName) {
    if (root == nullptr || root->name == targetName) {
        return root;
    }

    // Saring jalur pencarian berdasarkan abjad
    if (targetName < root->name) {
        return searchContact(root->left, targetName); // Cari ke kiri saja
    } else {
        return searchContact(root->right, targetName); // Cari ke kanan saja
    }
}

// Menampilkan semua kontak secara urut abjad A-Z (Inorder Traversal)
void displayAllContacts(ContactNode* root) {
    if (root != nullptr) {
        displayAllContacts(root->left);
        cout << "- " << root->name << " (" << root->phoneNumber << ")\n";
        displayAllContacts(root->right);
    }
}

int main() {
    ContactNode* phonebook = nullptr;

    // Sistem otomatis menyusun kontak berdasarkan abjad saat disimpan
    phonebook = insertContact(phonebook, "Charlie", "0811-1111");
    insertContact(phonebook, "Alice", "0822-2222");
    insertContact(phonebook, "Ejen", "0833-3333");
    insertContact(phonebook, "Bob", "0844-4444");
    insertContact(phonebook, "Deni", "0855-5555");

    cout << "=== DAFTAR KONTAK HP (Otomatis Urut A-Z) ===\n";
    displayAllContacts(phonebook);
    cout << "===========================================\n\n";

    // Simulasi mengetik nama di kolom pencarian HP
    string pencarian = "Bob";
    cout << "Mengetik di kolom pencarian: '" << pencarian << "'...\n";
    
    ContactNode* hasil = searchContact(phonebook, pencarian);
    
    if (hasil != nullptr) {
        cout << "Kontak Ditemukan! -> Nomor " << hasil->name << ": " << hasil->phoneNumber << endl;
    } else {
        cout << "Kontak tidak ditemukan.\n";
    }

    return 0;
}
