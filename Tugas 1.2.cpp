#include <iostream>

using namespace std;

int compress (char* y, int length) {
    int index = 0; 
    int count = 1;
    for (int i = 1; i <= length; i++) {
        if (y[i] == y[i-1]) {
            count++;
        } else {
            y[index++] = y[i-1];{
                string count_str = to_string(count);
                for (int j = 0; j < count_str.length(); j++) {
                    y[index++] = count_str[j];
                }
            }
            count = 1;
        }
    }
    return index;
}

int main () {
    int length;
    cout << "-----------------------------------------" << endl;
    cout << "MasukKan Panjang Array : ";
    cin >> length;
    char y[length];
    cout << "MasukKan Karakter Array : ";
    for (int i = 0; i < length; i++) {
        cin >> y[i];
    }
    int compressed_length = compress (y, length);
    for (int i = 0 ; i < compressed_length; i++) {
        cout << y[i];
    }
    cout <<"\n-----------------------------------------" << endl;
    cout <<"\n\nNama : Haliza Adzikia Sukarno" << endl << "NPM : 2310631170087"; 
    return 0;
}