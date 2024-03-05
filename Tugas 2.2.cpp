#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "======================================" << endl;
    cout << "Program Putar Matriks 90 Derajat" << endl;
    cout << "======================================" << endl;

    cout << "Masukkan ukuran array (n x n) " << endl;
    cout << " n  =  "; cin >> n;

    int m[n][n];

    cout << "Masukkan nilai elemen array:" << endl;        // Input nilai array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << "Masukan elemen [" << i + 1 << "] [" << j + 1 << " ] : ";cin >> m[i][j];
            }
        }

    cout << endl << "Array awal:" << endl;       // Tampilkan array awal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n / 2; i++) {           // Putar gambar 90 derajat searah jarum jam
        for (int j = i; j < n - i - 1; j++) {
            int a = m[i][j];
            m[i][j] = m[n - 1 - j][i];
            m[n - 1 - j][i] = m[n - 1 - i][n - 1 - j];
            m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
            m[j][n - 1 - i] = a;
        }
    }

    cout << endl << "Array setelah diputar 90 derajat searah jarum jam:" << endl;        // Tampilkan array setelah diputar
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }

    cout << "======================================" << endl;
    cout << endl;
    cout << "======================================" << endl;
    cout << "Nama   : Haliza Adzikia Sukarno"  << endl;
    cout << "NPM    : 2310631170087"  << endl;
    cout << "Kelas  : 2C - Informatika"  << endl;
    cout << "======================================" << endl;


    return 0;
}
