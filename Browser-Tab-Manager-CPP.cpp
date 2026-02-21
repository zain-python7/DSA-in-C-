#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string title;
    Node* next;
    Node* prev;

    Node(string t) {
        title = t;
        next = NULL;
        prev = NULL;
    }
};

class Hello {
    Node* head;
    Node* current;

public:
    Hello() {
        head = NULL;
        current = NULL;
    }

    void openNewTab(string title) {
        Node* newTab = new Node(title);

        if (head == NULL) {
            newTab->next = newTab;
            newTab->prev = newTab;
            head = newTab;
            current = newTab;
        } else {
            newTab->next = head;
            newTab->prev = head->prev;
            head->prev->next = newTab;
            head->prev = newTab;
            current = newTab;
        }

        cout << "tab is opend " << title << endl;
    }

    void closeCurrentTab() {
        if (current == NULL) {
            cout << "no one is present "<<endl;
            return;
        }

        if (current->next == current) {
            cout << "tab closing  " << current->title << endl;
            delete current;
            current = NULL;
            head = NULL;
            return;
        }

        Node* temp = current;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp == head)
            head = temp->next;

        cout << "Closed tab: " << temp->title << endl;
        current = temp->next;
        delete temp;
    }

    void nextTab() {
        if (current == NULL) {
            cout << "No tabs open.\n";
            return;
        }
        current = current->next;
        cout << "Moved to next tab: " << current->title << endl;
    }

    void prevTab() {
        if (current == NULL) {
            cout << "No tabs open.\n";
            return;
        }
        current = current->prev;
        cout << "Moved to previous tab: " << current->title << endl;
    }

    void showTabs() {
        if (head == NULL) {
            cout << "No tabs open.\n";
            return;
        }

        cout << "Currently open tabs:\n";
        Node* temp = head;

        
        for (Node* temp = head; ; temp = temp->next) {
            if (temp == current)
                cout << "-> ";
            else
                cout << "   ";
            cout << temp->title << endl;

            if (temp->next == head)
                break; 
        }
    }

    ~Hello() {
        if (head == NULL) return;
        Node* temp = head->next;
        while (temp != head) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
    }
};

int main() {
    Hello obj;
    int choice = 0;
    string title;

    while (choice != 6) {
        cout << "\n=== Tabs Menu ===\n";
        cout << "1. Open new tab\n";
        cout << "2. Close current tab\n";
        cout << "3. Move to next tab\n";
        cout << "4. Move to previous tab\n";
        cout << "5. Show all open tabs\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tab title: ";
            cin.ignore();
            getline(cin, title);
            obj.openNewTab(title);
        } else if (choice == 2) {
            obj.closeCurrentTab();
        } else if (choice == 3) {
            obj.nextTab();
        } else if (choice == 4) {
            obj.prevTab();
        } else if (choice == 5) {
            obj.showTabs();
        } else if (choice == 6) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
