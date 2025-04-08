#include <iostream>
#include <string>

#define MAX 100

using namespace std;

struct Antrian {
    string nama[MAX];
    int front, rear;

    Antrian() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string n) {
        if (isFull()) {
            cout << "Antrian penuh!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        nama[rear] = n;
        cout << "Antrian atas nama " << n << " berhasil ditambahkan.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!\n";
            return;
        }
        cout << "Memanggil: " << nama[front] << "\n";
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong.\n";
            return;
        }
        cout << "Daftar Antrian:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << nama[i] << "\n";
        }
    }

    void reset() {
        front = rear = -1;
        cout << "Antrian berhasil direset.\n";
    }
};

int main() {
    Antrian antri;
    int pilih;
    string nama;

    do {
        cout << "\n=== Sistem Antrian ===\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Panggil Antrian\n";
        cout << "3. Lihat Antrian\n";
        cout << "4. Reset Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore(); // membersihkan buffer

        switch (pilih) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                antri.enqueue(nama);
                break;
            case 2:
                antri.dequeue();
                break;
            case 3:
                antri.display();
                break;
            case 4:
                antri.reset();
                break;
            case 5:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilih != 5);

    return 0;
}
