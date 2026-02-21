#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularSinglyList {
private:
    Node* head;

public:
    CircularSinglyList() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void insert_at_head() {
        int value;
        cout << "Enter value: ";
        cin >> value;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Inserted at head.\n";
    }

    void insert_at_end() {
        int value;
        cout << "Enter value: ";
        cin >> value;

        Node* newNode = new Node(value);

        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted at end.\n";
    }

    void random_insert() {
        int pos, value;
        cout << "Enter position: ";
        cin >> pos;
        cout << "Enter value: ";
        cin >> value;

        if (pos <= 1 || isEmpty()) {
            insert_at_head();
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;
        int i = 1;

        while (temp->next != head && i < pos - 1) {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Inserted at position " << pos << endl;
    }

    void delete_from_head() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        if (temp->next == head) {
            delete temp;
            head = NULL;
        } else {
            Node* last = head;
            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;
            delete temp;
        }
        cout << "Deleted from head.\n";
    }

    void delete_from_end() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        if (temp->next == head) {
            delete temp;
            head = NULL;
        } else {
            Node* prev = NULL;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
            delete temp;
        }
        cout << "Deleted from end.\n";
    }

    void random_delete() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        int pos;
        cout << "Enter position to delete: ";
        cin >> pos;

        if (pos <= 1) {
            delete_from_head();
            return;
        }

        Node* temp = head, *prev = NULL;
        int i = 1;

        while (temp->next != head && i < pos) {
            prev = temp;
            temp = temp->next;
            i++;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Deleted from position " << pos << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        cout << "CSLL: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD\n";
    }

    void search() {
        if (isEmpty()) {
            cout << "List is empty!\n";
            return;
        }

        int value, pos = 1;
        cout << "Enter value to search: ";
        cin >> value;

        Node* temp = head;
        do {
            if (temp->data == value) {
                cout << value << " found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        } while (temp != head);

        cout << value << " not found.\n";
    }

    int Size_of_List() {
        if (isEmpty()) return 0;

        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
};


// MAIN

int main() {
    CircularSinglyList csll;
    int choice;

    while (true) {
        cout << "\n===== Circular Singly Linked List =====\n";
        cout << "1. Insert Head\n2. Insert End\n3. Insert Position\n";
        cout << "4. Delete Head\n5. Delete End\n6. Delete Position\n";
        cout << "7. Display\n8. Search\n9. Size\n10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: csll.insert_at_head(); break;
            case 2: csll.insert_at_end(); break;
            case 3: csll.random_insert(); break;
            case 4: csll.delete_from_head(); break;
            case 5: csll.delete_from_end(); break;
            case 6: csll.random_delete(); break;
            case 7: csll.display(); break;
            case 8: csll.search(); break;
            case 9: cout<<"Size: "<<csll.Size_of_List()<<endl; break;
            case 10: return 0;
            default: cout<<"Invalid choice!\n";
        }
    }
}