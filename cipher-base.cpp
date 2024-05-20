#include <iostream>
#include <fstream>
#include <climits> 
#include <string>
#include <cstdlib> 

using namespace std;

void menu() {
    cout << "***********************\n";
    cout << "    Caesar Cipher\n";
    cout << "***********************\n\n";
    cout << "Select Choice \n1. For encryption\n2. For decryption \n";
}

string ENCRYPT(string plaintext, int shift) {
    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + shift;
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ch + shift;
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
        }
        plaintext[i] = ch;
    }
    return plaintext;
}

string Decrypt(string ciphertext, int shift) {
    for (int i = 0; i < ciphertext.length(); i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = ciphertext[i] - shift;
            if (ciphertext[i] < 'A') {
                ciphertext[i] = ciphertext[i] + 'Z' - 'A' + 1;
            }
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = ciphertext[i] - shift;
            if (ciphertext[i] < 'a') {
                ciphertext[i] = ciphertext[i] + 'z' - 'a' + 1;
            }
        }
    }
    return ciphertext;
}

int main() {
    // File for Encryption
    fstream new_file;
    new_file.open("new_file.txt", ios::out);
    if (!new_file) {
        cout << "File creation failed\n";
    } else {
        new_file << "Amazon Forest";
        new_file.close();
    }

    // Reading Content from Encrypted File
    string line;
    ifstream file("new_file.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    // File for Decryption
    fstream new_file1;
    new_file1.open("new_file1.txt", ios::out);
    if (!new_file1) {
        cout << "File creation failed\n";
    } else {
        new_file1 << "Eqedsr Jsviwx";
        new_file1.close();
    }

    // Reading Content from Decrypted file
    string line1;
    ifstream file1("new_file1.txt");
    if (file1.is_open()) {
        while (getline(file1, line1)) {
            cout << line1 << endl;
        }
        file1.close();
    }

    int shift, choice;
    string text;
    char ch;
    do {
        system("cls");
        menu();
        cin >> choice;
        while (choice != 1 && choice != 2) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid Input Enter Again: ";
            cin >> choice;
        }
        cout << "Enter Shift: ";
        cin >> shift;
        cin.ignore(INT_MAX, '\n');
        if (choice == 1) {
            cout << "Plaintext is: " << line << endl;
            text = ENCRYPT(line, shift);
            cout << "Cipher Text is: " << text << endl;
        } else {
            cout << "Ciphertext is: " << line1 << endl;
            text = Decrypt(line1, shift);
            cout << "Plaintext is: " << text << endl;
        }
        cout << "Do you want to continue? Y/N: ";
        cin >> ch;
    } while (toupper(ch) == 'Y');

    return 0;
}
