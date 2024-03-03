#include <iostream>

using namespace std;

int main() {
    int matrixA[2][2], matrixB[2][2], matrixC[2][2], i, j, k;



    //Masukkan nilai matrix A
    cout << "=========================================" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << "Masukkan nilai dari matrix A = [" << i << "][" << j << "] : ";
            cin >> matrixA[i][j];
        }
    }

    //Output matrix A
    cout << "\nMatrix A : " << endl;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //Masukkan nilai matrix B
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << "Masukkan nilai dari matrix B = [" << i << "][" << j << "] : ";
            cin >> matrixB[i][j];
        }
    }

    //Output matrix B
    cout << "\nMatrix B : " << endl;
     for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    //Perkalian matrix
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            matrixC[i][j] = 0;
            for (k = 0; k < 2; k++){   
                 matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }       
        }    
    } 

     // Print hasil perkalian matrix
    cout << "\nHasil perkalian matriks A dan B\n";
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << matrixC[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "=========================================";
    cout << "\n\n Nama : Haliza Adzikia Sukarno " << endl << " NPM : 2310631170087 ";

    return 0;
}