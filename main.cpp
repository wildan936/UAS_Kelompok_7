#include <iostream>
#include <string>
#include "data_disimpan_dikelola.cpp"
#include "fitur-pencarian-buku.cpp"

using namespace std;

int main() {
    ManajemenKoleksiBuku perpus;
    int pilihan;
    string inputIsbn, inputJudul, inputPenulis;

    
    

    do {
        cout << "\n====================================\n";
        cout << "    SISTEM PERPUSTAKAAN MODERN\n";
        cout << "====================================\n";
        cout << "1. Tambah Buku Baru\n";
        cout << "2. Tampilkan Seluruh Koleksi\n";
        cout << "3. Hapus Buku (Rusak/Hilang)\n";
        cout << "4. Cari Buku (berdasarkan Judul)\n";
        cout << "5. Keluar\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "\n--- TAMBAH BUKU BARU ---\n";
                cout << "Masukkan ISBN    : ";
                getline(cin, inputIsbn);
                cout << "Masukkan Judul   : ";
                getline(cin, inputJudul);
                cout << "Masukkan Penulis : ";
                getline(cin, inputPenulis);
                perpus.tambahBuku(inputIsbn, inputJudul, inputPenulis);
                break;

            case 2:
                perpus.tampilkanKoleksi();
                break;

            case 3:
                cout << "\n--- HAPUS BUKU ---\n";
                cout << "Masukkan ISBN buku yang dihapus: ";
                getline(cin, inputIsbn);
                perpus.hapusBuku(inputIsbn);
                break;

            case 4:
                cariBukuMenu(perpus);
                break;

            case 5:
                cout << "\nKeluar dari sistem perpustakaan. Sampai jumpa bro!\n";
                break;

            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan pilih 1-5.\n";
        }

    } while (pilihan != 5);

    return 0;
}