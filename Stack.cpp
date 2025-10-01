#include <iostream>
using namespace std;

class Stack {
    int top, size;
    int arr[5];
public:
    Stack(int s) {
        size = s;
        top = -1;
    }

    bool isempty() {
        return (top == -1);
    }

    bool isfull() {
        return (top == size - 1);
    }

    void push(int val) {
        if (isfull()) {
            cout << "Stack is full You cannot  push " << val << "." << endl;
        } else {
            top++;
            arr[top] = val;
            cout << "Pushed: " << val << endl;
        }
    }

    void pop() {
        if (isempty()) {
            cout << "Stack is empty. Nothing to pop." << endl;
        } else {
            cout << "Popped: " << arr[top] << endl;
            top--;
        }
    }

    void peak() {
        if (isempty()) {
            cout << "Stack is empty. No peak element." << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack(5);

    stack.push(4);
    stack.push(3);
    stack.push(7);
    stack.pop();
    stack.peak();
    stack.display();

    return 0;
}
