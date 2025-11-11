#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  // Sorting
  int lengthOfArray = 10;
  int A[lengthOfArray] = {};
  // Giving random values to the array;
  for (int i = 0; i < lengthOfArray; i++) {
    A[i] = rand() % (30 + 1);
  }

  printf("\n[");
  for (int i = 0; i < lengthOfArray; i++) {
    printf("%d, ", A[i]);
  }
  printf("]");

  int flip;
  // Continue flipping  till we flip nothing.
  do {
    // Cosider we are not going to flip anything
    flip = 0;
    for (int i = 0; i < lengthOfArray - 1; i++) {
      if (A[i] > A[i + 1]) {
        int temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
        // Something flipped so loop will continue again
        flip = 1;
      }
    }
  } while (flip != 0);

  printf("\n[");
  for (int i = 0; i < lengthOfArray; i++) {
    printf("%d, ", A[i]);
  }
  printf("]\n");

  return 0;
}
