#include "iostream"
#include <cstddef>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

static int idx = -1;

Node *buildTree(vector<int> arr) {

  idx++;

  if (arr[idx] == -1) {
    return NULL;
  }

  Node *root = new Node(arr[idx]);

  root->left = buildTree(arr);
  root->right = buildTree(arr);

  return root;
}

void levelorder(Node *root) {
  queue<Node *> q;

  q.push(root);

  while (q.size() >= 0) {
    Node *curr = q.front();

    q.pop();
    cout << curr->data << endl;

    if (curr->left != NULL) {
      q.push(curr->left);
    }
    if (curr->right != NULL) {
      q.push(curr->right);
    }
  }
}

int main() {

  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(arr);

  levelorder(root);

  return 0;
}