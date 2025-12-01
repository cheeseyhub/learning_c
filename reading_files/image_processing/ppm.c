#include "ppm.h"
#include "fcntl.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

ppmimage *ppm_readimage(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Could not open the file");
    return NULL;
  }
  // get the file size;
  fseek(file, 0, SEEK_END);
  size_t file_size = ftell(file);

  // Get file descriptor
  int file_desc = fileno(file);

  // Go back to the beginning of the file
  rewind(file);

  ppmimage *result = malloc(sizeof *result);

  // Get the first letters to see if this is a ppm image;
  char type[3] = {0};
  fscanf(file, "%2s", type);

  if (strcmp(type, "P6") != 0) {
    perror("Not a ppm image");
    fclose(file);
    return NULL;
  }

  fscanf(file, "%u %u", &(result->cols), &(result->rows));
  fscanf(file, "%u", &(result->maxval));
  off_t offset = ftell(file);
};
void ppm_destroyimage(ppmimage *image) {

};
bool ppm_writeimage(const char *filename, ppmimage *image) {

};
