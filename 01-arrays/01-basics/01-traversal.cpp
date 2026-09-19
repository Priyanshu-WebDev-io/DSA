#include <iostream>
using namespace std;

int main() {
  int arr[6] = {1, 2, 3, 5, 6, 9};

  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n; i++) {
    cout << "the element at: " << i << " is: " << arr[i] << endl;
  }

  return 0;
}
