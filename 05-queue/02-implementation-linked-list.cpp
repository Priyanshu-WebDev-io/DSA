#include <iostream>
using namespace std;

class Queue {

    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* front;
    Node* rear;

public:

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue
    void enqueue(int value) {

        Node* newNode = new Node(value);

        // Queue is empty
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue
    void dequeue() {

        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;

        front = front->next;

        // Queue became empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Get front element
    int peek() {

        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    // Check empty
    bool empty() {
        return front == nullptr;
    }
};

int main() {

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;  // 10

    q.dequeue();

    cout << q.peek() << endl;  // 20

    q.dequeue();

    cout << q.peek() << endl;  // 30

    return 0;
}