#include <iostream>
#include "Buku.h"

using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan kode buku: "; cin >> data.kodeBuku;
    cout << "masukkan judul buku: "; cin >> data.judul;
    cout << "masukkan tahun terbit: "; cin >> data.thnTerbit;

    if (findElm(L, data.kodeBuku) == Nil) {
        P = alokasi(data);
        insertLast(L, P);
    } else {
        cout << "kode buku sudah terdaftar" << endl;
    }
}

int main() {
    List L;
    CreateList(L);

    inputData(L);
    inputData(L);
    inputData(L);
    inputData(L);

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    string cariKode;
    cout << "\nMasukkan Kode Buku yang dicari: ";
    cin >> cariKode;

    address P = findElm(L, cariKode);
    if (P != Nil) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Data dengan kode buku " << cariKode << " tidak ditemukan." << endl;
    }

    return 0;
}