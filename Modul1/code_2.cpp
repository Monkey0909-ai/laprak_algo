#include <iostream>
#include <string>

using namespace std;

struct DataKendaraan {
    string plat_nomor;
    string jenis;
    string nama_pemilik;
    string alamat;
    string kota;
};

int main() {
    DataKendaraan mobil;

    mobil.plat_nomor = "DA 4752 AL";
    mobil.jenis = "PCX";
    mobil.nama_pemilik = "Siti Nurchalisah";
    mobil.alamat = "Jl. Ukhwah Islamiah";
    mobil.kota = "Banjarmasin";

    cout << "a. Plat Nomor Kendaraan : " << mobil.plat_nomor << endl;
    cout << "b. Jenis Kendaraan      : " << mobil.jenis << endl;
    cout << "c. Nama Pemilik         : " << mobil.nama_pemilik << endl;
    cout << "d. Alamat               : " << mobil.alamat << endl;
    cout << "e. Kota                 : " << mobil.kota << endl;

    return 0;
}