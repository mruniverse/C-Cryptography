#include <iostream>
// #include "main.cpp"

using namespace std;

void Decrypt(){
    int i = 0;
    int n = 0;
    char lP[2][50];
    float M[2][2], I[2][2],E[2][50];
    float P[2][50];
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
    for(int l = 0; l < 2; l ++){
        for(int c = 0; c < 50; c++){
            E[l][c] = 0;
        }
    }
//Insert Key Matrix ============================================================
    system("clear");
    cout << "Enter the elements of the Key Matrix: \n";
        for(int l = 0; l < 2; l ++){
            for(int c = 0; c < 2; c++){
                cin >> M[l][c];
            }
        }
    system("clear");
    cout << "Key Matrix:\n";
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
    cout << "\nInsert the index:\n";
    cin >> n;
    float V[n];
    cout << "\nInsert the encrypted phrase: \n";
    for(int i = 0; i < n; i++){
        cin >> V[i];
    }
    cout << endl;
    // if(phrase.length()%2 != 0){
    //     phrase = phrase + " ";
    // }
    i = 0;
    for(int l = 0; l < 2; l++){
        for(int c = 0; c < (n/2); c++){
            P[l][c] = V[i];
            i++;
            cout << P[l][c] << " |";
        }
        cout << "\n";
    }
//Multiplication of the Matrix Key and the Matrix Phrase =======================
for(int l = 0; l < 2; l++){
    for(int k = 0; k < n/2; k++){
        for(int c = 0; c < 2; c++){
            E[l][k] += M[l][c] * P[c][k];
        }
    }
}

    // cout << endl;
    // for(int l = 0; l < 2; l++){
    //     for(int c = 0; c < (n/2); c++){
    //         cout << E[l][c] << endl;
    //     }
    // }

//Transform to ASCII Table =====================================================
    for(int l = 0; l < 2; l++){
        for(int c = 0; c < (n/2); c++){
            lP[l][c] = E[l][c];
        }
    }

//Decrypted Phrase =============================================================
    cout << endl;
    cout << "Decrypted Message:\n";
    for(int l = 0; l < 2; l++){
        for(int c = 0; c < (n/2); c++){
            cout << lP[l][c];
        }
        cout << endl;
    }
    cout << endl;
//Print the Inverse of the Key Matrix ==========================================
    cout << "Inverse of the Key Matrix:\n";
    for(int l = 0; l < 2; l ++){
        for(int c = 0; c < 2; c++){
            cout << I[l][c];
            cout << " | ";
        }
        cout << "\n";
    }
//==============================================================================
cout << endl;
}
