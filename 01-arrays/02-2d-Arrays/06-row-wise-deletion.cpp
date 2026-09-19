#include "iostream"
using namespace std;

// row wise insertion
int main() {
  const int ROWS = 3;
  const int COLS = 4;

  // Explicit initialization (3 Rows, 4 Columns)
  int matrix[ROWS][COLS] = {
      {10, 20, 30, 40}, // Row 0
      {50, 60, 70, 80}, // Row 1
  };

  cout << "before deletion" << endl;

  // print all the rows
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << endl;
    }
  }

  int del_row = 2;
  int curr_rows = 3;

  // first copy or make space for insertion
  for (int i = del_row - 1; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      matrix[i][j] = matrix[i + 1][j];
    }
  }

  cout << "after deletion" << endl;

  // print all the rows
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << endl;
    }
  }

  return 0;
}