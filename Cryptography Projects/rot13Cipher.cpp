/* ROT13 CIPHER
This program is a ROT13 Cipher, where the user can
choose to encrypt or decrypt a message by an
alphabetical "rotation" of 13.

~ Legend Artis 4/10/2022
*/

#include<iostream>
#include<ios> // used to get stream size
#include<limits> // used to get numeric limits
using namespace std;

struct encryption {
    char encrypt[200], decrypt[200], message[200], cipher[200];
};

int main() {
    string selection;
    struct encryption e;

    //  User makes their choice to encrypt or decrypt a message
    //  or exit the program

    do {
        cout << "Enter your choice: ";
        cout << "1. Encryption      2. Decryption       3. Exit\n";
        cin >> selection;

        // Selection 1: ROT13 Encrypting
        if (selection == "1") {
            while (true) {
                if (!cin) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else {
                    fflush(stdin);
                    break;
                }
            }

            // user inputs message to encrypt
            cout << "Enter your message to encrypt (up to 200 characters): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(e.message, 200);
            cout << "The cipher is: ";
            
            //  rot13 encryption logic
            for (int i = 0; i < 200 && e.message[i] != '\0'; i++) {
                if ('A' <= e.message[i] && e.message[i] <= 'M')
                    e.encrypt[i] = e.message[i] + 13;
                else if ('N' <= e.message[i] && e.message[i] <= 'Z')
                    e.encrypt[i] = e.message[i] - 13;
                else if ('a' <= e.message[i] && e.message[i] <= 'm')
                    e.encrypt[i] = e.message[i] + 13;
                else if ('n' <= e.message[i] && e.message[i] <= 'n')
                    e.encrypt[i] = e.message[i] - 13;
                else
                    e.encrypt[i] = e.message[i];
                cout << e.encrypt[i];
            }
            cout << "\n\n";
        }

        //  Selection 2: ROT13 Decrypting
        else if (selection == "2") {
            while (true) {
                if (!cin) {   // ?
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else {
                    fflush(stdin);
                    break;
                }
            }

            // user inputs cipher message
            cout << "Enter the cipher you want to decrypt (up to 200 characters): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(e.cipher, 200);   // ?
            cout << "The decrypted message is: ";
            
            //  rot13 decryption logic is the same as the encryption logic
            for (int i = 0; i < 200 && e.cipher[i] != '\0'; i++) {
                if ('A' <= e.cipher[i] && e.cipher[i] <= 'M')
                    e.decrypt[i] = e.cipher[i] + 13;
                else if ('N' <= e.cipher[i] && e.cipher[i] <= 'Z')
                    e.decrypt[i] = e.cipher[i] - 13;
                else if ('A' <= e.cipher[i] && e.cipher[i] <= 'M')
                    e.decrypt[i] = e.cipher[i] + 13;
                else if ('N' <= e.cipher[i] && e.cipher[i] <= 'Z')
                    e.decrypt[i] = e.cipher[i] - 13;
                else
                    e.decrypt[i] = e.message[i];
                cout << e.decrypt[i];
            }
            cout << "\n\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (selection != "3") cout << "Invalid input.\n\n";
        }
    } while (selection != "3");

}