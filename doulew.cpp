#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Doblewlinked {
private:
    Node* head;

public:
    Doblewlinked() {
        head = NULL;
    }

    void insert_at_head(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_at_end(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void random_insert(int val, int pos) {
        Node* newNode = new Node(val);
        Node* temp = head;
        int count = 1;
        while (count < pos - 1 && temp != NULL) {
            temp = temp->next;
            count++;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void delete_from_head() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
    }

    void delete_from_end() {
       
        Node* temp = head;
        
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void random_delete(int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }
      
       
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
            }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        
    }

    void search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "the number is present" << val << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "it is not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "," ;
            temp = temp->next;
        }
        cout << endl;
    }

    int size_of_list() {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
            
        }
        cout<<"size :" <<count<<endl;
        
        return count;
        
    }
};

int main() {
    Doblewlinked link;
    link.insert_at_head(2);
    link.insert_at_head(3);
    link.insert_at_end(4);
    link.insert_at_end(5);
    link.search(4);
    link.display();
    link.delete_from_end();
    link.delete_from_head();
    link.display();
    link.random_delete(4);
    link.random_insert(2,2);
    link.display();
    link.size_of_list();
    link.random_delete(26);
}
