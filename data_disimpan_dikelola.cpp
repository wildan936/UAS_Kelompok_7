#pragma once
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

        if (head == nullptr) {
            head = bukuBaru;
        } else {
            Buku* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = bukuBaru;
        }
        cout << "[SUKSES] Berhasil menambahkan buku: " << judul << "\n";
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

    
    void cariBuku(string judul) {
        Buku* temp = head;
        while (temp != nullptr) {
            if (temp->judul == judul) {
                cout << "\n=== Buku Ditemukan ===\n";
                cout << "ISBN    : " << temp->isbn << "\n";
                cout << "Judul   : " << temp->judul << "\n";
                cout << "Penulis : " << temp->penulis << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "\n[INFO] Buku dengan judul \"" << judul << "\" tidak ditemukan.\n";
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

   
    bool rekomendasiBerdasarkanKataKunci(string kataKunci) {
        if (head == nullptr) {
            return false;
        }

        Buku* temp = head;
        bool ditemukan = false;

        while (temp != nullptr) {
            
            if (temp->judul.find(kataKunci) != string::npos || temp->penulis.find(kataKunci) != string::npos) {
                cout << "ISBN    : " << temp->isbn << "\n";
                cout << "Judul   : " << temp->judul << "\n";
                cout << "Penulis : " << temp->penulis << "\n";
                cout << "----------------------------------------\n";
                ditemukan = true;
            }
            temp = temp->next;
        }

        return ditemukan;
    }
};