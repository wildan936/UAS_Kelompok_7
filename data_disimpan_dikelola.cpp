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

    void tambahBuku(string isbn, string judul, string penulis) {
        Buku* bukuBaru = new Buku();
        bukuBaru->isbn = isbn;
        bukuBaru->judul = judul;
        bukuBaru->penulis = penulis;
        bukuBaru->next = nullptr;
\

        if (head == nullptr) {
            head = bukuBaru;
        } else {
            Buku* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = bukuBaru;
        }
        cout << "[SUKSES] Buku '" << judul << "' berhasil ditambahkan ke koleksi.\n";
    }

    void hapusBuku(string isbn) {
        if (head == nullptr) {
            cout << "[GAGAL] Koleksi buku masih kosong.\n";
            return;
        }

        Buku* temp = head;
        Buku* prev = nullptr;

        if (temp != nullptr && temp->isbn == isbn) {
            head = temp->next; 
            delete temp;       
            cout << "[SUKSES] Buku dengan ISBN " << isbn << " berhasil dihapus.\n";
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
        cout << "[SUKSES] Buku dengan ISBN " << isbn << " berhasil dihapus.\n";
    }

    void perbaruiBuku(string isbn, string judulBaru, string penulisBaru) {
        Buku* temp = head;

        while (temp != nullptr) {
            if (temp->isbn == isbn) {
                temp->judul = judulBaru;
                temp->penulis = penulisBaru;
                cout << "[SUKSES] Data buku dengan ISBN " << isbn << " berhasil diperbarui.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "[INFO] Buku dengan ISBN " << isbn << " tidak ditemukan untuk diperbarui.\n";
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
                 << "-------------------------------------------------\n";
            temp = temp->next;
        }
        cout << "========================================\n\n";
    }
};

int main() {
    ManajemenKoleksiBuku perpus;

    cout << "--- SIMULASI MANAJEMEN KOLEKSI BUKU ---\n\n";

    perpus.tambahBuku("978-623-01", "Struktur Data C++", "Budi Raharjo");
    perpus.tambahBuku("978-623-02", "Algoritma Pemrograman", "Sukamto");
    perpus.tambahBuku("978-623-03", "Clean Code", "Robert C. Martin");
    
    perpus.tampilkanKoleksi();

    cout << "Melakukan pembaruan data buku...\n";
    perpus.perbaruiBuku("978-623-02", "Algoritma Pemrograman (Revisi)", "Sukamto & Rosa");
    perpus.tampilkanKoleksi();

    cout << "Menghapus buku yang rusak...\n";
    perpus.hapusBuku("978-623-01");
    perpus.tampilkanKoleksi();

    return 0;
}