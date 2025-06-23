#include <iostream>
#include <string>
using namespace std;

struct Perabot {
    int id;
    string nama;
    string kategori;
    string merk;
    double harga;
    int stok;
    Perabot* next;

};

Perabot* head = nullptr;

void tambahPerabot() {
    Perabot* baru = new Perabot;
    cout << "\n=== Tambah Perabot ===\n";
    cout << "ID: "; cin >> baru->id;
    cout << "Nama: "; cin >> baru->nama;
    cout << "Kategori: "; cin >> baru->kategori;
    cout << "Merk: "; cin >> baru->merk;
    cout << "Harga: "; cin >> baru->harga;
    cout << "Stok: "; cin >> baru->stok;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
        head->next = head;
    } else {
        Perabot* temp = head;
        while (temp->next != head ) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->next = head;
    }

    cout << "Data berhasil ditambahkan!\n";
}

void sisipPerabot(int pos) {
    Perabot* baru = new perabot;
    cout << "\n=== Sisipkan Perabot di Posisi " << pos << " ===\n";
    cout << "ID: "; cin >> baru->id;
    cout << "Nama: "; cin >> baru->nama;
    cout << "Kategori: "; cin >> baru->kategori;
    cout << "Merk: "; cin >> baru->merk;
    cout << "Harga: "; cin >> baru->harga;
    cout << "Stok: "; cin >> baru->stok;

    if (head == nullptr || pos <= 1) {
        if (head == nullptr) {
            head= baru;
            head->next = head;
        } else {
            Perabot* temp = head;
            while (temp->next != head) temp = temp->next;
            baru->next = head;
            baru->next = baru;
            head = baru;
        }
    } else {
        Perabot* temp =head;
        for ( int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "Data berhasil disisipkan\n";
}



int main () {
    int pilihan, posisi, idHapus;

    do{
        cout << "\n=== Inventory Perabotan Rumah Tangga (Circular Linked List) ===\n";
        cout << "1. Tambah Perabot\n";
        cout << "2. Sisipkan Perabotan di Posisi\n";
        cout << "3. Tampilkan Semua Perabotan\n";
        cout << "4. Hapus Perabotan berdasarkan ID\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahPerabot();
                break;
            case 2:
                cout << "Masukkan Posisi: ";
                cin >> posisi;
                sisipkanPerabot(posisi);
                break;
            case 3:
                tampilkanPerabot();
                break;
            case 4:
                cout << "Masukkan ID perabot yang ingin dihapus: ";
                cin >> idHapus;
                hapusPerabot(idHapus);
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";    
        }
    }
}