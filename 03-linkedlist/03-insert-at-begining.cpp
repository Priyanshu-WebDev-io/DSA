// insert at begining
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

  Node *newNode = new Node(0);
  newNode->next = head;

  Node *temp = newNode;

  while (temp != nullptr) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  return 0;
}