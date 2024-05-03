#include <iostream>
using namespace std;

struct Stack {
    int data;
    Stack* next;
};

Stack* buatSimpul(int data) {
    Stack* simpulBaru = new Stack();
    simpulBaru->data = data;
    simpulBaru->next = nullptr;
    return simpulBaru;
}

bool isEmpty(Stack* top) {
    return (top == nullptr);
}

// Fungsi untuk menambahkan elemen ke stack
void push(Stack** top, int data) {
    Stack* simpulBaru = buatSimpul(data);
    if (*top == nullptr || data < (*top)->data) { // Memasukkan nilai ke stack sesuai urutan
        simpulBaru->next = *top;
        *top = simpulBaru;
    } else {
        Stack* current = *top;
        while (current->next != nullptr && data > current->next->data) {
            current = current->next;
        }
        simpulBaru->next = current->next;
        current->next = simpulBaru;
    }
}


// Fungsi untuk menghapus elemen dari stack
int pop(Stack** top) {
    if (isEmpty(*top)) {
        return 0;
    }

    int data = (*top)->data;
    Stack* temp = *top;
    *top = (*top)->next;
    delete temp;
    return data;
}

// Fungsi untuk memindahkan dari menara awal ke menara tujuan
void pindah(Stack** fromStack, Stack** toStack, char liza, char she) {
    int elemen = pop(fromStack);
    push(toStack, elemen);
    cout << "Memindahkan " << elemen << " dari " << liza << " ke " << she << endl;
}
    
void tampil(Stack* tower, char he, bool isFirst) {
    if (isFirst) {
        cout << "This is stack of hanoi tower!\n";
        cout << "============================\n";
    }
    cout << "Tower " << he << ": ";
    Stack* bantu = tower;
    while (bantu != nullptr) {
        cout << bantu->data << " -> ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {
    // Inisialisasi menara A, B, dan C
    Stack* towerA = nullptr;
    Stack* towerB = nullptr;
    Stack* towerC = nullptr;

    // Push beberapa nilai ke menara B
    push(&towerB, 10);
    push(&towerB, 30);
    push(&towerB, 50);

    // Karakter untuk mewakili setiap menara
    char menaraAwal = 'A';
    char menaraTujuan = 'B';
    char menaraBantu = 'C';

    // Tampilkan kondisi awal menara
    tampil(towerA, 'A', true);
    tampil(towerB, 'B', false);
    tampil(towerC, 'C', false);
    cout << endl;

    // Pindahkan nilai dari menara B ke menara A
    if (!isEmpty(towerB)) {
        pindah(&towerB, &towerA, menaraTujuan, menaraAwal);
        tampil(towerA, 'A', true);
        tampil(towerB, 'B', false);
        tampil(towerC, 'C', false);
        cout << endl;
    } else {
        cout << "Menara B kosong, tidak ada nilai yang berpindah.\n\n";
    }

    // Pindahkan nilai dari menara C ke menara A
    if (!isEmpty(towerC)) {
        pindah(&towerC, &towerA, menaraBantu, menaraAwal);
        tampil(towerA, 'A', true);
        tampil(towerB, 'B', false);
        tampil(towerC, 'C', false);
        cout << endl;
    } else {
        cout << "Menara C kosong, tidak ada nilai yang berpindah.\n\n";
    }

    // Pindahkan nilai dari menara B ke menara C
    if (!isEmpty(towerB)) {
        pindah(&towerB, &towerC, menaraTujuan, menaraBantu);
        tampil(towerA, 'A', true);
        tampil(towerB, 'B', false);
        tampil(towerC, 'C', false);
        cout << endl;
    } else {
        cout << "Menara B kosong, tidak ada nilai yang berpindah.\n\n";
    }

    // Tampilkan kondisi terakhir menara
    tampil(towerA, 'A', true);
    tampil(towerB, 'B', false);
    tampil(towerC, 'C', false);

    cout << "\n\n============================================================" << endl; 
    cout << "Nama  : Haliza Adzikia Sukarno" << endl;
    cout << "NPM   : 2310631170087" << endl;
    cout << "kelas : 2C-Informatika" << endl;
    cout << "============================================================" << endl; 
    

    return 0;
}

