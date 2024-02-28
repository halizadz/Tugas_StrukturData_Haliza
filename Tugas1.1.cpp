#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Jumlah Mahasiswa : 10" << endl;

  // declare an array of 10 strings and pointer
  string namaMahasiswa[10];
  string *alamat_nama = &namaMahasiswa[9];
   

  // take the names of 10 students as input
  for (int i = 0; i < 10; i++) {
    cout << "Masukkan nama mahasiswa ke-" << i+1 << " : ";
    cin >> namaMahasiswa[i];  
  }

  // print out the names and their memory addresses
  cout << "\nNama Mahasiswa \t\tAlamat pada komputer" << endl;
  cout << "-----------------------------------------" << endl;
  for (int i = 0; i < 10; i++) {
    cout << namaMahasiswa[i] << "\t\t\t" << &alamat_nama[i] <<endl;
    
  }
  cout << "-----------------------------------------" << endl;
    cout << "\n\nNama : Haliza Adzikia Sukarno" << endl <<  "NPM : 2310631170087";
  return 0;
}