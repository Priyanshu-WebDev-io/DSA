#include "iostream"
#include <algorithm>
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

int sum(Node *root) {
  if (root == NULL) {
    return 0;
  }

  int left = sum(root->left);
  int right = sum(root->right);

  return left + right + root->data;
}

int main() {

  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(arr);

  int s = sum(root);

  cout << s << endl;
  return 0;
}