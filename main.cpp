#include <iostream>
#include <string>
#include <queue> 
#include "data_disimpan_dikelola.cpp"
#include "fitur-pencarian-buku.cpp"
#include "rekomendasi_buku.cpp"
#include "fitur-peminjaman-pengembalian.cpp"

using namespace std;

int main() {
    ManajemenKoleksiBuku perpus;
    int pilihan;
    string inputIsbn, inputJudul, inputPenulis;

    
    queue<Transaksi> daftarAntrean; 

    do {
        cout << "\n====================================\n";
        cout << "    SISTEM PERPUSTAKAAN MODERN\n";
        cout << "====================================\n";
        cout << "1. Tambah Buku Baru\n";
        cout << "2. Tampilkan Seluruh Koleksi\n";
        cout << "3. Hapus Buku (Rusak/Hilang)\n";
        cout << "4. Cari Buku (berdasarkan Judul)\n";
        cout << "5. Rekomendasi Buku (judl,ISBN)\n";
        cout << "6. peminjaman-pengembalian \n";
        cout << "7. Keluar\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu (1-7): ";
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
                menuRekomendasiBuku(perpus);
                break;

            case 6:
                
                menupeminjaman(perpus, daftarAntrean); 
                break;
            
            case 7:
                cout << "\nKeluar dari sistem perpustakaan. Sampai jumpa bro!\n";
                break; 

            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan pilih 1-7.\n";
                break;
        }

    } while (pilihan != 7); 

    return 0;
}