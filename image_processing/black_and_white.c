#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE (16 * 1024 * 1024)

void validate(int val, const char *msg) {
  if (!val) {
    fprintf(stderr, "Invalid file : %s \n");
    exit(1);
  }
}
void check_header(const char *buffer) {
  validate((unsigned char)buffer[0] == 0x89, "header byte 1");
  validate((unsigned char)buffer[1] == 'P', "header byte 2");
}

// Takes two arguments  input file and output file
int main(int argc, char **argv) {

  if (argc != 3) {
    printf("%s <input_file_name> <output_file_name>\n", argv[0]);
    return 0;
  }

  // Allocate memory
  char *buffer = (char *)malloc(MAX_SIZE);

  if (!buffer) {
    fprintf(stderr, "Couldn't Allocate the memory \n");
    return 1;
  }

  // Open the png file
  FILE *png = fopen(argv[1], "r");

  if (png == NULL) {
    fprintf(stderr, "Couldn't open the file");

    if (buffer) {
      free(buffer);
    }
    return 1;
  }

  free(buffer);
  fclose(png);
  return 0;
}
