#include <stdio.h>

int main() {

  char sentence[10];

  if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
    printf("Error reading input");
    return 1;
  }

  printf("%s\n", sentence);
  return 0;
}
