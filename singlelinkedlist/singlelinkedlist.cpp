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

bool serachNode(int nim, Node*& previous, Node*& current) {
    previous = START;
    current = START;

    while (current != NULL && nim != current->noMhs) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        return true;
    }
    else if (current->noMhs == nim) {
        return true;
    }
    else {
        return false;
    }
}

bool deleteNode(int nim) {
    Node* previous;
    Node* current;

    if (!serachNode(nim, previous, current) == false)
        return false;
    previous->next = current->next;
    if (current == START)
        START = current->next;
    return true;
}

bool listEmpty() {
    if (START == NULL) {
        return true;
    }
    else {
        return false;
    }
}


void traverse() {
    if (listEmpty()) {
        cout << "List kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        Node* currentNode = START;
        while (currentNode != NULL) {
            cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
    }
}

void searchNode() {
    if (listEmpty()) {
        cout << "List kosong" << endl;
        system("pause");
        system("cls");
        return;
    }
    else {
        int nim;
        cout << "Masukkan NIM yang dicari: ";
        cin >> nim;
        Node* currentNode = START;
        while (currentNode != NULL) {
            if (currentNode->noMhs == nim) {
                cout << "NIM: " << currentNode->noMhs << ", Nama: " << currentNode->name << endl;
                return;
            }
            currentNode = currentNode->next;
        }
        cout << "NIM tidak ditemukan" << endl;
    }
}

int main()
{
    int pilihan;
    do {
        try {
            cout << "1. Tambah Node" << endl;
            cout << "2. Hapus Node" << endl;
            cout << "3. Cari Node" << endl;
            cout << "4. Tampilkan Node" << endl;
            cout << "5. Keluar" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            switch (pilihan)
            {
            case 1:
                addNode();
                cout << "Node berhasil ditambahkan" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                if (listEmpty())
                {
                    cout << "List kosong" << endl;
                    system("pause");
                    system("cls");
                    break;
                }
                int nim;
                cout << "Masukkan NIM yang akan dihapus: ";
                cin >> nim;
                if (deleteNode(nim))
                {
                    cout << "nim" << nim << "berhasil dihapus" << endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    cout << "NIM tidak ditemukan" << endl;
                }
                break;
            case 3:
                searchNode();
                break;
            case 4:
                traverse();
                break;
            case 5:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        }
        catch (exception e)
        {
            cout << "Terjadi kesalahan: " << e.what() << endl;
        }
    } while (pilihan != 5);
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
