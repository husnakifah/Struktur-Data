### Implementasi Tree pada Sistem Folder Komputer 

1. Implementasi General Tree Non-Binary
Karena folder di komputer aslinya bisa menampung banyak sub-folder sekaligus (tidak cuma dua seperti Binary Tree), kita menggunakan tipe data vector<FolderNode*> children. Setiap kali folder baru dibuat dengan fungsi createFolder(), alamat memorinya langsung dimasukkan (push_back) ke dalam vektor milik folder induknya.

2. Logika Menampilkan Hierarki ala OS (displayHierarchy)
Fungsi ini berjalan secara rekursif membawa variabel depth (kedalaman tingkat folder). Variabel depth ini dikalikan dengan spasi atau karakter garis (└── ) untuk membentuk efek visual tingkatan folder berundak. Semakin dalam posisi foldernya, semakin menonjol visual indentasinya ke kanan.

3. Logika Menampilkan Path Lengkap (displayFullPath)
Untuk membuat full path (misal: /C:/Users/Alice/Documents), logikanya dibalik:

Program mencari folder target terlebih dahulu menggunakan fungsi pencarian.

Setelah ketemu, program melakukan perulangan mundur ke atas menelusuri pointer current->parent sampai menyentuh root.

Teks digabungkan secara prepend (path = "/" + current->name + path) agar urutannya otomatis menjadi dari depan ke belakang.

4. Logika Penghapusan Terstruktur (deleteFolder & deleteTree)
Menghapus folder di dunia nyata berarti menghapus seluruh sub-folder di dalamnya. Logika deleteTree berjalan secara Postorder (menghapus anak-anak terdalamnya dulu, baru menghapus dirinya sendiri). Hal ini wajib dilakukan agar tidak terjadi memory leak (kehilangan jejak memori anak ketika induknya dihapus duluan).

5. Analisis Traversal yang Digunakan
Preorder (C: Users Alice Documents ...): Cocok digunakan untuk menduplikasi/meng-copy sistem folder dari satu tempat ke tempat lain karena folder induk diciptakan terlebih dahulu sebelum sub-foldernya dibuat.

Postorder (Tugas_Strukdat Documents Alice ... C:): Cocok digunakan saat proses penghapusan folder (seperti fungsi deleteTree) atau menghitung ukuran total disk space (kapasitas byte baru bisa diketahui setelah semua file di dalam anak-anak folder dihitung).

output:

![output}(output.img)
