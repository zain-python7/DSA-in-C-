#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Linked {
private:
    Node* head;
   Node* tail;

public:
    Linked() {
        head = NULL;
        tail = NULL;
    }

    void insert_at_head(int val) {
        Node* ptr = new Node(val);
        if(head==NULL){
            head=tail=ptr;
            return;
        }
        ptr->next = head;
        head = ptr;
       
        cout << "value adde at the head" << endl;
    }

    void insert_at_end(int val) {
        Node* ptr = new Node(val);
        if (tail == NULL) {
            head = ptr;
            tail = ptr;
        } else {
            tail->next = ptr;
            tail = ptr;
        }
        cout << "value added at the end" << endl;
    }

    void random_insert(int val1, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != val1) {
            temp = temp->next;
        }
        if (temp != NULL) {
            Node* ptr = new Node(val);
            ptr->next = temp->next;
            temp->next = ptr;
           
        }
    }

    void delete_from_head() {
        if (head == NULL){
            cout<<"it is nul";
        } 
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "the first number is deleted" << endl;
        
    }

    void delete_from_end() {
         if (head == NULL){
            cout<<"it is nul";
        } 
        
        
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
        cout << "the last numbr is delted" << endl;
    }

    void random_delete(int val) {
        if (head == NULL){
            cout<<"it is nul";
        } 
       
        Node* temp = head;
        while (temp->next != NULL && temp->data != val) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            Node* del = temp->next;
            temp->next = del->next;
            if (del == tail) {
                tail = temp;
            }
            delete del;
            cout<<"the number is deleted"<<val<<endl;
        } else {
            cout << "the number  is not found" << endl;
        }
    }

    void search(int val) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "the number is present " << val<< endl;
                return;
            }
            temp = temp->next;
        }
        cout << "the number not found" << endl;
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "nthing to print" << endl;
        } else {
            while (temp != NULL) {
                cout << temp->data << " ,";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Linked list;
    list.insert_at_head(5);
    list.insert_at_end(10);
    list.insert_at_end(15);
    list.random_insert(10, 12);
    list.display();
    list.search(12);
    list.random_delete(10);
    list.display();
    list.delete_from_head();
    list.delete_from_end();
    list.display();
    return 0;
}
