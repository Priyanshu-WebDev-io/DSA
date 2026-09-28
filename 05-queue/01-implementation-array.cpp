#include "iostream"
using namespace std;

class Queue {
private:
  int arr[5];
  int front;
  int rear;

public:
  Queue() {
    front = 0;
    rear = -1;
  }
  void enqueue(int value) {
    if (rear == 4) {
      cout << "stack overflow" << endl;
      return;
    }
    rear++;
    arr[rear] = value;
  }

  void dequeue() {
    if (rear == -1) {
      cout << "no data " << endl;
      return;
    }
    front++;
  }

  int peek() {
    if (rear == -1) {
      return -1;
    }
    return arr[front];
  }

  bool empty() {
    if (rear == -1) {
      return true;
    }
    return false;
  }
};

int main() {

  Queue qu;

  qu.enqueue(1);
  qu.enqueue(2);
  qu.enqueue(3);

  cout << qu.peek() << endl;

  qu.dequeue();

  cout << qu.peek() << endl;

  return 0;
}