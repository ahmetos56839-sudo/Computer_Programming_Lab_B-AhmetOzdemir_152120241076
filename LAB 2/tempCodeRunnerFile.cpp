#include <iostream>
#include <string>

using namespace std;


struct Node {
    string songTitle;
    Node* next;
};


void addSong(Node*& head, string title) {
    Node* newNode = new Node(); 
    newNode->songTitle = title;  
    newNode->next = head;        
    head = newNode;              
    
    cout << ">> '" << title << "' listeye eklendi.\n";
}


void listSongs(Node* head) {
    if (head == nullptr) {
        cout << "\n[!] Oynatma listesi bos.\n";
        return;
    }

    Node* temp = head;
    int count = 1;
    cout << "\n--- MUZIK LISTESI ---" << endl;
    while (temp != nullptr) {
        cout << count << ". " << temp->songTitle << endl;
        temp = temp->next;
        count++;
    }
}


void searchSong(Node* head, string title) {
    Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->songTitle == title) {
            found = true;
            break;
        }
        temp = temp->next;
    }

    if (found) {
        cout << ">> Sonuc: '" << title << "' listede bulundu!\n";
    } else {
        cout << ">> Sonuc: '" << title << "' listede yok.\n";
    }
}

// 5. Ana Menü
int main() {
    Node* head = nullptr; 
    int choice;
    string input;

    do {
        cout << "\n--- PLAYLIST YONETIMI ---";
        cout << "\n1. Sarki Ekle (Basa)";
        cout << "\n2. Sarki Ara";
        cout << "\n3. Listeyi Goster";
        cout << "\n4. Cikis";
        cout << "\nSeciminiz: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Sarki adi giriniz: ";
                getline(cin, input);
                addSong(head, input);
                break;
            case 2:
                cout << "Aranacak sarki: ";
                getline(cin, input);
                searchSong(head, input);
                break;
            case 3:
                listSongs(head);
                break;
            case 4:
                cout << "Programdan cikiliyor...\n";
                break;
            default:
                cout << "Gecersiz secim!\n";
        }
    } while (choice != 4);

    return 0;
}