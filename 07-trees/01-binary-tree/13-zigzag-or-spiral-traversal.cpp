#include <algorithm>
#include <iostream>
#include <queue> // Added for Level-Order Queue
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

// Zigzag Traversal Implementation
void zigzagTraversal(Node *root) {
  if (root == NULL)
    return;

  queue<Node *> q;
  q.push(root);

  bool leftToRight = true; // Flag to track printing direction

  while (!q.empty()) {
    int size = q.size();
    vector<int> row(size);

    for (int i = 0; i < size; i++) {
      Node *node = q.front();
      q.pop();

      // Find position to fill based on current direction
      int index = leftToRight ? i : (size - 1 - i);
      row[index] = node->data;

      if (node->left != NULL)
        q.push(node->left);
      if (node->right != NULL)
        q.push(node->right);
    }

    // Print the current level's row
    for (int val : row) {
      cout << val << " ";
    }

    // Toggle the direction for the next level
    leftToRight = !leftToRight;
  }
  cout << endl;
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

  cout << "Zigzag Traversal: ";
  zigzagTraversal(root); // Expected Output: 1 3 2 4 5

  return 0;
}
