#include "iostream"
using namespace std;

// element wise insertion
int main() {
  const int ROWS = 3;
  const int COLS = 4;

  // Explicit initialization (3 Rows, 4 Columns)
  int matrix[ROWS][COLS] = {
      {10, 20, 30, 40}, // Row 0
      {50, 60, 80, 90}, // Row 1
      {100, 110, 120}   // row 2
  };

  cout << "before insertion" << endl;

  // print all the rows
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << endl;
    }
  }

  int row_i = 1;
  int col_i = 2;
  int val = 43;
  int curr_rows = 3;

  // first copy or make space for insertion
  for (int i = curr_rows - 1; i >= row_i; i--) {
    for (int j = COLS - 1; j > 0; j--) {
      if (i != row_i && j != col_i) {
        matrix[i][j] = matrix[i][j - 1];
      }
    }
  }

  matrix[row_i][col_i] = val;

  cout << "after insertion" << endl;

  // print all the rows
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << endl;
    }
  }

  return 0;
}