#include <algorithm>
#include <iostream>
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

Node *buildTree(const vector<int> &arr) {
  idx++;

  if (arr[idx] == -1) {
    return NULL;
  }

  Node *root = new Node(arr[idx]);
  root->left = buildTree(arr);
  root->right = buildTree(arr);

  return root;
}

// Helper: Checks if a node is a leaf node
bool isLeaf(Node *node) { return (node->left == NULL && node->right == NULL); }

// 1. Collect Left Boundary (excluding leaves)
void addLeftBoundary(Node *root, vector<int> &res) {
  Node *curr = root->left;
  while (curr) {
    if (!isLeaf(curr))
      res.push_back(curr->data);
    if (curr->left)
      curr = curr->left;
    else
      curr = curr->right;
  }
}

// 2. Collect All Leaves (Left to Right)
void addLeaves(Node *root, vector<int> &res) {
  if (root == NULL)
    return;
  if (isLeaf(root)) {
    res.push_back(root->data);
    return;
  }
  addLeaves(root->left, res);
  addLeaves(root->right, res);
}

// 3. Collect Right Boundary in Reverse (excluding leaves)
void addRightBoundary(Node *root, vector<int> &res) {
  Node *curr = root->right;
  vector<int> temp; // Use temporary storage to reverse later
  while (curr) {
    if (!isLeaf(curr))
      temp.push_back(curr->data);
    if (curr->right)
      curr = curr->right;
    else
      curr = curr->left;
  }
  // Add elements in reverse order to get bottom-up trajectory
  for (int i = temp.size() - 1; i >= 0; --i) {
    res.push_back(temp[i]);
  }
}

// Main Boundary Traversal function
vector<int> boundaryTraversal(Node *root) {
  vector<int> res;
  if (root == NULL)
    return res;

  // Add root node if it's not a leaf
  if (!isLeaf(root)) {
    res.push_back(root->data);
  }

  addLeftBoundary(root, res);
  addLeaves(root, res);
  addRightBoundary(root, res);

  return res;
}

int main() {
  // Tree structure:
  //     1
  //    / \
  //   2   3
  //      / \
  //     4   5
  vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

  Node *root = buildTree(arr);

  vector<int> boundary = boundaryTraversal(root);

  cout << "Boundary Traversal: ";
  for (int val : boundary) {
    cout << val << " ";
  }
  cout << endl; // Expected Output: 1 2 4 5 3

  return 0;
}
