#include <iostream>
#include <ratio>
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

  Node *curr = head;
  Node *prev = nullptr;

  while (curr->next != nullptr) {
    Node *next = curr->next;

    curr->next = prev;

    prev = curr;
    curr = next;
  }

  head = prev;

  Node *temp = head;

  while (temp->next != nullptr) {
    cout << temp->data;
    temp = temp->next;
  }

  return 0;
}