/* SIMPLE ATBASH CIPHER
This program is a simple Atbash Cipher where the user can
choose to encrypt or decrypt a message, and the output
will use the Affine formula as the key for both.

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

        //  atbash encyrpting
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

            // user enters a message to  encrypt
            cout << "Enter your message to encrypt (up to 200 characters): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(e.message, 200);   // cin operator that also reads whitespaces
            cout << "The cipher is: ";

            //  atbash encryption logic
            for (int i = 0; i < 200 && e.message[i] != '\0'; i++) {
                
                // for lower-case characters
                if ('a' <= e.message[i] && e.message[i] <= 'z')   
                    e.encrypt[i] = 'a' + 'z' - e.message[i];
                
                // for capital characters
                else if ('A' <= e.message[i] && e.message[i] <= 'Z')    
                    e.encrypt[i] = 'A' + 'Z' - e.message[i];
                
                // for the spaces
                else    
                    e.encrypt[i] = e.message[i];
                cout << e.encrypt[i];
            }
            cout << "\n\n";

        //  atbach decrypting
        }
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
            cout << "Enter the cipher you want to decrypt (up to 200 characters): ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get(e.cipher, 200);   // ?
            cout << "The decrypted message is: ";
            
            //  atbash decryption logic is the same as the encryption logic
            for (int i = 0; i < 200 && e.cipher[i] != '\0'; i++) {
                if ('a' <= e.cipher[i] && e.cipher[i] <= 'z')   
                    e.decrypt[i] = 'a' + 'z' - e.cipher[i];
                else if ('A' <= e.cipher[i] && e.cipher[i] <= 'Z')
                    e.decrypt[i] = 'A' + 'Z' - e.cipher[i];
                else
                    e.decrypt[i] = e.cipher[i];
                cout << e.decrypt[i];
            }
            cout << "\n\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ?
            if (selection != "3") cout << "Invalid input.\n\n";
        }
    } while (selection != "3");

}