#include <iostream>

using namespace std;

int main() {

    string alphabet {" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"?MSLGZTXQBDRAOYWHFUICJPNKEVmslgztxqbdraoywhfuicjpnkev"};
    string input;
    char choice;

    cout << "Enter your message : ";
    getline(cin, input);

    string encryption;

    for(char character: input) {
        size_t position = alphabet.find(character);
        if(position != string::npos) {
            char new_char {key.at(position)};
            encryption += new_char;
        }else {
            encryption += character;
        }
    }

    cout << encryption << endl;

    cout << "Do you want to decrypt the message ? ";
    cin >> choice;

    string decryption;
    if(choice == 'y' || choice == 'Y') {

        for(char character: encryption) {
            size_t position = key.find(character);
            if(position != string::npos) {
                char new_char {alphabet.at(position)};
                decryption += new_char;
            }else
                decryption += character;
        }

    }else {
        cout << "Bye Bitch" << endl;
    }

    cout << decryption << endl;


    return 0;
}
