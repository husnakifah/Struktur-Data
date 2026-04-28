#include <iostream>
#include <string>

using namespace std;

#define MAX 5

struct Queue {
    int front = -1;
    int rear = -1;
    string mahasiswa[MAX];
};

bool isEmpty(Queue &q) { return q.front == -1; }
bool isFull(Queue &q) { return q.rear == MAX - 1; }

void enqueue(Queue &q, string nama) {
    if (isFull(q)) {
        cout << "Antrian penuh!\n";
    } else {
        if (isEmpty(q)) q.front = 0;
        q.rear++;
        q.mahasiswa[q.rear] = nama;
        cout << nama << " berhasil mengambil nomor antrian.\n";
    }
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong!\n";
    } else {
        cout << "Melayani mahasiswa: " << q.mahasiswa[q.front] << endl;
        if (q.front >= q.rear) {
            q.front = q.rear = -1; 
        } else {
            q.front++;
        }
    }
}

void tampilkanAntrian(Queue &q) {
    if (isEmpty(q)) {
        cout << "Kondisi Antrian: [Kosong]\n";
    } else {
        cout << "Kondisi Antrian: ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << "[" << q.mahasiswa[i] << "] ";
        }
        cout << "\nSedang dilayani (Front): " << q.mahasiswa[q.front] << endl;
        cout << "Antrian terakhir (Rear): " << q.mahasiswa[q.rear] << endl;
    }
}

int main() {
    Queue layananAkademik;
    
    enqueue(layananAkademik, "Mahasiswa A");
    enqueue(layananAkademik, "Mahasiswa B");
    enqueue(layananAkademik, "Mahasiswa C");
    cout << "----------------------------\n";
    
    dequeue(layananAkademik); 
    cout << "----------------------------\n";
    
    enqueue(layananAkademik, "Mahasiswa D");
    cout << "----------------------------\n";
    
    tampilkanAntrian(layananAkademik);
    
    return 0;
}
