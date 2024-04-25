// singlelinkedlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
    int noMhs;
    string name;
    Node* next;
};

Node* START = NULL;

void addNode() {
    int nim;
    string nama;
    Node* nodeBaru = new Node();
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> nama;
    nodeBaru->noMhs = nim;
    nodeBaru->name = nama;

    if (START == NULL || nim <= START->noMhs) {
        if (START != NULL && nim == START->noMhs) {
            cout << "NIM sudah ada" << endl;
            return;
        }

        nodeBaru->next = START;
        START = nodeBaru;
        return;
    }

    Node* previous = START;
    Node* current = START;

    while ((current != NULL) && (nim > current->noMhs)) {
        if (nim == current->noMhs) {
            cout << "NIM sudah ada" << endl;
            return;
        }
        previous = current;
        current = current->next;
    }

    nodeBaru->next = current;
    previous->next = nodeBaru;
}

int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
