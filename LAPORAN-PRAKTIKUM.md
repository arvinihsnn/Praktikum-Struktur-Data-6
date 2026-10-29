# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Arvin Ihsan Fatih - 109082500050</p>

## Dasar Teori
Doubly Linked List (DLL) merupakan struktur data linier yang terdiri dari node-node yang saling berhubungan, di mana setiap node mempunyai dua pointer yang menunjuk ke node sebelumnya (prev) dan node berikutnya (next). Berbeda dengan Single Linked List (SLL) yang hanya memiliki satu pointer yang menunjuk ke node berikutnya, keunggulan DLL terletak pada kemudahan dalam melakukan operasi penyisipan dan penghapusan data karena memungkinkan navigasi dua arah dalam daftar[1].

### A. Karakteristik dan Struktur Doubly Linked List<br/>
Struktur data Doubly Linked List terdiri dari node-node yang terhubung secara berpasangan dan dikelola menggunakan pointer utama untuk menunjukkan batas awal dan akhir list.
#### 1. First dan Last Pointer.
#### 2. Pointer Next dan Prev pada Node.
#### 3. Keunggulan Navigasi Dua Arah[1].

### B. Operasi Manipulasi Data pada Doubly Linked List<br/>
Operasi dasar pada DLL mencakup penyisipan (insertion) dan penghapusan (deletion) yang dapat dilakukan secara efisien di berbagai posisi.
#### 1. Algoritma Penyisipan (Insertion).
#### 2. Algoritma Penghapusan (Deletion).
#### 3. Kompleksitas Waktu Operasi[1].

## Guided 

### 1. Doublylist.h

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <string>

#define Nil NULL

// Latihan 1
struct infotype {
    std::string nopol; 
    std::string warna; 
    int thnBuat;      
};
typedef struct elmlist *address;
struct elmlist {
    infotype info;  
    address next;   
    address prev;   
};
struct List {
    address First; 
    address Last;  
};


// Latihan 1
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

// Latihan 2

address findElm(List L, std::string nopol);

// Latihan 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string nopol, bool &status);

#endif
```
File header Doublylist.h berfungsi sebagai pusat deklarasi struktur data dan prototipe fungsi untuk Doubly Linked List yang menerapkan studi kasus inventaris kendaraan. Di dalam file ini didefinisikan tipe bentukan infotype yang menampung atribut data kendaraan berupa nomor polisi (nopol), warna, dan tahun pembuatan (thnBuat). Selain itu, terdapat deklarasi struktur elmlist yang dilengkapi dengan dua pointer penunjuk arah yaitu next (menuju elemen sesudahnya) dan prev (menuju elemen sebelumnya), serta struktur List yang memiliki pointer penunjuk batas awal (First) dan batas akhir (Last). Berbagai prototipe fungsi dan prosedur juga dideklarasikan di sini, mulai dari inisialisasi list, manajemen memori (alokasi dan dealokasi), penambahan data (insertLast), pencarian elemen berdasarkan nomor polisi (findElm), hingga berbagai variasi prosedur penghapusan node (deleteFirst, deleteLast, deleteAfter, dan deleteElm).

### 2. Doublylist.cpp

```C++
#include "Doublylist.h"

// Latihan 1
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; 
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void printInfo(List L) {
    address P = L.Last;
    if (P == Nil) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    while (P != Nil) {
        std::cout << "no polisi : " << P->info.nopol << std::endl;   
        std::cout << "warna     : " << P->info.warna << std::endl;   
        std::cout << "tahun     : " << P->info.thnBuat << std::endl; 
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) { 
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;         
        (L.Last)->next = P;     
        L.Last = P;               
    }
}

// Latihan 2
address findElm(List L, std::string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Latihan 3
void deleteFirst(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.First; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;     
        (L.First)->prev = Nil; 
        P->next = Nil;         
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) return;

    P = L.Last; 
    if (L.First == L.Last) { 
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;      
        (L.Last)->next = Nil; 
        P->prev = Nil;         
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) return;

    P = Prec->next;
    if (P == L.Last) {
        deleteLast(L, P);
    } else {
        Prec->next = P->next;     
        (P->next)->prev = Prec; 
        P->next = Nil;            
        P->prev = Nil;           
    }
}

void deleteElm(List &L, std::string nopol, bool &status) {
    address P = findElm(L, nopol);
    status = false;

    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P); 
        status = true;
    }
}
```
File implementasi Doublylist.cpp berisi realisasi kode lengkap dari seluruh fungsi dan prosedur yang telah dideklarasikan dalam Doublylist.h. Di dalamnya mencakup fungsi dasar pembuatan list kosong (CreateList), alokasi dan dealokasi memori dinamis (alokasi dan dealokasi), prosedur penambahan elemen di akhir list (insertLast) dengan memperbarui penunjuk next dan prev, serta prosedur pencarian elemen berdasarkan nomor polisi (findElm). Selain itu, file ini juga memuat sekumpulan prosedur penghapusan node yang fleksibel, mulai dari penghapusan elemen pertama (deleteFirst), elemen terakhir (deleteLast), penghapusan setelah node tertentu (deleteAfter), hingga pencarian dan penghapusan elemen spesifik berdasarkan nomor polisi menggunakan deleteElm. Proses pencetakan informasi (printInfo) dilakukan secara mundur dari pointer last menuju first untuk menyesuaikan dengan format keluaran data kendaraan.

### 3. main.cpp

```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void inputData(List &L) {
    infotype data;
    address P;

    cout << "masukkan nomor polisi: "; cin >> data.nopol;
    cout << "masukkan warna kendaraan: "; cin >> data.warna;
    cout << "masukkan tahun kendaraan: "; cin >> data.thnBuat;
    if (findElm(L, data.nopol) == Nil) {
        P = alokasi(data); 
        insertLast(L, P);  
    } else {
        cout << "nomor polisi sudah terdaftar" << endl; 
    }
}

int main() {
    List L;
    CreateList(L); 
    address P;

    // Latihan 1
    inputData(L); 
    inputData(L); 
    inputData(L); 
    inputData(L); 

    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    // Latihan 2
    string nopolCari;
    cout << "\nMasukkan Nomor Polisi yang dicari : "; 
    cin >> nopolCari; 
    
    P = findElm(L, nopolCari); 
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol << endl; 
        cout << "Warna        : " << P->info.warna << endl; 
        cout << "Tahun        : " << P->info.thnBuat << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolCari << " tidak ditemukan." << endl;
    }

    // Latihan 3
    string nopolHapus;
    bool hapusBerhasil;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> nopolHapus;

    deleteElm(L, nopolHapus, hapusBerhasil); 

    if (hapusBerhasil) {
        cout << "Data dengan nomor polisi " << nopolHapus << " berhasil dihapus." << endl; 
    } else {
        cout << "Data dengan nomor polisi " << nopolHapus << " tidak ditemukan." << endl;
    }
    cout << "\nDATA LIST 1" << endl; 
    printInfo(L); 

    return 0;
}
```
File program utama main.cpp bertindak sebagai pengendali (driver) untuk menguji seluruh fungsi dan prosedur ADT Doubly Linked List yang telah dibuat. Program menginisialisasi list melalui fungsi CreateList, kemudian menyediakan fungsi bantu inputData yang dilengkapi mekanisme validasi menggunakan findElm untuk mencegah duplikasi nomor polisi saat pengguna memasukkan data kendaraan secara berurutan. Setelah menampilkan keseluruhan isi list, program mengeksekusi fitur pencarian (searching) berdasarkan nomor polisi masukan pengguna untuk menampilkan detail kendaraan secara spesifik. Pada bagian akhir, program menguji prosedur penghapusan elemen (deletion) berdasarkan nomor polisi tertentu melalui fungsi deleteElm serta menampilkan kembali status akhir data list yang tersisa.

## Unguided 

### 1. Buatlah ADT Doubly Linked List di dalam file "Buku.h". Buatlah implementasi ADT Doubly Linked List pada file “Buku.cpp" dan cobalah hasil implementasi ADT tersebut pada file "main.cpp". Pastikan sistem melakukan pengecekan duplikasi kodeBuku sebelum memasukkan data baru ke dalam list.

### Buku.h
```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>

#define Nil NULL

struct buku {
    std::string kodeBuku;
    std::string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, std::string kodeBuku);

#endif
```

### Buku.cpp
```C++
#include "Buku.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        std::cout << "kode buku : " << P->info.kodeBuku << std::endl;
        std::cout << "judul     : " << P->info.judul << std::endl;
        std::cout << "tahun     : " << P->info.thnTerbit << std::endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, std::string kodeBuku) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.kodeBuku == kodeBuku) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```

### main.cpp
```C++
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

    return 0;
}
```

### Output Unguided 1 :
![Screenshot Output Unguided 1_1](https://github.com/arvinihsnn/Praktikum-Struktur-Data-6/blob/main/Output-Unguided/Output-Unguided-1.png)

Program di atas menerapkan struktur Doubly Linked List dengan pointer First dan Last serta pointer next dan prev pada setiap node. Sebelum data baru dimasukkan ke bagian akhir list melalui prosedur insertLast, fungsi findElm mengecek apakah kodeBuku sudah pernah terdaftar untuk mencegah duplikasi. Pencetakan data dilakukan secara mundur dari pointer Last agar sesuai dengan format keluaran modul.

### 2. Carilah elemen dengan kode buku B001 dengan membuat fungsi baru.

### Buku.h
```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>

#define Nil NULL

struct buku {
    std::string kodeBuku;
    std::string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, std::string kodeBuku);

#endif
```

### Buku.cpp
```C++
#include "Buku.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        std::cout << "kode buku     : " << P->info.kodeBuku << std::endl;
        std::cout << "judul         : " << P->info.judul << std::endl;
        std::cout << "tahun terbit  : " << P->info.thnTerbit << std::endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, std::string kodeBuku) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.kodeBuku == kodeBuku) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```

### main.cpp
```C++
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
```

### Output Unguided 2 :
![Screenshot Output Unguided 2_1](https://github.com/arvinihsnn/Praktikum-Struktur-Data-6/blob/main/Output-Unguided/Output-Unguided-2.png)

Fungsi findElm melakukan penelusuran (traversal) secara linier dari node pertama (First) hingga akhir list untuk mencocokkan kodeBuku yang diinputkan pengguna. Jika data ditemukan, fungsi mengembalikan alamat node (address) sehingga atribut lengkap buku seperti judul dan tahun terbit dapat langsung ditampilkan ke layar.

### 3. Hapus elemen dengan kode buku B003 dengan membuat prosedur delete.

### Buku.h
```C++
#ifndef BUKU_H
#define BUKU_H

#include <iostream>
#include <string>

#define Nil NULL

struct buku {
    std::string kodeBuku;
    std::string judul;
    int thnTerbit;
};

typedef buku infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, std::string kodeBuku);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteElm(List &L, std::string kodeBuku);

#endif
```

### Buku.cpp
```C++
#include "Buku.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        std::cout << "kode buku     : " << P->info.kodeBuku << std::endl;
        std::cout << "judul         : " << P->info.judul << std::endl;
        std::cout << "tahun terbit  : " << P->info.thnTerbit << std::endl;
        P = P->prev;
    }
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

address findElm(List L, std::string kodeBuku) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.kodeBuku == kodeBuku) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First == L.Last) {
        P = L.First;
        L.First = Nil;
        L.Last = Nil;
    } else {
        P = L.First;
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First == L.Last) {
        P = L.Last;
        L.First = Nil;
        L.Last = Nil;
    } else {
        P = L.Last;
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        if (P == L.Last) {
            deleteLast(L, P);
        } else {
            Prec->next = P->next;
            P->next->prev = Prec;
            P->next = Nil;
            P->prev = Nil;
        }
    }
}

void deleteElm(List &L, std::string kodeBuku) {
    address P = findElm(L, kodeBuku);
    if (P != Nil) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(L, Prec, P);
        }
        dealokasi(P);
        std::cout << "Data dengan kode buku " << kodeBuku << " berhasil dihapus." << std::endl;
    } else {
        std::cout << "Data dengan kode buku " << kodeBuku << " tidak ditemukan." << std::endl;
    }
}
```

### main.cpp
```C++
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

    string hapusKode;
    cout << "\nMasukkan Kode Buku yang akan dihapus: ";
    cin >> hapusKode;

    deleteElm(L, hapusKode);

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    return 0;
}
```

### Output Unguided 3 :

![Screenshot Output Unguided 3_1](https://github.com/arvinihsnn/Praktikum-Struktur-Data-6/blob/main/Output-Unguided/Output-Unguided-3.png)

Prosedur deleteFirst, deleteLast, dan deleteAfter digunakan untuk menangani penghapusan node di berbagai posisi secara fleksibel (di awal, di akhir, atau setelah node tertentu) pada Doubly Linked List. Prosedur utama deleteElm memanfaatkan fungsi pencarian (findElm) untuk mendeteksi posisi node B003, lalu mengarahkan proses penghapusan ke prosedur yang sesuai dan melakukan dealokasi memori.

## Kesimpulan
Kesimpulan dari praktikum Modul 6 ini adalah untuk memahami dan mengimplementasikan struktur data Doubly Linked List yang dilengkapi dengan dua pointer utama (First dan Last) serta pointer penghubung ganda (next dan prev) pada setiap nodenya. Penerapan operasi dasar seperti alokasi memori, penambahan data di akhir (insertLast), pencarian elemen (findElm), hingga variasi penghapusan data (deleteFirst, deleteLast, dan deleteAfter).

## Referensi
[1] Wijoyo, Agung., Farhan, Ahmad., Prayudi, Lalu Akbar., Fiqih, Muhamad., Santoso, Rendi Dwi., Putra, Ricky Tri Setiawan., Arifin, Teguh. (2024). "Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion". JRIIN: Jurnal Riset Informatika dan Inovasi, Vol. 1, No. 12, hal. 1329-1331. Diakses pada 29 Oktober 2026 melalui https://jurnalmahasiswa.com/index.php/jriin/article/download/1282/762.