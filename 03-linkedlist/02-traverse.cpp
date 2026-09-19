#include <iostream>
using namespace std;

int main() {

  struct Node {
    int data;
    Node *next;

    Node(int value) {
      data = value;
      next = nullptr;
    }
  };

  Node *first = new Node(0);
  Node *second = new Node(1);
  Node *third = new Node(2);

  first->next = second;
  second->next = third;

  Node* temp = first;

  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}