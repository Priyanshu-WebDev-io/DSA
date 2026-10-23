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

static int ans = 0;

int diameter(Node *root) {

  if (root == NULL) {
    return 0;
  }

  int left = diameter(root->left);
  int right = diameter(root->right);

  int totl = left + right;

  if (totl > ans) {
    ans = totl;
  }

  return max(left, right) + 1;
}

int main() {

  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(arr);

  int h = diameter(root);

  cout << h << endl;

  return 0;
}