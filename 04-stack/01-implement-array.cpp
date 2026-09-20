#include "iostream"
using namespace std;

class Stack {
private:
  int arr[5];
  int top;

public:
  Stack() { top = -1; }

  void push(int value) {
    if (top == 4) {
      cout << "stack overflow" << endl;
      return;
    }

    top++;
    arr[top] = value;
  }

  void pop() {
    if (top == -1) {
      cout << "no data" << endl;
      return;
    }
    top--;
  }

  int peek() {
    if (top == -1) {
      cout << "no data" << endl;
      return -1;
    }

    return arr[top];
  }

  bool empty() {
    if (top == -1) {
      return true;
    }
    return false;
  }
};

int main() {

  Stack st;

  st.push(1);
  st.push(2);

  cout << st.peek() << endl;

  st.pop();

  cout << st.peek() << endl;

  return 0;
}