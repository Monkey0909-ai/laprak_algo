#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>  // [MODIFIKASI 1] tambah header untuk istringstream
#include <vector>   // [MODIFIKASI 1] tambah header untuk vector
using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;
int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();
int countH();   // [MODIFIKASI 4] deklarasi fungsi baru
int countHT();  // [MODIFIKASI 4] deklarasi fungsi baru
void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void hapusTargetH();    // [MODIFIKASI 2] deklarasi fungsi baru
void hapusTargetHT();   // [MODIFIKASI 2] deklarasi fungsi baru
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();

int main()
{
menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"======================================="<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        initH();
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (ke-N dari belakang)"<<endl;  // [MODIFIKASI 4] label diupdate
            cout<<"6. Hapus Berdasarkan Target"<<endl;              // [MODIFIKASI 2] menu baru
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);
            switch(pil) {
            case 1: tambahDepanH();   break;
            case 2: tambahBelakangH(); break;
            case 3: tampilkanH();      break;
            case 4: hapusDepanH();     break;
            case 5: hapusBelakangH();  break;
            case 6: hapusTargetH();    break;  // [MODIFIKASI 2] case baru
            case 7: clearH();          break;
            default:
                system("cls");
                goto menu;
            }
            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");
        } while (pil<8);
    } else if(menu==2){
        initHT();
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"======================================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (ke-N dari belakang)"<<endl;  // [MODIFIKASI 4] label diupdate
            cout<<"6. Hapus Berdasarkan Target"<<endl;              // [MODIFIKASI 2] menu baru
            cout<<"7. Reset"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);
            switch(pil) {
            case 1: tambahDepanHT();   break;
            case 2: tambahBelakangHT(); break;
            case 3: tampilkanHT();      break;
            case 4: hapusDepanHT();     break;
            case 5: hapusBelakangHT();  break;
            case 6: hapusTargetHT();    break;  // [MODIFIKASI 2] case baru
            case 7: clearHT();          break;
            default:
                system("cls");
                goto menu;
            }
            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");
        } while (pil<8);
    } else {
        cout<<"\nTERIMA KASIH"<<endl;
        cout<<"Program was made by Nama (NIM)."<<endl;
    }
}

void initH(){
    head = NULL;
}
void initHT(){
    head = NULL;
    tail = NULL;
}
int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}
int isEmptyHT(){
    if(tail == NULL) return 1;
    else return 0;
}

// [MODIFIKASI 4] fungsi baru untuk menghitung jumlah node
int countH(){
    int count = 0;
    TNode *bantu = head;
    while(bantu != NULL){ count++; bantu = bantu->next; }
    return count;
}
int countHT(){
    return countH();
}

// [MODIFIKASI 1] tambahDepanH - input multi-data dipisah spasi, urutan terjaga
void tambahDepanH(){
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string baris;
    getline(cin, baris);        // [MODIFIKASI 1] getline agar bisa baca banyak data
    istringstream iss(baris);   // [MODIFIKASI 1] tokenisasi input
    vector<string> tokens;      // [MODIFIKASI 1] simpan semua token
    string token;
    while(iss >> token) tokens.push_back(token);
    if(tokens.empty()){ cout<<"Tidak ada data yang dimasukkan."; return; }
    for(int i=(int)tokens.size()-1; i>=0; i--){  // [MODIFIKASI 1] loop terbalik agar urutan di list = urutan input
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyH()==1){ head = baru; }
        else { baru->next = head; head->prev = baru; head = baru; }
    }
    cout<<"Data \""<<baris<<"\" berhasil dimasukkan di bagian depan.";
}

// [MODIFIKASI 1] tambahDepanHT - input multi-data dipisah spasi, urutan terjaga
void tambahDepanHT(){
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string baris;
    getline(cin, baris);        // [MODIFIKASI 1] getline agar bisa baca banyak data
    istringstream iss(baris);   // [MODIFIKASI 1] tokenisasi input
    vector<string> tokens;      // [MODIFIKASI 1] simpan semua token
    string token;
    while(iss >> token) tokens.push_back(token);
    if(tokens.empty()){ cout<<"Tidak ada data yang dimasukkan."; return; }
    for(int i=(int)tokens.size()-1; i>=0; i--){  // [MODIFIKASI 1] loop terbalik agar urutan di list = urutan input
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT()==1){ head = baru; tail = baru; }
        else { baru->next = head; head->prev = baru; head = baru; }
    }
    cout<<"Data \""<<baris<<"\" berhasil dimasukkan di bagian depan.";
}

// [MODIFIKASI 1] tambahBelakangH - input multi-data dipisah spasi, urutan terjaga
void tambahBelakangH(){
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string baris;
    getline(cin, baris);        // [MODIFIKASI 1] getline agar bisa baca banyak data
    istringstream iss(baris);   // [MODIFIKASI 1] tokenisasi input
    vector<string> tokens;      // [MODIFIKASI 1] simpan semua token
    string token;
    while(iss >> token) tokens.push_back(token);
    if(tokens.empty()){ cout<<"Tidak ada data yang dimasukkan."; return; }
    TNode *tail_bantu = head;   // [MODIFIKASI 1] cari posisi tail saat ini
    if(tail_bantu != NULL)
        while(tail_bantu->next != NULL) tail_bantu = tail_bantu->next;
    for(int i=0; i<(int)tokens.size(); i++){  // [MODIFIKASI 1] loop maju, sisipkan di belakang data lama
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyH()==1){ head = baru; tail_bantu = baru; }
        else { tail_bantu->next = baru; baru->prev = tail_bantu; tail_bantu = baru; }
    }
    cout<<"Data \""<<baris<<"\" berhasil dimasukkan di bagian belakang.";
}

// [MODIFIKASI 1] tambahBelakangHT - input multi-data dipisah spasi, urutan terjaga
void tambahBelakangHT(){
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    cin.ignore();
    string baris;
    getline(cin, baris);        // [MODIFIKASI 1] getline agar bisa baca banyak data
    istringstream iss(baris);   // [MODIFIKASI 1] tokenisasi input
    vector<string> tokens;      // [MODIFIKASI 1] simpan semua token
    string token;
    while(iss >> token) tokens.push_back(token);
    if(tokens.empty()){ cout<<"Tidak ada data yang dimasukkan."; return; }
    for(int i=0; i<(int)tokens.size(); i++){  // [MODIFIKASI 1] loop maju, sisipkan di belakang data lama
        TNode *baru = new TNode;
        baru->data = tokens[i];
        baru->next = NULL;
        baru->prev = NULL;
        if(isEmptyHT()==1){ head = baru; tail = baru; }
        else { tail->next = baru; baru->prev = tail; tail = baru; }
    }
    cout<<"Data \""<<baris<<"\" berhasil dimasukkan di bagian belakang.";
}

void tampilkanH(){
    TNode *bantu = head;
    if(isEmptyH()==0){
        cout<<"Isi Linked List : ";
        while(bantu != NULL){
            cout<<bantu->data;
            if(bantu->next != NULL) cout<<" <-> ";
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}
void tampilkanHT(){
    TNode *bantu = head;
    if(isEmptyHT()==0){
        cout<<"Isi Linked List : ";
        while(bantu != NULL){
            cout<<bantu->data;
            if(bantu->next != NULL) cout<<" <-> ";
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusDepanH(){
    TNode *hapus;
    string data;
    if(isEmptyH()==0){
        hapus = head;
        data = hapus->data;
        if(head->next != NULL){ head = head->next; head->prev = NULL; }
        else initH();
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}
void hapusDepanHT(){
    TNode *hapus;
    string data;
    if(isEmptyHT()==0){
        hapus = head;
        data = hapus->data;
        if(head->next != NULL){ head = head->next; head->prev = NULL; }
        else initHT();
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

// [MODIFIKASI 4] hapusBelakangH - hapus node ke-N dari belakang dengan sistem mundur
void hapusBelakangH(){
    if(isEmptyH()==1){ cout<<"Tidak terdapat data pada Linked List"; return; }
    int total = countH();
    int N;
    cout<<"Hapus node ke-N dari belakang (N) : ";
    cin>>N;
    N = N % total;      // [MODIFIKASI 4] sistem mundur jika N > jumlah node
    if(N==0) N = total; // [MODIFIKASI 4] jika hasil mod 0, N = total (kelipatan penuh)
    cout<<"Node ke-"<<N<<" dari belakang yang akan dihapus."<<endl;
    TNode *hapus = head;
    for(int i=0; i<total-N; i++) hapus = hapus->next;  // [MODIFIKASI 4] cari posisi node ke-N dari belakang
    string data = hapus->data;
    if(hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;
    if(hapus->next != NULL) hapus->next->prev = hapus->prev;
    delete hapus;
    cout<<"Data \""<<data<<"\" (node ke-"<<N<<" dari belakang) telah berhasil dihapus.";
}

// [MODIFIKASI 4] hapusBelakangHT - hapus node ke-N dari belakang dengan sistem mundur
void hapusBelakangHT(){
    if(isEmptyHT()==1){ cout<<"Tidak terdapat data pada Linked List"; return; }
    int total = countHT();
    int N;
    cout<<"Hapus node ke-N dari belakang (N) : ";
    cin>>N;
    N = N % total;      // [MODIFIKASI 4] sistem mundur jika N > jumlah node
    if(N==0) N = total; // [MODIFIKASI 4] jika hasil mod 0, N = total (kelipatan penuh)
    cout<<"Node ke-"<<N<<" dari belakang yang akan dihapus."<<endl;
    TNode *hapus = tail;
    for(int i=1; i<N; i++) hapus = hapus->prev;  // [MODIFIKASI 4] mundur dari tail sebanyak N-1 langkah
    string data = hapus->data;
    if(hapus->prev != NULL) hapus->prev->next = hapus->next;
    else head = hapus->next;
    if(hapus->next != NULL) hapus->next->prev = hapus->prev;
    else tail = hapus->prev;    // [MODIFIKASI 4] update tail jika node paling belakang dihapus
    delete hapus;
    cout<<"Data \""<<data<<"\" (node ke-"<<N<<" dari belakang) telah berhasil dihapus.";
}

// [MODIFIKASI 2] fungsi baru - hapus semua node yang datanya sama dengan target
void hapusTargetH(){
    if(isEmptyH()==1){ cout<<"Tidak terdapat data pada Linked List"; return; }
    string target;
    cout<<"Masukkan data yang ingin dihapus : ";
    cin>>target;
    TNode *bantu = head;
    int count = 0;
    while(bantu != NULL){
        TNode *next = bantu->next;  // [MODIFIKASI 2] simpan next sebelum delete agar traversal tidak putus
        if(bantu->data == target){
            if(bantu->prev != NULL) bantu->prev->next = bantu->next;
            else head = bantu->next;
            if(bantu->next != NULL) bantu->next->prev = bantu->prev;
            delete bantu;
            count++;
        }
        bantu = next;
    }
    if(count>0) cout<<"Sebanyak "<<count<<" node dengan data \""<<target<<"\" berhasil dihapus.";
    else cout<<"Data \""<<target<<"\" tidak ditemukan dalam Linked List.";  // [MODIFIKASI 2] pesan jika tidak ditemukan
}

// [MODIFIKASI 2] fungsi baru - hapus semua node yang datanya sama dengan target
void hapusTargetHT(){
    if(isEmptyHT()==1){ cout<<"Tidak terdapat data pada Linked List"; return; }
    string target;
    cout<<"Masukkan data yang ingin dihapus : ";
    cin>>target;
    TNode *bantu = head;
    int count = 0;
    while(bantu != NULL){
        TNode *next = bantu->next;  // [MODIFIKASI 2] simpan next sebelum delete agar traversal tidak putus
        if(bantu->data == target){
            if(bantu->prev != NULL) bantu->prev->next = bantu->next;
            else head = bantu->next;
            if(bantu->next != NULL) bantu->next->prev = bantu->prev;
            else tail = bantu->prev;    // [MODIFIKASI 2] update tail jika node terakhir dihapus
            delete bantu;
            count++;
        }
        bantu = next;
    }
    if(count>0) cout<<"Sebanyak "<<count<<" node dengan data \""<<target<<"\" berhasil dihapus.";
    else cout<<"Data \""<<target<<"\" tidak ditemukan dalam Linked List.";  // [MODIFIKASI 2] pesan jika tidak ditemukan
}

// [MODIFIKASI 3] clearH - hapus bergantian depan-belakang, tampilkan urutan & data
void clearH(){
    if(isEmptyH()==1){ cout<<"Linked List sudah kosong."; return; }
    int urutan = 1;
    bool dari_depan = true;         // [MODIFIKASI 3] flag arah hapus, mulai dari depan
    while(head != NULL){
        TNode *hapus;
        string data;
        if(dari_depan){             // [MODIFIKASI 3] hapus dari depan
            hapus = head;
            data  = hapus->data;
            head  = head->next;
            if(head != NULL) head->prev = NULL;
        } else {                    // [MODIFIKASI 3] hapus dari belakang
            hapus = head;
            while(hapus->next != NULL) hapus = hapus->next;
            data = hapus->data;
            if(hapus->prev != NULL) hapus->prev->next = NULL;
            else head = NULL;
        }
        cout<<"Penghapusan ke-"<<urutan<<" : \""<<data<<"\""<<endl;  // [MODIFIKASI 3] tampilkan urutan & data
        delete hapus;
        urutan++;
        dari_depan = !dari_depan;   // [MODIFIKASI 3] ganti arah setiap iterasi
    }
    initH();
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}

// [MODIFIKASI 3] clearHT - hapus bergantian depan-belakang, tampilkan urutan & data
void clearHT(){
    if(isEmptyHT()==1){ cout<<"Linked List sudah kosong."; return; }
    int urutan = 1;
    bool dari_depan = true;         // [MODIFIKASI 3] flag arah hapus, mulai dari depan
    while(head != NULL){
        TNode *hapus;
        string data;
        if(dari_depan){             // [MODIFIKASI 3] hapus dari depan
            hapus = head;
            data  = hapus->data;
            if(head==tail){ head = NULL; tail = NULL; }
            else { head = head->next; head->prev = NULL; }
        } else {                    // [MODIFIKASI 3] hapus dari belakang
            hapus = tail;
            data  = hapus->data;
            if(head==tail){ head = NULL; tail = NULL; }
            else { tail = tail->prev; tail->next = NULL; }
        }
        cout<<"Penghapusan ke-"<<urutan<<" : \""<<data<<"\""<<endl;  // [MODIFIKASI 3] tampilkan urutan & data
        delete hapus;
        urutan++;
        dari_depan = !dari_depan;   // [MODIFIKASI 3] ganti arah setiap iterasi
    }
    cout<<"Seluruh data pada Linked List telah dibersihkan.";
}
