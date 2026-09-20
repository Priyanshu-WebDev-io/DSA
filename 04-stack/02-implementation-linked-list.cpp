#include "iostream"
#include <cstddef>
using namespace std;

class Stack {
private:
  struct Node {
    int data;
    Node *next;

    Node(int value) {
      data = value;
      next = nullptr;
    }
  };

  Node *top;

public:
  Stack() { top = nullptr; }

  void push(int value) {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
  }

  void pop() {
    if (top == nullptr) {
      cout << "no data" << endl;
      return;
    }

    Node *temp = top;
    top = top->next;
    delete temp;
  }

  int peek() {
    if (top == nullptr) {
      cout << "no data" << endl;
      return -1;
    }

    return top->data;
  }

  bool empty() {
    if (top == nullptr) {
      return true;
    }
    return false;
  }
};

int main() {

  Stack st;

  st.push(1);
  st.push(2);

  cout << st.peek() << endl;

  st.pop();

  cout << st.peek() << endl;

  return 0;
}