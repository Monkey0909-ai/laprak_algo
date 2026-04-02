#include<iostream>
#include<conio.h>
#include<stdlib.h>
#define n 10
using namespace std;

void INSERT();
void DELETE();
void CETAKLAYAR();
void Inisialisasi();

int PIL, F, R;
char PILIHAN[2], HURUF; 
char Q[n];

int main()
{
    Inisialisasi();
    do
    {
        cout<<"QUEUE (ANTREAN)"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. INSERT (Tambah)"<<endl;
        cout<<"2. DELETE (Hapus)"<<endl;
        cout<<"3. CETAK QUEUE"<<endl;
        cout<<"4. QUIT"<<endl;
        cout<<"PILIHAN : "; cin>>PILIHAN;
        PIL=atoi(PILIHAN);

        switch (PIL)
        {
        case 1:
            INSERT();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR();
            break;
        case 4:
            cout<<"TERIMA KASIH"<<endl;
            break;
        default:
            cout<<"PILIHAN TIDAK ADA"<<endl;
            break;
        }
        if(PIL != 4) {
            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");
        }
    }
    while (PIL < 4);
    return 0;
}


void Inisialisasi() {
    F = -1;
    R = -1;
}

void INSERT() {
    if (R == n - 1) {
        cout << "Queue Penuh!" << endl;
    } else {
        cout << "Masukkan Huruf: "; cin >> HURUF;
        if (F == -1) F = 0;
        R++;
        Q[R] = HURUF;
        cout << "Huruf " << HURUF << " berhasil dimasukkan." << endl;
    }
}

void DELETE() {
    if (F == -1 || F > R) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Huruf " << Q[F] << " berhasil dihapus." << endl;
        F++;
        if (F > R) {
            F = -1;
            R = -1;
        }
    }
}

void CETAKLAYAR() {
    if (F == -1) {
        cout << "Queue Kosong!" << endl;
    } else {
        cout << "Isi Queue: ";
        for (int i = F; i <= R; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
}