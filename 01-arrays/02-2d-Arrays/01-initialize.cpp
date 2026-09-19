#include "iostream"
using namespace std;

int main() {
  const int ROWS = 3;
  const int COLS = 4;

  // Explicit initialization (3 Rows, 4 Columns)
  int matrix[ROWS][COLS] = {
      {10, 20, 30, 40},   // Row 0
      {50, 60, 70, 80},   // Row 1
      {90, 100, 110, 120} // Row 2
  };

  return 0;
}