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

  Node *temp = head;

  while (temp->next->next != nullptr) {
    temp = temp->next;
  }

  delete temp->next;
  temp->next = nullptr;

  // Find last node
  Node *temp2 = head;

  while (temp2 != nullptr) {
    cout << temp2->data << " ";
    temp2 = temp2->next;
  }

  return 0;
}