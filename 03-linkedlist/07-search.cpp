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

  Node *head = new Node(1);
  Node *first = new Node(2);
  Node *second = new Node(3);

  head->next = first;
  first->next = second;

  int val = 2;

  Node *temp = head;

  while (temp->next != nullptr) {
    if (temp->data == val) {
      cout << "found" << endl;
      break;
    }

    temp = temp->next;
  }

  return 0;
}