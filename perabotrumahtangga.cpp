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
    Perabot* baru = new Perabot;
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

void tampilkanPerabot(){
    if(head == nullptr){
        cout << "\nData kosong!\n";
        return;
    }
    cout << "\n=== Daftar Perabot ===\n";
    Perabot* temp = head;
    int i = 1;
    do{
        cout << "[" << i++ << "] ID: " << temp->id << "\n";
        cout << "    Nama: " << temp->nama << ", Kategori: " << temp->kategori << "\n";
        cout << "    Merk: " << temp->merk << ", Harga: Rp" << temp->harga << ", Stok: " << temp->stok << "\n";
        cout << "--------------------------------------------------\n";
        temp = temp->next;
    } while (temp != head);
}

void hapusPerabot(int id) {
    if (head == nullptr) {
        cout << "Data kosong!\n";
        return;
    }

    Perabot* temp = head;
    Perabot* prev = nullptr;

    do {
        if (temp->id == id) {
            if (temp == head) {
                if (head->next == head) {
                    delete head;
                    head = nullptr;
                } else {
                    Perabot* last = head;
                    while (last->next != head) last = last->next;
                    head = head->next;
                    last->next = head;
                    delete temp;
                }
            } else {
                prev->next = temp->next;
                delete temp;
            }
            cout << "Data dengan ID " << id << " berhasil dihapus!\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    cout << "Data dengan ID " << id << " tidak ditemukan!\n";
}

int main () 
{
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
                sisipPerabot(posisi);
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
    } while (pilihan != 0);
    return 0;
}
    
