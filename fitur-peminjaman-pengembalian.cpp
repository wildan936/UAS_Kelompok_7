#include <iostream>
#include <queue>
#include <string> 
using namespace std;

struct Transaksi {
    string nama;
    string judulBuku;
    string tanggalPinjam;
    string batasKembali;
};


void menupeminjaman(ManajemenKoleksiBuku &perpus, queue<Transaksi> &antrean) {
    int pilihan;

    do {
        cout << "\n=== SISTEM PEMINJAMAN PERPUSTAKAAN ===" << endl;
        cout << "1. Tambah Peminjaman" << endl;
        cout << "2. Proses Pengembalian" << endl;
        cout << "3. Lihat Antrean" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        cin.ignore(); 
        if (pilihan == 1) {
            Transaksi t;

            cout << "Nama Peminjam : ";
            getline(cin, t.nama);

            cout << "Judul Buku : ";
            getline(cin, t.judulBuku);

            cout << "Tanggal Pinjam : ";
            getline(cin, t.tanggalPinjam);

            cout << "Batas Kembali : ";
            getline(cin, t.batasKembali);

            antrean.push(t);

            cout << "Data peminjaman berhasil ditambahkan.\n";
        }

        else if (pilihan == 2) {
            if (!antrean.empty()) {
                cout << "\nBuku yang dikembalikan:" << endl;
                cout << "Nama : " << antrean.front().nama << endl;
                cout << "Judul Buku : " << antrean.front().judulBuku << endl;

                antrean.pop();

                cout << "Pengembalian berhasil diproses.\n";
            } else {
                cout << "Tidak ada antrean peminjaman.\n";
            }
        }

        else if (pilihan == 3) {
            if (antrean.empty()) {
                cout << "Antrean masih kosong.\n";
            } else {
                queue<Transaksi> temp = antrean;
                int no = 1;

                cout << "\n=== DAFTAR ANTREAN ===" << endl;

                while (!temp.empty()) {
                    cout << no++ << ". "
                         << temp.front().nama
                         << " - "
                         << temp.front().judulBuku
                         << endl;

                    temp.pop();
                }
            }
        }

    } while (pilihan != 0);
}