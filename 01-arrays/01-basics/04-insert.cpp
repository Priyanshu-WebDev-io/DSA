#include <iostream>
using namespace std;

int main() {
  int arr[6] = {1, 2, 3, 5}; // Max capacity (n) is 6

  int insertAt = 2;
  int insertVal = 6;
  int currSize = 4; // Elements currently in use
  int n = sizeof(arr) / sizeof(arr[0]);

  // 1. Correct Guard Condition: Block execution if full
  if (currSize >= n) {
    cout << "array overflow, we cant do insertion operation" << endl;
    return 0; // Exit early to prevent crashes below!
  }

  // 2. Correct Shifting Loop: Start from the last valid element index
  // Moving elements from i to i + 1 is safe because we verified currSize < n
  for (int i = currSize - 1; i >= insertAt; i--) {
    arr[i + 1] = arr[i];
  }

  // 3. Place the element and increase current size
  arr[insertAt] = insertVal;
  currSize++;

  // 4. Print only up to currSize (the actual elements now stored)
  for (int i = 0; i < currSize; i++) {
    cout << "the element at: " << i << " is: " << arr[i] << endl;
  }

  return 0;
}
