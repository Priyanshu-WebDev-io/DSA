#include <iostream>
using namespace std;

int main() {
  int arr[6] = {1, 2, 3, 5}; // Max capacity (n) is 6

  int val = 3;
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n; i++) {
    if (arr[i] == val) {
      return i;
    };
  }

  return 0;
}
