#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int arr[5];
public:
    Queue(int s) {
        size = s;
        front = -1;
        rear = -1;
    }

    bool isempty() {
        return (front == -1 || front > rear);
    }

    bool isfull() {
        return (rear == size - 1);
    }

    void enqueue(int val) {
        if (isfull()) {
            cout << "Queue is full. Cannot insert " << val << "." << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            arr[rear] = val;
            cout << "Enqueued: " << val << endl;
        }
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty. Nothing to dequeue." << endl;
        } else {
            cout << "Dequeued: " << arr[front] << endl;
            front++;
        }
    }

    void peak() {
        if (isempty()) {
            cout << "Queue is empty. No peak element." << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue(5);

    queue.enqueue(5);
    queue.enqueue(6);
    queue.dequeue();
    queue.display();
    queue.peak();

    return 0;
}
