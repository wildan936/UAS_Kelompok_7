#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string isbn;
    string judul;
    string penulis;
    Buku* next;
};

class ManajemenKoleksiBuku {
private:
    Buku* head;

public:
    ManajemenKoleksiBuku() {
        head = nullptr;
    }

    // 1. Menambah buku baru (Insert at Tail)
    void tambahBuku(string isbn, string judul, string penulis) {
        Buku* bukuBaru = new Buku();
        bukuBaru->isbn = isbn;
        bukuBaru->judul = judul;
        bukuBaru->penulis = penulis;
        bukuBaru->next = nullptr;

        if (head == nullptr) {
            head = bukuBaru;
        } else {
            Buku* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = bukuBaru;
        }
        cout << "Buku " << judul << "\n";
    }

    void hapusBuku(string isbn) {
        if (head == nullptr) {
            cout << "[GAGAL] Koleksi buku masih kosong, tidak ada yang bisa dihapus.\n";
            return;
        }

        Buku* temp = head;
        Buku* prev = nullptr;

        if (temp != nullptr && temp->isbn == isbn) {
            head = temp->next; 
            delete temp;       
            cout << "[SUKSES] Buku dengan ISBN " << isbn << " berhasil dihapus dari sistem.\n";
            return;
        }

        while (temp != nullptr && temp->isbn != isbn) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "[INFO] Buku dengan ISBN " << isbn << " tidak ditemukan.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "[SUKSES] Buku dengan ISBN " << isbn << " berhasil dihapus dari sistem.\n";
    }

    void tampilkanKoleksi() {
        if (head == nullptr) {
            cout << "\n--- Koleksi Perpustakaan Kosong ---\n";
            return;
        }

        Buku* temp = head;
        cout << "\n=== Daftar Koleksi Buku Perpustakaan ===\n";
        while (temp != nullptr) {
            cout << "ISBN    : " << temp->isbn << "\n"
                << "Judul   : " << temp->judul << "\n"
                << "Penulis : " << temp->penulis << "\n"
                << "----------------------------------------\n";
            temp = temp->next;
        }
    }
};

int main() {
    ManajemenKoleksiBuku perpus;
    int pilihan;
    string inputIsbn, inputJudul, inputPenulis;

    cout << "====================================\n";
    cout << "           KOLEKSI BUKU\n";
    cout << "====================================\n";
    perpus.tambahBuku("978-111", "Struktur Data & Algoritma", "Budi Raharjo");
    perpus.tambahBuku("978-222", "Kalkulus Lanjut", "Koko Martono");
    perpus.tambahBuku("978-333", "Fisika Dasar", "Halliday Resnick");
    perpus.tambahBuku("978-444", "Pengantar Sistem Operasi", "Stallings");
    perpus.tambahBuku("978-555", "Clean Code C++", "Robert C. Martin");
    cout << "------------------------------------\n";

    do {
        cout << "\n====================================\n";
        cout << "    SISTEM PERPUSTAKAAN MODERN\n";
        cout << "====================================\n";
        cout << "1. Tambah Buku Baru\n";
        cout << "2. Tampilkan Seluruh Koleksi\n";
        cout << "3. Hapus Buku (Rusak/Hilang)\n";
        cout << "4. Keluar\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu (1-4): ";
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
                cout << "\nKeluar dari sistem perpustakaan. Sampai jumpa bro!\n";
                break;

            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan pilih 1-4.\n";
        }

    } while (pilihan != 4);

    return 0;
}