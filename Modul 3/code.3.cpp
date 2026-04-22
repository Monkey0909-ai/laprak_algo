#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
string dataBaru, dataHapus;

void init();
int isEmpty();

void tambahDepan();
void tambahBelakang();
void hapusDepan();
void hapusBelakang();
void tampilkan();
void reset();
void cariData();
void hapusData();
void sisipkanSebelum();
void sisipkanSetelah();

int main()
{
    init();

    do {
        cout << "Single Linked List Circular (SLLC)\n";
        cout << "====================================\n";
        cout << "1. Tambah Depan\n";
        cout << "2. Tambah Belakang\n";
        cout << "3. Hapus Depan\n";
        cout << "4. Hapus Belakang\n";
        cout << "5. Tampilkan Data\n";
        cout << "6. Hapus Semua Elemen\n";
        cout << "7. Cari Data\n";
        cout << "8. Hapus Data Tertentu\n";
        cout << "9. Sisipkan Sebelum\n";
        cout << "10. Sisipkan Setelah\n";
        cout << "11. Quit\n";
        cout << "Pilihan : ";
        cin >> pil;

        switch (pil) {
        case 1: tambahDepan(); break;
        case 2: tambahBelakang(); break;
        case 3: hapusDepan(); break;
        case 4: hapusBelakang(); break;
        case 5: tampilkan(); break;
        case 6: reset(); break;
        case 7: cariData(); break;
        case 8: hapusData(); break;
        case 9: sisipkanSebelum(); break;
        case 10: sisipkanSetelah(); break;
        default:
            cout << "\nTERIMA KASIH\n";
        }

        cout << "\nTekan ENTER...";
        cin.ignore(1000, '\n');
        cin.get();

        system("cls");

    } while (pil != 11);

    return 0;
}

void init() {
    head = NULL;
    tail = NULL;
}

int isEmpty() {
    return (head == NULL);
}

void tambahDepan() {
    TNode *baru = new TNode;
    cout << "Masukkan data : ";
    cin >> dataBaru;

    baru->data = dataBaru;

    if (isEmpty()) {
        head = tail = baru;
        baru->next = head;
    } else {
        baru->next = head;
        head = baru;
        tail->next = head;
    }

    cout << "Berhasil tambah depan\n";
}

void tambahBelakang() {
    TNode *baru = new TNode;
    cout << "Masukkan data : ";
    cin >> dataBaru;

    baru->data = dataBaru;

    if (isEmpty()) {
        head = tail = baru;
        baru->next = head;
    } else {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }

    cout << "Berhasil tambah belakang\n";
}

void hapusDepan() {
    if (!isEmpty()) {
        TNode *hapus = head;
        dataHapus = hapus->data;

        if (head != tail) {
            head = head->next;
            tail->next = head;
        } else {
            init();
        }

        delete hapus;
        cout << "Hapus depan: " << dataHapus << endl;
    } else {
        cout << "List kosong\n";
    }
}

void hapusBelakang() {
    if (!isEmpty()) {
        TNode *hapus = tail;
        dataHapus = hapus->data;

        if (head != tail) {
            TNode *bantu = head;
            while (bantu->next != tail)
                bantu = bantu->next;

            tail = bantu;
            tail->next = head;
        } else {
            init();
        }

        delete hapus;
        cout << "Hapus belakang: " << dataHapus << endl;
    } else {
        cout << "List kosong\n";
    }
}

void tampilkan() {
    if (!isEmpty()) {
        TNode *bantu = head;
        do {
            cout << bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    } else {
        cout << "List kosong\n";
    }
}

void reset() {
    while (!isEmpty()) {
        hapusDepan();
    }
    cout << "Semua data dihapus\n";
}

void cariData() {
    if (!isEmpty()) {
        string cari;
        cout << "Cari data: ";
        cin >> cari;

        TNode *bantu = head;
        bool ketemu = false;

        do {
            if (bantu->data == cari) {
                ketemu = true;
                break;
            }
            bantu = bantu->next;
        } while (bantu != head);

        if (ketemu) cout << "Data ditemukan\n";
        else cout << "Tidak ditemukan\n";
    } else {
        cout << "List kosong\n";
    }
}

void hapusData() {
    if (!isEmpty()) {
        string cari;
        cout << "Hapus data: ";
        cin >> cari;

        TNode *bantu = head;
        TNode *sebelum = tail;
        bool ditemukan = false;

        int count = 0;
        int jumlah = 0;

        TNode *temp = head;
        do {
            jumlah++;
            temp = temp->next;
        } while (temp != head);

        while (count < jumlah && !isEmpty()) {
            if (bantu->data == cari) {
                ditemukan = true;

                if (bantu == head) {
                    hapusDepan();
                    bantu = head;
                    sebelum = tail;
                } 
                else if (bantu == tail) {
                    hapusBelakang();
                    bantu = head;
                    sebelum = tail;
                } 
                else {
                    sebelum->next = bantu->next;
                    delete bantu;
                    bantu = sebelum->next;
                }
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
            count++;
        }

        if (ditemukan) cout << "Data berhasil dihapus\n";
        else cout << "Data tidak ditemukan\n";
    } else {
        cout << "List kosong\n";
    }
}

void sisipkanSebelum() {
    if (!isEmpty()) {
        string target;
        cout << "Sisip sebelum: ";
        cin >> target;

        TNode *bantu = head;
        TNode *sebelum = tail;

        do {
            if (bantu->data == target) {
                TNode *baru = new TNode;
                cout << "Data baru: ";
                cin >> dataBaru;

                baru->data = dataBaru;
                baru->next = bantu;
                sebelum->next = baru;

                if (bantu == head)
                    head = baru;

                cout << "Berhasil sisip\n";
                return;
            }
            sebelum = bantu;
            bantu = bantu->next;
        } while (bantu != head);

        cout << "Data tidak ditemukan\n";
    } else {
        cout << "List kosong\n";
    }
}

void sisipkanSetelah() {
    if (!isEmpty()) {
        string target;
        cout << "Sisip setelah: ";
        cin >> target;

        TNode *bantu = head;

        do {
            if (bantu->data == target) {
                TNode *baru = new TNode;
                cout << "Data baru: ";
                cin >> dataBaru;

                baru->data = dataBaru;
                baru->next = bantu->next;
                bantu->next = baru;

                if (bantu == tail)
                    tail = baru;

                cout << "Berhasil sisip\n";
                return;
            }
            bantu = bantu->next;
        } while (bantu != head);

        cout << "Data tidak ditemukan\n";
    } else {
        cout << "List kosong\n";
    }
}