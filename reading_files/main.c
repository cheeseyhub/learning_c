#include <stdio.h>

int main() {
  int errorValue = 0;
  FILE *inputFile;
  FILE *outputFile;
  inputFile = fopen("./input.txt", "r");
  outputFile = fopen("./output.txt", "w+");

  if (inputFile == NULL) {
    printf("Error opening the file");
    errorValue = 1;
    goto end;
  }

  if (outputFile == NULL) {
    printf("Error opening the outputFile");
    errorValue = 1;
    goto end;
  }

  char word[50];
  int count = 0;
  while ((fgets(word, sizeof(word), inputFile))) {
    printf("%s", word);
    fputs(word, outputFile);
  }

end:
  fclose(inputFile);
  fclose(outputFile);

  return errorValue;
}
