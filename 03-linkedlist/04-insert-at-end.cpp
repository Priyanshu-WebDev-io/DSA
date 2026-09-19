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

  // New node
  Node *newNode = new Node(4);

  // Find last node
  Node *temp = head;

  while (temp->next != nullptr) {
    temp = temp->next;
  }

  // Insert at end
  temp->next = newNode;

  // Print linked list
  Node *temp2 = head;

  while (temp2 != nullptr) {
    cout << temp2->data << " ";
    temp2 = temp2->next;
  }

  return 0;
}