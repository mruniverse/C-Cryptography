#include <iostream>
// #include "matrix.hpp"

using namespace std;

int main(){
    int i = 0;
    float M[2][2], I[2][2];
    char P[2][50];
    float D = 0;
    string phrase;

//Initialize the Matrix ====================================================
    for(int l = 0; l < 2; l ++){
        for(int c = 0; c < 2; c++){
            M[l][c] = 0;
        }
    }
    for(int l = 0; l < 2; l ++){
        for(int c = 0; c < 50; c++){
            P[l][c] = 0;
        }
    }
//Insert Key Matrix ============================================================
    cout << "Enter the elements of the Key Matrix: " << endl;
        for(int l = 0; l < 2; l ++){
            for(int c = 0; c < 2; c++){
                cin >> M[l][c];
            }
        }
        system("clear");
        cout << "Key Matrix:" << endl;
        for(int l = 0; l < 2; l ++){
            for(int c = 0; c < 2; c++){
                cout << M[l][c];
                cout << " | ";
            }
            cout << "\n";
        }
//Finding the Inverse of the Key Matrix ========================================
    float aux;
    D = M[0][0] * M[1][1] - M[1][0] * M[0][1];

    I[0][0] = (1.0/D) * M[1][1];
    I[1][1] = (1.0/D) * M[0][0];
    I[0][1] = (1.0/D) * -M[0][1];
    I[1][0] = (1.0/D) * -M[1][0];
//==============================================================================
    cout << "Insert the phrase to be Encrypted: " << endl;
    cin.ignore();
    getline(cin, phrase);
    if(phrase.length()%2 != 0){
        phrase = phrase + " ";
    }
    for(int l = 0; l < 2; l++){
        for(int c = 0; c < (phrase.length()/2); c++){
            P[l][c] = phrase[i];
            i++;
            cout << P[l][c] << " |";
        }
        cout << "\n";
    }
//==============================================================================
    // system("clear");
    cout << "Inverse of the Key Matrix:" << endl;
    for(int l = 0; l < 2; l ++){
        for(int c = 0; c < 2; c++){
            cout << I[l][c];
            cout << " | ";
        }
        cout << "\n";
    }
//==============================================================================



    return 0;
}
