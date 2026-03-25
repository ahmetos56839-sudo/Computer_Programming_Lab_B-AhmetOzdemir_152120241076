#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Page {
    string url;
    string title;
    int accessTime[3];
    Page *next;
    Page *prev;

    Page(string u, string t, int h, int m, int s) {
        url = u;
        title = t;
        accessTime[0] = h;
        accessTime[1] = m;
        accessTime[2] = s;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory {
private:
    Page* head;
    Page* current;

    void clearFrom(Page* startNode) {
        while (startNode) {
            Page* nextNode = startNode->next;
            delete startNode;
            startNode = nextNode;
        }
    }

public:
    BrowserHistory() : head(nullptr), current(nullptr) {}

    void visit(string url, string title, int h, int m, int s) {
        Page* newPage = new Page(url, title, h, m, s);
        
        if (!head) {
            head = newPage;
            current = head;
        } else {
            if (current->next) {
                clearFrom(current->next);
                current->next = nullptr;
            }
            current->next = newPage;
            newPage->prev = current;
            current = newPage;
        }
    }

    void back() {
        if (current && current->prev) {
            current = current->prev;
        }
    }

    void forward() {
        if (current && current->next) {
            current = current->next;
        }
    }

    void deleteCurrent() {
        if (!current) return;

        Page* toDelete = current;

        if (toDelete->prev) toDelete->prev->next = toDelete->next;
        if (toDelete->next) toDelete->next->prev = toDelete->prev;

        if (toDelete == head) head = toDelete->next;

        if (toDelete->prev) current = toDelete->prev;
        else current = toDelete->next;

        delete toDelete;
    }

    void displayHistory() {
        if (!head) return;

        Page* temp = head;
        while (temp) {
            if (temp == current) cout << "-> [CURRENT] ";
            else cout << "   ";

            cout << temp->title << " (" << temp->url << ") ";
            
            for (int i = 0; i < 3; i++) {
                cout << setfill('0') << setw(2) << temp->accessTime[i] << (i < 2 ? ":" : "");
            }
            cout << endl;
            temp = temp->next;
        }
    }

    ~BrowserHistory() {
        clearFrom(head);
    }
};

int main() {
    BrowserHistory myBrowser;
    string command;

    while (true) {
        cin >> command;

        if (command == "visit") {
            string u, t;
            int h, m, s;
            cin >> u >> t >> h >> m >> s;
            myBrowser.visit(u, t, h, m, s);
        } else if (command == "back") {
            myBrowser.back();
        } else if (command == "forward") {
            myBrowser.forward();
        } else if (command == "delete") {
            myBrowser.deleteCurrent();
        } else if (command == "show") {
            myBrowser.displayHistory();
        } else if (command == "EXIT") {
            break;
        }
    }

    return 0;
}