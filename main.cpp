#include <iostream>
#include <string>

using namespace std;
int isi;

// Deklarasi struktur untuk data member
struct Member {
    string nama;
    string ktp;
    string nik;
    string tanggal;
    string gender;
    int saldo;
    Member* next;
};

// Pointer kepala untuk daftar member
Member* head = nullptr;

// Deklarasi fungsi-fungsi
void pendaftaran();
void caridata();
void tampilkan();
void edit(string nama);
void hapus(string nama);
void isitarik();
void bersih();
void header();
void menu();

// Konstanta maksimum jumlah member
const int MAX_MEMBERS = 100;
Member members[MAX_MEMBERS];
int numMembers = 0;

// Fungsi utama
int main() {
    do {
        bersih();
        header();
        menu();
    } while (true);
}

// Fungsi untuk membersihkan layar
void bersih() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk menampilkan header
void header() {
    cout << "       \t    MANAJEMEN KEUANGAN ATM & TRANSAKSI\n\t\t    - RANDIKA SYARIAH -\n";
    cout << "==============================================================\n";
}

// Fungsi untuk menampilkan menu
void menu() {
    int pilih;
    bersih();
    header();
    cout << "||                      MENU UTAMA                          ||\n";
    cout << "==============================================================\n";
    cout << "[1] Daftar Member\n";
    cout << "[2] Cari Data Member\n";
    cout << "[3] Isi Saldo / Tarik Tunai\n";
    cout << "[4] Tampilkan Seluruh Data Member\n";
    cout << "[5] Keluar Program\n";

    cout << "Pilih Menu (1-6): ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            bersih();
            pendaftaran();
            break;
        case 2:
            bersih();
            caridata();
            break;
        case 3:
            bersih();
            isitarik();
            break;
        case 4:
            bersih();
            tampilkan();
            break;
        case 5:
            exit(0);
    }
}

// Fungsi untuk melakukan pendaftaran member baru
void pendaftaran() {
    bersih();
    header();

    Member* baru = new Member;
    baru->next = nullptr;

    cout << "||                 PENDAFTARAN MEMBERSHIP                   ||\n";
    cout << "==============================================================\n";
    cout << "Masukan data pribadi anda !                                 ||\n";
    cout << "--------------------------------------------------------------\n";
    cout << "> Nama\t\t\t\t: ";
    cin.ignore();
    getline(cin, baru->nama);

    // Periksa apakah nama sudah terdaftar sebelumnya
    for (int i = 0; i < numMembers; ++i) {
        if (members[i].nama == baru->nama) {
            cout << "Member dengan nama tersebut sudah terdaftar." << endl;
            delete baru;
            cout << "Tekan ENTER untuk kembali ke menu ..." << endl;
            cin.ignore();
            menu();
            return;
        }
    }

    cout << "> Nomor Ktp\t\t\t: ";
    cin >> baru->ktp;

    cout << "> Nomor NIK\t\t\t: ";
    cin >> baru->nik;

    cout << "> Tempat,Tanggal Lahir\t\t: ";
    cin >> baru->tanggal;

    cout << "> Jenis Kelamin\t\t\t: ";
    cin >> baru->gender;

    cout << "> Masukan Jumlah Saldo Awal\t: ";
    cin >> baru->saldo;
    cout << "--------------------------------------------------------------\n";

    members[numMembers++] = *baru;

    cout << "\nData anda telah tersimpan, tekan ENTER untuk kembali ke menu..." << endl;
    cin.ignore();
    cin.get();
    menu();
}

// Fungsi untuk mencari data member
void caridata() {
    int pilihan;
    string konfirmasi;
    bersih();
    header();
    cout << "||                    CARI DATA MEMBER                      ||\n";
    cout << "==============================================================\n";
    string nama;
    cout << "Masukkan nama member yang ingin dicari: ";
    cin.ignore();
    getline(cin, nama);

    bool ketemu = false;

    for (int i = 0; i < numMembers; ++i) {
        if (members[i].nama == nama) {
            cout << "Member berhasil ditemukan!" << endl;
            cout << "--------------------------------------------------------------\n";
            cout << "> Nama\t\t\t: " << members[i].nama << endl;
            cout << "> Nomor Ktp\t\t: " << members[i].ktp << endl;
            cout << "> Nomor NIK\t\t: " << members[i].nik << endl;
            cout << "> Tempat,tanggal Lahir\t: " << members[i].tanggal << endl;
            cout << "> Jenis Kelamin\t\t: " << members[i].gender << endl;
            cout << "> Jumlah Saldo\t\t: " << members[i].saldo << endl;
            cout << "--------------------------------------------------------------\n";
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "> Member dengan nama '" << nama << "' tidak berhasil ditemukan." << endl;
    }

    cout << "\nPilihan: \n";
    cout << "1. Cari data lagi\n";
    cout << "2. Isi Saldo / Tarik Tunai\n";
    cout << "3. Edit Data Member\n";
    cout << "4. Hapus Data Member\n";
    cout << "5. Kembali ke menu\n";
    cout << "Pilih menu (1-5): ";
    cin >> pilihan;

    if (pilihan == 1) {
        bersih();
        caridata();
    } else if (pilihan == 2) {
        bersih();
        isitarik();
    } else if (pilihan == 3) {
        bersih();
        edit(nama);
    } else if (pilihan == 4) {
        cout << "Apakah anda yakin ingin menghapus data? (Y/N) ";
        cin >> konfirmasi;

        if (konfirmasi == "Y" || konfirmasi == "y") {
            hapus(nama);
        } else
            cout << "Tekan ENTER untuk kembali ke menu" << endl;
        cin.ignore();
        cin.get();
        bersih();
        return menu();
    } else {
        cout << "Pilihan tidak valid. Kembali ke Menu Utama." << endl;
        bersih();
        menu();
    }
}

// Fungsi untuk mengedit data member
void edit(string nama) {
    bersih();
    header();
    cout << "||                    EDIT DATA MEMBER                      ||\n";
    cout << "==============================================================\n";

    bool ketemu = false;

    for (int i = 0; i < numMembers; ++i) {
        if (members[i].nama == nama) {
            cout << "Masukkan data baru untuk '" << nama << "'                            ||\n";
            cin.ignore();
            cout << "--------------------------------------------------------------\n";
            cout << "> Nama\t\t\t: ";
            getline(cin, members[i].nama);
            cout << "> Nomor Ktp\t\t: ";
            cin >> members[i].ktp;
            cout << "> Nomor NIK\t\t: ";
            cin >> members[i].nik;
            cout << "> Tempat, Tanggal Lahir\t: ";
            cin >> members[i].tanggal;
            cout << "> Jenis Kelamin\t\t: ";
            cin >> members[i].gender;
            cout << "> Jumlah saldo\t\t: " << members[i].saldo << endl;
            cout << "--------------------------------------------------------------\n";
            cout << "\nData member telah berhasil diubah, tekan ENTER untuk kembali ke menu..." << endl;
            cin.ignore();
            cin.get();
            ketemu = true;
            break;
        }
    }

    if (!ketemu) {
        cout << "Member dengan nama '" << nama << "' tidak berhasil ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan seluruh data member
void tampilkan() {
    bersih();
    header();
    cout << "||                  TAMPILKAN DATA MEMBER                   ||\n";
    cout << "==============================================================\n";
    for (int i = 0; i < numMembers; ++i) {
        cout << "--------------------------------------------------------------\n";
        cout << "> Nama\t\t\t\t: " << members[i].nama << endl;
        cout << "> Nomor Ktp\t\t\t: " << members[i].ktp << endl;
        cout << "> Nomor NIK\t\t\t: " << members[i].nik << endl;
        cout << "> Tanggal Lahir\t\t\t: " << members[i].tanggal << endl;
        cout << "> Jenis Kelamin\t\t\t: " << members[i].gender << endl;
        cout << "> Jumlah Saldo\t\t\t: " << members[i].saldo << endl;
    }
    cout << "--------------------------------------------------------------\n";
    cout << "\ntekan ENTER untuk kembali ke menu..." << endl;
    cin.ignore();
    cin.get();
}

// Fungsi untuk menghapus data member
void hapus(string nama) {
    for (int i = 0; i < numMembers; ++i) {
        if (members[i].nama == nama) {
            for (int j = i; j < numMembers - 1; ++j) {
                members[j] = members[j + 1];
            }
            numMembers--;
            cout << "Data member tersebut berhasil dihapus !\n\nTekan ENTER untuk kembali ke menu..." << endl;
            return;
        }
    }
    cout << "Member dengan nama '" << nama << "' tidak ditemukan.\n\nTekan ENTER untuk kembali ke menu..." << endl;
}

// Fungsi untuk isi/tarik saldo
void isitarik() {
    int pilih3;
    bersih();
    header();
    cout << "||                    ISI / TARIK SALDO                     ||\n";
    cout << "==============================================================\n";
    cout << "Pilihan: \n";
    cout << "1. Isi Saldo\n";
    cout << "2. Tarik Tunai\n";
    cout << "3. Kembali ke menu\n";
    cout << "Input Pilihan (1-3) : ";
    cin >> pilih3;
    if (pilih3 == 1) {
        bersih();
        header();
        cout << "||                       ISI SALDO                          ||\n";
        cout << "==============================================================\n";
        string nama;
        cout << "Masukkan nama member : ";
        cin.ignore();
        getline(cin, nama);

        bool ketemu = false;

        for (int i = 0; i < numMembers; ++i) {
            if (members[i].nama == nama) {
                cout << "--------------------------------------------------------------\n";
                cout << "Nama Member\t\t: " << nama << endl;
                cout << "Saldo Awal\t\t: " << members[i].saldo << endl;
                cout << "Input Nominal Setoran\t: ";
                cin >> isi;
                cout << endl;
                members[i].saldo += isi;
                cout << "> Setoran Berhasil ! " << endl;
                cout << "Total Saldo Anda\t: " << members[i].saldo << endl;
                cout << "--------------------------------------------------------------\n";
                ketemu = true;
                break;
            }
        }
        if (!ketemu) {
            cout << "> Member dengan nama '" << nama << "' tidak ditemukan!" << endl;
        }
        cout << "\nTekan ENTER untuk kembali ke menu..." << endl;
        cin.ignore();
        cin.get();
        menu();
    } else if (pilih3 == 2) {
        bersih();
        header();
        cout << "||                      TARIK SALDO                         ||\n";
        cout << "==============================================================\n";
        string nama;
        cout << "Masukkan nama member : ";
        cin.ignore();
        getline(cin, nama);

        bool ketemu = false;

        for (int i = 0; i < numMembers; ++i) {
            if (members[i].nama == nama) {
                cout << "--------------------------------------------------------------\n";
                cout << "Nama Member\t\t: " << nama << endl;
                cout << "Saldo Awal\t\t: " << members[i].saldo << endl;
                cout << "Input Nominal Penarikan\t: ";
                cin >> isi;
                cout << endl;
                if (members[i].saldo < isi) {
                    cout << "Saldo tidak mencukupi untuk penarikan." << endl;
                } else {
                    members[i].saldo -= isi;
                    cout << "> Penarikan Berhasil ! " << endl;
                    cout << "Total Saldo Anda\t: " << members[i].saldo << endl;
                }
                cout << "--------------------------------------------------------------\n";
                ketemu = true;
                break;
            }
        }
        if (!ketemu) {
            cout << "> Member dengan nama '" << nama << "' tidak ditemukan!" << endl;
        }
        cout << "\nTekan ENTER untuk kembali ke menu..." << endl;
        cin.ignore();
        cin.get();
        menu();
    } else {
        cout << "\nTidak ada di pilihan, tekan ENTER untuk kembali ke menu..." << endl;
        cin.ignore();
        cin.get();
        menu();
    }
}
