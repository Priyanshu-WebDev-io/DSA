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

  cout << "before insertion" << endl;

  // print all the rows
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << endl;
    }
  }

  int row[COLS] = {90, 100, 110, 120};
  int row_i = 1;
  int curr_rows = 2;

  // first copy or make space for insertion
  for (int i = curr_rows - 1; i >= row_i; i--) {
    for (int j = 0; j < COLS; j++) {
      matrix[i + 1][j] = matrix[i][j];
    }
  }

  // now update the values at desired row
  for (int i = 0; i < COLS; i++) {
    matrix[row_i][i] = row[i];
  }

  cout << "after insertion" << endl;

  // print all the rows
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      cout << matrix[i][j] << endl;
    }
  }

  return 0;
}