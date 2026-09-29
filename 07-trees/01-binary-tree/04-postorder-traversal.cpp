#include "iostream"
#include <cstddef>
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

void posteorder_traversal(Node *root) {
  if (root == NULL) {
    return;
  }

  posteorder_traversal(root->left);
  posteorder_traversal(root->right);
  cout << root->data << endl;
}

int main() {

  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(arr);

  posteorder_traversal(root);

  return 0;
}