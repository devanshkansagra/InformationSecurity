#include<bits/stdc++.h>
using namespace std;

string encrypt(string plain, int key) {
    string result = "";
    for(int i = 0; i < plain.length(); i++) {

        if(isupper(plain[i])) {
            result += char(int(plain[i] + key - 65)%26 + 65);
        }
        else {
            result += char(int(plain[i] + key - 97)%26 + 97);
        }

    }
    return result;
}

string decrypt(string encrypted, int key) {
    string plain = "";
    for(int i = 0; i < encrypted.length(); i++) {
        char c = encrypted[i];
        if (isupper(c)) {
            plain += char(int(c - key - 'A' + 26) % 26 + 'A');
        }
        else if (islower(c)) {
            plain += char(int(c - key - 'a' + 26) % 26 + 'a');
        }
        else {
            plain += c;
        }
    }
    return plain;
}
int main() {

    string plain;
    cout << "Enter the plain text: ";
    cin >> plain;

    int key;
    cout << "Enter key: ";
    cin >> key;

    string encrypted = encrypt(plain, key);
    cout << "Plain text: " << plain << endl;
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
