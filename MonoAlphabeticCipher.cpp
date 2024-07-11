#include<bits/stdc++.h>
using namespace std;

string mixed = "";
string encrypt(string plain, string key) {
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string encrypted = "";
    for(int i = 0; i < key.length(); i++) {
        bool isPresent = false;
        for(int j = 0; j < mixed.length(); j++) {
            if(key[i] == mixed[j]) {
                isPresent = true;
            }
        }
        if(!isPresent || mixed == "") {
            mixed.push_back(key[i]);
        }
    }

    for(int i = 0; i < alpha.length(); i++) {
        bool isPresent = false;
            for(int j = 0; j < key.length(); j++) {
                if(alpha[i] == key[j]) {
                    isPresent = true;
                }
            }
            if(!isPresent) {
                mixed.push_back(alpha[i]);
            }
    }

    for(int i = 0; i < plain.length(); i++) {
        for(int j = 0; j < alpha.length(); j++) {
            if(plain[i] == alpha[j]) {
                encrypted.push_back(mixed[j]);
            }
        }
    }

    return encrypted;
}
string decrypt(string enc, string key) {
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string decrypted = "";
    for(int i = 0; i < key.length(); i++) {
        bool isPresent = false;
        for(int j = 0; j < mixed.length(); j++) {
            if(key[i] == mixed[j]) {
                isPresent = true;
            }
        }
        if(!isPresent || mixed == "") {
            mixed.push_back(key[i]);
        }
    }
    for(int i = 0; i < enc.length(); i++) {
        for(int j = 0; j < alpha.length(); j++) {
            if(enc[i] == mixed[j]) {
                decrypted.push_back(alpha[j]);
            }
        }
    }
    return decrypted;
}
int main() {

    string plain = "BVMENGINEERINGCOLLEGE";
    string key = "DEVANSHKANSAGRA";


    string enc = encrypt(plain, key);
    cout << "Plain text: " << plain << endl;
    cout << "Encrypted text: " << enc << endl;

    string dec = decrypt(enc, key);
    cout << "Decrypted text: " << dec << endl;
    return 0;
}
