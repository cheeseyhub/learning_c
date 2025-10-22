#include <stdio.h>

int main() {
  int set_1_size, set_2_size;

  printf("Enter the size of set 1:");
  scanf("%d", &set_1_size);

  printf("Enter the size of set 2:");
  scanf("%d", &set_2_size);

  int set_one[set_1_size];
  int set_two[set_2_size];

  // Get values for set 1

  printf("Give values for the first set\n");
  for (int i = 0; i < set_1_size; i++) {
    printf("Give value for %d th index: ", i);
    scanf("%d", &set_one[i]);
  }

  // Get values for set 2;
  printf("Give values for the second set\n");
  for (int i = 0; i < set_2_size; i++) {
    printf("Give value for %d th index: ", i);
    scanf("%d", &set_two[i]);
  }

  // Set union set as one set as the initial set;
  int unionSetSize = set_1_size + set_2_size;

  int unionSet[unionSetSize] = {};

  // Put values of set_one in union set;

  for (int i = 0; i < set_1_size; i++) {
    unionSet[i] = set_one[i];
  }

  int next_index = set_1_size;

  int included_flag;
  for (int i = 0; i < set_2_size; i++) {
    included_flag = 0;
    for (int j = 0; j < unionSetSize; j++) {
      if (set_two[i] == unionSet[j]) {
        included_flag = 1;
      }
    }
    if (included_flag == 0) {
      unionSet[next_index] = set_two[i];
      next_index++;
    }
  }

  // Print the union set
  for (int i = 0; i < set_1_size + set_2_size; i++) {
    printf("%d ", unionSet[i]);
  }

  return 0;
}
