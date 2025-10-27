#include <stdio.h>
int main() {
  // Task 1 pattern 1;
  printf("-------------");
  printf("\nPattern 1 \n");
  printf("\n");

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      printf("*");
    }
    printf("\n");
  }

  // Task 1 pattern 2;
  printf("-------------");
  printf("\n Pattern 2");
  printf("\n");

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }
  // Task 1 pattern 3;
  printf("-------------");
  printf("\nPattern 3 \n");
  printf("\n");

  for (int i = 0; i < 10; i++) {
    int spaces = 10 - i;
    for (int j = 0; j < spaces; j++) {
      printf(" ");
    }
    for (int x = 0; x < 10 - spaces; x++) {
      printf("*");
    }
    printf("\n");
  }
  // Task 1 pattern 4;
  printf("-------------");
  printf("\nPattern 4 \n");
  printf("\n");

  for (int i = 0; i < 10; i++) {

    for (int star = 0; star < 10 - i; star++) {
      printf("*");
    }

    printf("\n");
  }

  // Task 1 pattern 5;
  printf("-------------");
  printf("\nPattern 5 \n");
  printf("\n");

  for (int i = 0; i < 10; i++) {
    int spaces = i;

    for (int j = 0; j < spaces; j++) {
      printf(" ");
    }

    for (int x = 0; x < 10 - spaces; x++) {
      printf("*");
    }
    printf("\n");
  }
  // Task 1 pattern 6;
  printf("-------------");
  printf("\nPattern 6 \n");
  printf("\n");
  int length = 16;
  for (int i = 0; i < length; i++) {
    if (i < 3 || i % 2 == 0) {
      for (int spaces = 0; spaces < length - i; spaces++) {
        printf(" ");
      }
      for (int star = 0; star < i; star++) {
        printf("* ");
      }

      printf("\n");
    }
  }
}
