#pragma once
#include <iostream>
#include <string>
#include "data_disimpan_dikelola.cpp"


void cariBukuMenu(ManajemenKoleksiBuku &perpus) {
    string judulCari;

    cout << "\n=== PENCARIAN BUKU ===\n";
    cout << "Masukkan Judul Buku : ";
    getline(cin, judulCari);

    perpus.cariBuku(judulCari);
}