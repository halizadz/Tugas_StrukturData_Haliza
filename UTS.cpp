#include <iostream>
#include <string>

using namespace std;

// Struktur untuk tanggal
struct Tanggal {
    int tgl;
    int bln;
    int th;
};

// Struktur untuk data KTM
struct KTM {
    string npm;
    char nama[30];
    char jenis_kelamin;
    Tanggal t;
};

// Struktur Node untuk menyimpan data KTM dalam linked list
struct Node {
    KTM data;
    Node* next;
};

// Struktur LinkedList untuk mengelola linked list
struct LinkedList {
    Node* head;
};

// Fungsi-fungsi untuk manipulasi data KTM
void tambah(LinkedList& data_ktm);
void tampil(const LinkedList& list);
void tahunKelahiran(const LinkedList& data_ktm);
void jenisKelamin(const LinkedList& data_ktm);
void edit(LinkedList& data_ktm);

int main() {
    LinkedList data_ktm;
    data_ktm.head = nullptr;
    char ulang = 'y';

    cout << "===========================================" << endl;
    cout << "Nama : Haliza Adzikia Sukarno" << endl <<  "NPM : 2310631170087" << endl;
    cout << "==========================================" << endl;

    do {
        char kembali;
        system("clear");
        cout << "============ MENU ============\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Bedasarkan Tahun Kelahiran\n";
        cout << "4. Cari Bedasarkan Jenis Kelamin\n";
        cout << "5. Edit Data\n";
        cout << "6. Keluar\n";
        cout << "==============================\n";
        cout << "Masukkan pilihan: ";
        int pilih;
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambah(data_ktm);
                break;
            case 2:
                tampil(data_ktm);
                break;
            case 3:
                tahunKelahiran(data_ktm);
                break;
            case 4:
                jenisKelamin(data_ktm);
                break;
            case 5:
                edit(data_ktm);
                break;
            case 6:
                ulang = 'n';
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        cout << "Kembali ke Menu? (Y/N): ";
        cin >> kembali;
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}

// Fungsi untuk menambahkan data KTM ke linked list
void tambah(LinkedList& data_ktm) {
    Node* newNode = new Node;
    cout << "========== TAMBAH DATA ==========\n";
    cout << "NPM      : ";
    cin >> newNode->data.npm;
    cout << "Nama     : ";
    cin.ignore();
    cin.getline(newNode->data.nama, sizeof(newNode->data.nama));
    cout << "Jenis Kelamin (L/P): ";
    cin >> newNode->data.jenis_kelamin;
    cout << "Tanggal  : ";
    cin >> newNode->data.t.tgl;
    cout << "Bulan    : ";
    cin >> newNode->data.t.bln;
    cout << "Tahun    : ";
    cin >> newNode->data.t.th;
    newNode->next = nullptr;

    if (data_ktm.head == nullptr) {
        data_ktm.head = newNode;
    } else {
        Node* temp = data_ktm.head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Data berhasil ditambahkan\n";
}

// Fungsi untuk menampilkan semua data KTM dalam linked list
void tampil(const LinkedList& list) {
    if (list.head == nullptr) {
        cout << "Data kosong.\n";
        return;
    }

    Node* temp = list.head;
    cout << "========= DATA KTM ==================\n";
    while (temp != nullptr) {
        cout << "NPM           : " << temp->data.npm << "\n";
        cout << "Nama          : " << temp->data.nama << "\n";
        cout << "Jenis Kelamin : " << temp->data.jenis_kelamin << "\n";
        cout << "Tanggal Lahir : "
             << temp->data.t.tgl << "/"
             << temp->data.t.bln << "/"
             << temp->data.t.th << "\n";
        cout << "==================================\n";
        temp = temp->next;
    }
}

// Fungsi untuk mencari data KTM berdasarkan tahun kelahiran
void tahunKelahiran(const LinkedList& data_ktm) {
    if (data_ktm.head == nullptr) {
        cout << "Data kosong.\n";
        return;
    }

    int tahun_cari;
    int jumlah_data = 0;
    cout << "=== DATA KTM BERDASARKAN TAHUN KELAHIRAN ===\n";
    cout << "Tahun kelahiran: ";
    cin >> tahun_cari;
    Node* temp = data_ktm.head;
    cout << "=============================================\n";

    while (temp != nullptr) {
        if (temp->data.t.th == tahun_cari) {
            jumlah_data++;
            cout << "NPM           : " << temp->data.npm << "\n";
            cout << "Nama          : " << temp->data.nama << "\n";
            cout << "Jenis Kelamin : " << temp->data.jenis_kelamin << "\n";
            cout << "Tanggal Lahir : "
                 << temp->data.t.tgl << "/"
                 << temp->data.t.bln << "/"
                 << temp->data.t.th << "\n";
            cout << "=====================================\n";
        }
        temp = temp->next;
    }

    if (jumlah_data == 0) {
        cout << "Data tidak ditemukan.\n";
    } else {
        cout << "Jumlah data ditemukan: " << jumlah_data << "\n";
    }
}

// Fungsi untuk mencari data KTM berdasarkan jenis kelamin
void jenisKelamin(const LinkedList& data_ktm) {
    if (data_ktm.head == nullptr) {
        cout << "Data kosong.\n";
        return;
    }

    char jenis_cari;
    int jumlah_data = 0;
    cout << "==== DATA KTM BERDASARKAN JENIS KELAMIN ====\n";
    cout << "Jenis kelamin: ";
    cin >> jenis_cari;
    Node* temp = data_ktm.head;
    cout << "============================================\n";

    while (temp != nullptr) {
        if (temp->data.jenis_kelamin == jenis_cari) {
            jumlah_data++;
            cout << "NPM           : " << temp->data.npm << "\n";
            cout << "Nama          : " << temp->data.nama << "\n";
            cout << "Jenis Kelamin : " << temp->data.jenis_kelamin << "\n";
            cout << "Tanggal Lahir : "
                 << temp->data.t.tgl << "/"
                 << temp->data.t.bln << "/"
                 << temp->data.t.th << "\n";
            cout << "====================================\n";
        }
        temp = temp->next;
    }

    if (jumlah_data == 0) {
        cout << "Data tidak ditemukan.\n";
    } else {
        cout << "Jumlah data ditemukan: " << jumlah_data << "\n";
    }
}

// Fungsi untuk mengedit data KTM
void edit(LinkedList& data_ktm) {
    if (data_ktm.head == nullptr) {
        cout << "Data kosong.\n";
        return;
    }

    string npm_cari;
    int jumlah_data = 0;
    cout << "====== EDIT DATA ===========\n";
    cout << "NPM: ";
    cin >> npm_cari;
    Node* temp = data_ktm.head;
    cout << "============================\n";

    while (temp != nullptr) {
        if (temp->data.npm == npm_cari) {
            jumlah_data++;
            cout << "Masukkan data baru\n";
            cout << "NPM      : ";
            cin >> temp->data.npm;
            cout << "Nama     : ";
            cin.ignore();
            cin.getline(temp->data.nama, sizeof(temp->data.nama));
            cout << "Jenis Kelamin (L/P): ";
            cin >> temp->data.jenis_kelamin;
            cout << "Tanggal  : ";
            cin >> temp->data.t.tgl;
            cout << "Bulan    : ";
            cin >> temp->data.t.bln;
            cout << "Tahun    : ";
            cin >> temp->data.t.th;
            cout << "Data berhasil diubah\n";
            cout << "==========================\n";
        }
        temp = temp->next;
    }

    if (jumlah_data == 0) {
        cout << "Data tidak ditemukan.\n";
    }
}
