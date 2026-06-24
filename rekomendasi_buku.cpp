#include <iostream>
#include <string>
#include <algorithm>
#include "data_disimpan_dikelola.cpp"

using namespace std;

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void menuRekomendasiBuku(ManajemenKoleksiBuku& perpus) {
    string kataKunci;

    cout << "\n--- REKOMENDASI BUKU UNTUKMU ---\n";
    cout << "Masukkan judul atau penulis yang kamu suka\n";
    cout << "(Contoh: Judul,Penulis): ";
    getline(cin, kataKunci);

    cout << "\n[REKOMENDASI] Berdasarkan minatmu pada \""
         << kataKunci << "\":\n";
    cout << "---------------------------------------------------------\n";

    bool ditemukan = perpus.rekomendasiBerdasarkanKataKunci(kataKunci);

    if (!ditemukan) {
        cout << "Maaf, tidak ditemukan buku yang sesuai dengan kata kunci tersebut.\n";
    }

    cout << "---------------------------------------------------------\n";
}