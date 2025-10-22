#include <stdio.h>

int main() {
  int arr1Size, arr2Size;

  printf("Enter the size of set 1:");
  scanf("%d", &arr1Size);

  printf("Enter the size of set 2:");
  scanf("%d", &arr2Size);

  int arr1[arr1Size];
  int arr2[arr2Size];

  // Get values for set 1

  printf("Give values for the first set\n");
  for (int i = 0; i < arr1Size; i++) {
    printf("Give value for %d th index: ", i);
    scanf("%d", &arr1[i]);
  }

  // Get values for set 2;
  printf("Give values for the second set\n");
  for (int i = 0; i < arr2Size; i++) {
    printf("Give value for %d th index: ", i);
    scanf("%d", &arr2[i]);
  }

  // Finding common elements between set 1 and set 2

  int intersection[arr1Size];
  int indexToInsert = 0;

  // Finding also the size of intersection set;
  int intersectionSetSize = 0;
  for (int i = 0; i < arr1Size; i++) {

    for (int j = 0; j < arr2Size; j++) {
      if (arr1[i] == arr2[j]) {

        // Third loop for Checking if the element isn already in the
        // intersection;
        int alreadyInIntersection = 0;
        for (int x = 0; x < i; x++) {

          if (arr1[i] == intersection[x])
            alreadyInIntersection = 1;
        }

        // if not already in array add to the intersection;
        if (!alreadyInIntersection) {
          intersection[indexToInsert] = arr1[i];
          indexToInsert++;
          intersectionSetSize++;
        }
        break;
      }
    }
  }

  // Printing the intersection set;
  //
  printf("\n[");
  for (int i = 0; i < intersectionSetSize; i++) {
    printf("%d,", intersection[i]);
  }
  printf("]");

  return 0;
}
