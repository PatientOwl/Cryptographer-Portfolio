/* SIMPLE CAESAR CIPHER
This program is a simple Caesar Cipher where the user can
choose to encrypt or decrypt a message, and create or use
a key for the appropriate operation.

~ Legend Artis 04/10/2022
*/

#include<iostream>
#include<ios> // used to get stream size
#include<limits> // used to get numeric limits
using namespace std;

struct encryption {
    char encrypt[200], decrypt[200], message[200], cipher[200];
    int key;
};

int main() {
    string selection;
    struct encryption e;

    // User makes their choice to encrypt or decrypt a message
    // or exit the program
    do {
        cout << "Enter your choice: ";
        cout << "1. Encryption      2. Decryption       3. Exit\n";
        cin >> selection;

        //  Selection 1: Encryption
        if (selection == "1") {
            cout << "Enter encryption key: ";

            // taking only integer input for encryption key
            while (true) {
                cin >> e.key;
                if (!cin) {
                    cout << "Invalid key number. Enter again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else {
                    fflush(stdin);
                    break;
                }
            }

            // user enters a message to encrypt
            cout << "Enter your message to encrypt (up to 200 characters): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(e.message, 200);
            cout << "The cipher is: ";

            // Caesar Cipher algorithm (encryption)
            for (int i = 0; i < 200 && e.message[i] != '\0'; i++) {
                e.encrypt[i] = (int)e.message[i] + e.key;
                cout << e.encrypt[i];
            }
            cout << "\n\n";
        }

        // Selection 2: Decryption
        else if (selection == "2") {
            cout << "Enter decryption key: ";

            // taking only integer input for decryption key
            while (true) {
                cin >> e.key;
                if (!cin) {
                    cout << "Invalid key number. Enter again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                else {
                    fflush(stdin);
                    break;
                }
            }

            // user enters the ciphered message
            cout << "Enter the cipher you want to decrypt (up to 200 characters): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(e.cipher, 200);   // ?
            cout << "The decrypted message is: ";

            // Caesar Cipher algorithm (decryption)
            for (int i = 0; i < 200 && e.cipher[i] != '\0'; i++) {
                e.decrypt[i] = (int)e.cipher[i] - e.key;
                cout << e.decrypt[i];
            }
            cout << "\n\n";
        }

        // loops program until user enters a valid input
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?
            if (selection != "3") cout << "Invalid input.\n\n";
        }
    } while (selection != "3");

}
