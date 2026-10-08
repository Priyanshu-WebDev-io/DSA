#include <cstddef>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};

bool isSameTree(Node *tree1, Node *tree2) {
  if (tree1 == NULL || tree2 == NULL) {
    return tree1 == tree2;
  }

  bool isLeftSame = isSameTree(tree1->left, tree2->left);
  bool isRightSame = isSameTree(tree1->right, tree2->right);

  return isRightSame && isLeftSame && tree1->data == tree2->data;
}