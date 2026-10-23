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

static int maxi = 0;

int maxSum(Node *root) {

  if (root == NULL) {
    return 0;
  }

  int left = maxSum(root->left);
  int right = maxSum(root->right);

  maxi = max(maxi, left + right + root->data);

  return root->data + max(left, right);
}

int main() {

  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(arr);

  int h = maxSum(root);

  cout << maxi << endl;

  return 0;
}