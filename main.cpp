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

   
    perpus.tambahBuku("978-013-235088-4", "Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin");
    perpus.tambahBuku("978-026-203384-8", "Introduction to Algorithms", "Thomas H. Cormen");
    perpus.tambahBuku("978-013-359414-0", "Computer Networking: A Top-Down Approach", "James Kurose");
    perpus.tambahBuku("978-013-608620-8", "Database Systems: The Complete Book", "Hector Garcia-Molina");
    perpus.tambahBuku("978-111-945633-9", "Operating System Concepts", "Abraham Silberschatz");
    

    do {
        cout << "\n====================================\n";
        cout << "    SISTEM PERPUSTAKAAN MODERN\n";
        cout << "====================================\n";
        cout << "1. Tambah Buku Baru\n";
        cout << "2. Tampilkan Seluruh Koleksi\n";
        cout << "3. Hapus Buku (Rusak/Hilang)\n";
        cout << "4. Cari Buku (Berdasarkan Judul)\n";
        cout << "5. Rekomendasi Buku (Judul/ISBN)\n"; 
        cout << "6. Peminjaman dan Pengembalian\n";   
        cout << "7. Keluar\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu (1-7): ";
        
        
        if (!(cin >> pilihan)) {
            cout << "\n[ERROR] Input harus berupa angka!\n";
            cin.clear(); 
            cin.ignore(1000, '\n');
            continue;
        }

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