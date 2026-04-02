#include <iostream>
using namespace std;

// Inisialisasi variabel dan struct
const int max_limit = 10;

struct {
    int atas = -1;
    int data[max_limit];
} Tumpuk;

int kosong() {
    if (Tumpuk.atas == -1) return 1;
    else return 0;
}

int penuh() {
    if (Tumpuk.atas == max_limit - 1) return 1;
    else return 0;
}

void input(int data) {
    if (kosong() == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack ";
    } 
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack ";
    } 
    else {
        cout << "Tumpukan Penuh";
    }
}

void hapus() {
    if (kosong() == 0) {
        cout << "Data Teratas Sudah Terambil: " << Tumpuk.data[Tumpuk.atas];
        Tumpuk.atas--;
    } 
    else {
        cout << "Data Kosong";
    }
}

void tampil() {
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
    } 
    else {
        cout << "Tumpukan Kosong";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

int main() {
    input(10);
    input(20);
    input(30);
    
    cout << "\n\nIsi Stack:";
    tampil();
    
    cout << "\n\nHapus data:";
    hapus();
    
    cout << "\n\nIsi akhir:";
    tampil();
    
    return 0;
}