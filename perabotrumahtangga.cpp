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