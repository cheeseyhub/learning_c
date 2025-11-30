#include <stdio.h>

int main() {

  FILE *inputFile;
  inputFile = fopen("./input.txt", "r");

  if (inputFile == NULL ) {
    printf("Error opening the file");
    return 1;
  }


  int ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    printf("%c", ch);
  }

  fclose(inputFile);

  return 0;
}
