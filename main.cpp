#include <iostream>
#include <stdio.h>
#include "encryption.hpp"
#include "decryption.hpp"

using namespace std;

void Decrypt();
void Encrypt();

int main(){
    int choice;

    cout << "\nAttention !!!\n"
                "You should give the KEY MATRIX as the main key for\n"
                "encryption and decryption instead of the INVERSE KEY MARTRIX.\n"
                "This program uses 2x2 matrix encryption key...\n"
                "GOOD LUCK !\n\n";

    while(true){
        cout << "Press 1 to Encrypt..." << endl;
        cout << "Press 2 to Decrypt..." << endl;
        cout << "Press 0 to Exit..." << endl;

        cin >> choice;

        switch(choice){
            case 0:
                return false;
            case 1:
                Encrypt();
                break;
            case 2:
                Decrypt();
                break;
        }
    }

    return 0;
}
