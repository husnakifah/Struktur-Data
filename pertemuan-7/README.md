### Implementasi queue berbasis array
---

### 1. Inisialisasi dan Status Awal (`Queue()` & Variabel Penunjuk)

* **`MAX = 5`**: Menentukan kapasitas maksimal antrean, yaitu hanya bisa menampung 5 elemen (indeks `0` sampai `4`).
* **`front` dan `rear**`: Dua variabel penunjuk (*pointer* indeks). `front` bertugas mencatat elemen paling depan (yang akan keluar pertama), sedangkan `rear` mencatat elemen paling belakang (tempat elemen baru masuk).
* **Konstruktor `Queue()**`: Saat objek antrean pertama kali dibuat, nilai `front` dan `rear` diatur ke `-1`. Ini adalah penanda bahwa antrean masih dalam keadaan **kosong**.

### 2. Pengecekan Kondisi (`isEmpty` & `isFull`)

* **`isEmpty()`**: Antrean dianggap kosong jika nilai `front == -1`. Logika ini sangat sederhana dan efektif untuk mendeteksi apakah ada data di dalam array.
* **`isFull()`**: Antrean dianggap penuh jika nilai `rear == MAX - 1` (dalam kasus ini, `rear == 4`). Karena array dimulai dari indeks `0`, maka indeks ke-4 menandakan slot terakhir sudah terisi.

### 3. Logika Menambah Elemen (`enqueue`)

Fungsi ini menggunakan prinsip **FIFO (First In, First Out)** di mana elemen baru selalu masuk dari belakang.

* **Cek Penuh**: Sebelum memasukkan data, program mengecek `isFull()`. Jika penuh, muncul pesan "Queue Overflow" dan proses dibatalkan.
* **Kondisi Elemen Pertama**: Jika antrean awalnya kosong (`isEmpty()`), maka variabel `front` yang tadinya `-1` harus diubah menjadi `0`. Ini karena elemen pertama yang masuk otomatis menjadi elemen terdepan.
* **Memasukkan Data**: Variabel `rear` dinaikkan terlebih dahulu (`++rear`), baru kemudian data `x` dimasukkan ke dalam array pada indeks `rear` yang baru tersebut (`arr[++rear] = x`).

### 4. Logika Menghapus Elemen (`dequeue`)

Fungsi ini menghapus elemen yang berada di posisi paling depan.

* **Cek Kosong**: Program mengecek `isEmpty()`. Jika tidak ada data, muncul pesan "Queue Underflow" dan proses dibatalkan.
* **Mengambil Data**: Elemen yang dihapus/dikeluarkan selalu elemen pada indeks `front` (`arr[front]`).
* **Kondisi Elemen Terakhir**: Program mengecek apakah `front == rear`. Jika iya, artinya elemen yang baru saja dihapus adalah **satu-satunya elemen tersisa** di antrean. Maka, antrean diatur ulang (*reset*) kembali ke kondisi kosong dengan mengubah `front = rear = -1`.
* **Kondisi Umum**: Jika masih ada elemen lain di belakangnya, posisi `front` cukup digeser maju ke indeks berikutnya (`front++`).

### 5. Logika Menampilkan Antrean (`display`)

* Program melakukan pengecekan apakah antrean kosong atau tidak.
* Jika berisi data, program akan melakukan perulangan (*looping*) menggunakan *for-loop*, dimulai dari indeks `front` hingga indeks `rear` (`for (int i = front; i <= rear; i++)`). Hal ini memastikan hanya elemen yang valid saja yang dicetak ke layar.

---

### Alur Eksekusi pada `main()`:

1. **`enqueue(10), (20), (30)`**: Angka 10 masuk (`front=0, rear=0`), lalu 20 masuk (`rear=1`), lalu 30 masuk (`rear=2`).
2. **`display()` pertama**: Mencetak data dari indeks `0` sampai `2`, hasilnya: `10 20 30`.
3. **`dequeue()`**: Elemen terdepan (angka 10 pada `front=0`) dikeluarkan. Nilai `front` bergeser naik menjadi `1`.
4. **`display()` kedua**: Mencetak data dari indeks `1` sampai `2`, hasilnya: `20 30`.

output: 

![output](pertemuan-7/img/queue.png)


### Implementasi Queue berbasis Linked List

---

### 1. Struktur Node dan Status Awal

* **`struct Node`**: Kerangka dasar pembentuk antrean. Setiap *Node* memiliki dua kompartemen: `data` (untuk menyimpan angka) dan `next` (pointer/alamat memori untuk menunjuk ke elemen di belakangnya).
* **`front` dan `rear**`: Dua buah pointer khusus. `front` selalu menunjuk ke *Node* pertama yang siap keluar, dan `rear` menunjuk ke *Node* paling terakhir yang baru masuk.
* **`Queue()` (Konstruktor)**: Saat objek antrean pertama kali dibuat, `front = rear = NULL`. Nilai `NULL` menandakan bahwa antrean masih bersih dan **kosong**.

### 2. Pengecekan Kondisi (`isEmpty`)

* **`isEmpty()`**: Hanya mengecek apakah `front == NULL`. Jika pointer yang bertugas mencatat elemen terdepan bernilai kosong (`NULL`), berarti otomatis seluruh antrean tidak memiliki isi.

### 3. Logika Memasukkan Elemen (`enqueue`)

Fungsi ini menyambungkan elemen baru ke barisan paling belakang:

* **Alokasi Memori (`new Node()`)**: Program membuat satu kotak data baru di memori, mengisi datanya dengan `x`, dan mengatur pointer `next`-nya ke `NULL` (karena dia berdiri di posisi paling belakang dan belum ada orang lain di belakangnya).
* **Kondisi Antrean Kosong (`rear == NULL`)**: Jika awalnya tidak ada siapa-siapa, maka *Node* baru ini langsung ditunjuk oleh `front` dan `rear` sekaligus. Dia menjadi elemen pertama sekaligus terakhir.
* **Kondisi Antrean Berisi**: Jika sudah ada elemen di dalam antrean:
1. Sambungkan elemen terakhir yang lama ke elemen baru (`rear->next = newNode`).
2. Pindahkan status penanda belakang ke elemen yang baru tersebut (`rear = newNode`).



### 4. Logika Mengeluarkan Elemen (`dequeue`)

Fungsi ini menghapus elemen yang berada di barisan paling depan:

* **Proteksi Kosong**: Memanggil `isEmpty()`. Jika benar kosong, program membatalkan penghapusan agar tidak terjadi *error*.
* **Pointer Bantuan (`Node* temp = front`)**: Program membuat pointer sementara (`temp`) untuk "memegang" *Node* terdepan yang akan dihapus, agar alamat memorinya tidak hilang saat kita geser.
* **Menggeser Posisi Depan**: Pointer `front` dipindahkan ke elemen di belakangnya (`front = front->next`).
* **Kondisi Khusus (Elemen Terakhir Habis)**: Setelah digeser, program mengecek `if (front == NULL)`. Jika ternyata setelah maju `front` menjadi `NULL`, artinya antrean kini kosong total. Maka dari itu, `rear` juga harus diatur menjadi `NULL`.
* **Pembersihan Memori (`delete temp`)**: Menghapus *Node* terdepan asli dari memori komputer untuk mencegah kebocoran memori (*memory leak*).

### 5. Logika Menampilkan Antrean (`display`)

* Menggunakan pointer bantuan `temp` yang diposisikan di awal antrean (`front`).
* Menggunakan perulangan `while (temp != NULL)` untuk menelusuri rantai *Node* satu per satu. Di setiap langkah, program mencetak `temp->data` lalu melompat ke *Node* berikutnya lewat perintah `temp = temp->next`. Perulangan akan otomatis berhenti ketika mencapai ujung rantai yang bernilai `NULL`.

---

### Ilustrasi Jalannya Program pada `main()`:

1. **`q.enqueue(5); q.enqueue(15); q.enqueue(25);`**
* Angka 5 masuk $\rightarrow$ `front` dan `rear` menunjuk ke Node(5).
* Angka 15 masuk $\rightarrow$ Node(5) menunjuk ke Node(15). `rear` pindah ke Node(15).
* Angka 25 masuk $\rightarrow$ Node(15) menunjuk ke Node(25). `rear` pindah ke Node(25).
* *Struktur:* `[5] -> [15] -> [25] -> NULL` (di mana `front` di 5, `rear` di 25).


2. **`q.display();`**
* Menelusuri dari `front` ke belakang. Output: `Isi Queue: 5 15 25`


3. **`q.dequeue();`**
* Node(5) dipegang oleh `temp`.
* `front` bergeser maju ke Node(15).
* Node(5) dihapus dari memori menggunakan perintah `delete`.
* *Struktur:* `[15] -> [25] -> NULL`.


4. **`q.display();`**
* Menelusuri dari posisi `front` yang baru. Output: `Isi Queue: 15 25`

output:

![output](pertemuan-7/img/linkedlist.png)
