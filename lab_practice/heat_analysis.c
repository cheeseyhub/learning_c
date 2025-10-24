#include <stdio.h>

int main() {

  int countOptimal = 0;
  int averageOfCycles = 0;

  int overheated = 0;
  for (int cycle = 0; cycle < 4; cycle++) {

    int temp1;
    printf("Give first reading: ");
    scanf("%d", &temp1);

    int temp2;
    printf("Give second reading: ");
    scanf("%d", &temp2);

    int temp3;
    printf("Give third reading: ");
    scanf("%d", &temp3);

    printf("\n ------------------- \n");

    int averageTemp = (temp1 + temp2 + temp3) / 3;

    averageOfCycles += averageTemp;
    printf("Average temperature is: %d\n", averageTemp);

    if (averageTemp < 750) {
      printf("Underheated \n");
    } else if (averageTemp > 750 && averageTemp < 850) {
      printf("Optimal \n");
      countOptimal++;
    } else {
      printf("overheated \n");
      overheated++;
    }
  }
  averageOfCycles /= 4;
  printf("Optimal temperature count is %d", countOptimal);

  if (averageOfCycles > 1000 || overheated > 0) {
    printf("\n Process instability detected \n");
  }
  return 0;
}
