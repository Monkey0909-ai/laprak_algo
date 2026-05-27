#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

// ===================== FUNGSI SEQUENTIAL SEARCHING =====================

int randomSeq(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

void sequentialSearching() {
    clrscr();
    int data[100];
    int cari = 20;
    int counter = 0;
    int flag = 0;
    int save;

    randomize();
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = randomSeq(100) + 1;
        printf("%d ", data[i]);
    }
    printf("\nDone.\n");

    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) {
            counter++;
            flag = 1;
            save = i;
        }
    }

    if (flag == 1) {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d", save);
    } else {
        printf("Data tidak ada!\n");
    }

    cout << "\n\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

// ===================== FUNGSI BINARY SEARCHING =====================

void binarySearching() {
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;

    cout << "Masukan jumlah data? ";
    cin >> n;
    int angka[n];

    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] : ";
        cin >> angka[i];
    }

    // Bubble sort untuk mengurutkan data
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                temp = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = temp;
            }
        }
    }

    cout << "\n------------------------------------------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) {
        cout << angka[i] << " ";
    }
    cout << "\n------------------------------------------------------------------------\n";
    cout << "Masukan angka yang dicari: ";
    cin >> key;

    kiri = 0;
    kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah]) {
            ketemu = true;
            break;
        } else if (key < angka[tengah]) {
            kanan = tengah - 1;
        } else {
            kiri = tengah + 1;
        }
    }

    if (ketemu == true) {
        cout << "Angka ditemukan! ";
    } else {
        cout << "Angka tidak ditemukan!";
    }

    cout << "\n\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

// ===================== FUNGSI PENJELASAN PERBEDAAN =====================

void jelaskanPerbedaan() {
    clrscr();
    cout << "========================================================================\n";
    cout << "   PERBEDAAN SEQUENTIAL SEARCHING DAN BINARY SEARCHING\n";
    cout << "========================================================================\n\n";

    cout << "1. SEQUENTIAL SEARCHING (Pencarian Berurutan)\n";
    cout << "   - Cara kerja : Mencari data satu per satu dari awal hingga akhir.\n";
    cout << "   - Data       : Tidak perlu terurut.\n";
    cout << "   - Kompleksitas: O(n) - semakin banyak data, semakin lama.\n\n";
    cout << "   Kelebihan:\n";
    cout << "   + Sederhana dan mudah diimplementasikan.\n";
    cout << "   + Dapat digunakan pada data yang tidak terurut.\n";
    cout << "   + Cocok untuk data berukuran kecil.\n\n";
    cout << "   Kekurangan:\n";
    cout << "   - Lambat untuk data berukuran besar (harus cek semua elemen).\n";
    cout << "   - Tidak efisien jika data yang dicari ada di posisi paling akhir.\n\n";

    cout << "------------------------------------------------------------------------\n\n";

    cout << "2. BINARY SEARCHING (Pencarian Biner)\n";
    cout << "   - Cara kerja : Membagi data menjadi dua bagian, lalu membandingkan\n";
    cout << "                  nilai tengah dengan data yang dicari secara berulang.\n";
    cout << "   - Data       : HARUS sudah terurut (ascending/descending).\n";
    cout << "   - Kompleksitas: O(log n) - jauh lebih cepat dari sequential.\n\n";
    cout << "   Kelebihan:\n";
    cout << "   + Sangat cepat dan efisien untuk data berukuran besar.\n";
    cout << "   + Jumlah perbandingan jauh lebih sedikit dibanding sequential.\n\n";
    cout << "   Kekurangan:\n";
    cout << "   - Data harus diurutkan terlebih dahulu sebelum dicari.\n";
    cout << "   - Implementasi lebih kompleks dibanding sequential searching.\n\n";

    cout << "========================================================================\n";
    cout << "   KESIMPULAN:\n";
    cout << "   Gunakan Sequential jika data kecil/tidak terurut.\n";
    cout << "   Gunakan Binary jika data besar dan sudah/bisa diurutkan.\n";
    cout << "========================================================================\n";

    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

// ===================== MAIN MENU =====================

int main() {
    int pilih;

    do {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                sequentialSearching();
                break;
            case 2:
                binarySearching();
                break;
            case 3:
                jelaskanPerbedaan();
                break;
            case 4:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilih != 4);

    return 0;
}