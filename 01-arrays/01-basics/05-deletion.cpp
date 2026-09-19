#include <iostream>
using namespace std;

int main() {
  int arr[6] = {1, 2, 3, 5}; // Max capacity (n) is 6

  int deleteAt = 1;
  int currSize = 4; // Elements currently in use
  int n = sizeof(arr) / sizeof(arr[0]);

  if (currSize >= n) {
    cout << "array overflow, we cant do deletion operation" << endl;
    return 0; // Exit early to prevent crashes below!
  }

  for (int i = deleteAt; i < currSize; i++) {
    arr[i] = arr[i + 1];
  }

  currSize--;

  for (int i = 0; i < currSize; i++) {
    cout << "the element at: " << i << " is: " << arr[i] << endl;
  }

  return 0;
}
