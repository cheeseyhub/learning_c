#include <stdio.h>

/* function that takes size of array takes index of the element to delete
 then decreases the size of array by shifting all the elements to the right
 of element back by one index */
void del(int *array, int index, int *arraySize) {
  for (int i = index; i < *(arraySize); i++) {
    array[i] = array[i + 1];
  }
  *arraySize -= 1;
}
int main() {
  int arraySize = 7;
  int array[arraySize] = {};
  array[0] = 5;
  array[1] = 1000;
  array[2] = 50000;

  // print the above array
  printf("Before \n");
  for (int i = 0; i < 7; i++) {
    printf("%d\n", array[i]);
  }

  del(array, 0, &arraySize);
  del(array, 1, &arraySize);
  del(array, 2, &arraySize);

  printf(" \n After \n ");
  printf("Array size is %d \n", arraySize);
  for (int i = 0; i < arraySize; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}
