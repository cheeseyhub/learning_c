#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rn() { return rand() % 10; }
void printMatrix(double matrix[][4], int rows) {

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < 4; col++) {

      printf("| %.1f | ", matrix[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}

void addMatrix(double MatrixA[][4], double MatrixB[][4], int rows) {

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < 4; col++) {

      printf("| %.1f | ", MatrixA[row][col] + MatrixB[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}

void subMatrix(double MatrixA[][4], double MatrixB[][4], int rows) {

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < 4; col++) {

      printf("| %.1f | ", MatrixA[row][col] - MatrixB[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}
void multMatrix(double MatrixA[][4], double MatrixB[][4], int rows) {

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < 4; col++) {

      printf("| %.1f | ", MatrixA[row][col] * MatrixB[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}
void divideMatrix(double MatrixA[][4], double MatrixB[][4], int rows) {

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < 4; col++) {

      printf("| %.1f | ", MatrixA[row][col] / MatrixB[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}
int main() {
  srand(time(NULL));

  double MatrixA[4][4] = {
      {rn(), rn(), rn(), rn()},
      {rn(), rn(), rn(), rn()},
      {rn(), rn(), rn(), rn()},
      {rn(), rn(), rn(), rn()},
  };

  printMatrix(MatrixA, 4);

  double MatrixB[4][4] = {
      {rn(), rn(), rn(), rn()},
      {rn(), rn(), rn(), rn()},
      {rn(), rn(), rn(), rn()},
      {rn(), rn(), rn(), rn()},
  };
  printMatrix(MatrixB, 4);

  printf("+ , - , *, / \n");
  printf("Tell the operator : ");
  char operator;
  scanf("%c", &operator);

  switch (operator) {
  case '+':
    addMatrix(MatrixA, MatrixB, 4);
    break;
  case '-':
    subMatrix(MatrixA, MatrixB, 4);
    break;
  case '*':
    multMatrix(MatrixA, MatrixB, 4);
    break;
  case '/':
    divideMatrix(MatrixA, MatrixB, 4);
    break;
  default:
    printf("\n Invalid operator \n");
    break;
  }
  return 0;
}
