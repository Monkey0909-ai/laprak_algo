#include <iostream>

using namespace std;

struct mhs {
    char nama[20], nim[10], jurusan[5];
    int sks, program;
};

struct mhs bayar[2];

int main() {
    int var, tetap;

    for (int i = 0; i < 2; i++) {
        cout << "\n\n------------------------------\n";
        cout << "Nama mhs            = "; cin >> bayar[i].nama;
        cout << "NIM                 = "; cin >> bayar[i].nim;
        cout << "Jurusan [TI, PTK]   = "; cin >> bayar[i].jurusan;

    input:
        cout << "Program [1=D3, 2=S1] = ";
        cin >> bayar[i].program;

        if (bayar[i].program < 1 || bayar[i].program > 2) {
            cout << "Program tidak sesuai\n";
            goto input;
        }

        cout << "Jumlah sks          = "; cin >> bayar[i].sks;

        if (bayar[i].program == 1) {
            tetap = 500000;
            var = bayar[i].sks * 25000;
        } else if (bayar[i].program == 2) {
            tetap = 750000;
            var = bayar[i].sks * 50000;
        }

        cout << "\n\n------------------------------\n";
        cout << "            Output            ";
        cout << "\n------------------------------\n";
        cout << "Nama mhs      = " << bayar[i].nama;
        cout << "\nNIM           = " << bayar[i].nim;
        cout << "\nJurusan       = " << bayar[i].jurusan;
        cout << "\nProgram       = " << (bayar[i].program == 1 ? "D3" : "S1");
        cout << "\nJumlah sks    = " << bayar[i].sks;
        cout << "\nSPP tetap     = " << tetap;
        cout << "\nSPP variable  = " << var;
        cout << "\n------------------------------" << endl;
    }

    return 0;
}