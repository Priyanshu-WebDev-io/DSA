#include "iostream"
using namespace std;

// element wise insertion
int main() {
  const int ROWS = 3;
  const int COLS = 4;

  // Explicit initialization (3 Rows, 4 Columns)
  int matrix[ROWS][COLS] = {
      {10, 20, 30, 40},    // Row 0
      {50, 60, 80, 90},    // Row 1
      {100, 110, 120, 130} // row 2
  };

  cout << "before deletion" << endl;

  // print all the rows
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << endl;
    }
  }

  int row_i = 1;
  int col_i = 2;

  // first copy or make space for insertion
  for (int i = row_i; i < ROWS; i++) {
    for (int j = col_i; j < COLS; j++) {
      matrix[i][j] = matrix[i][j + 1];
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