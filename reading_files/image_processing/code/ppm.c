#include "ppm.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline Pixel *image_pixel(ppmimage *image, int row, int col) {
  return &((Pixel *)image->pixels)[col * image->cols + row];
}

ppmimage *ppm_readimage(const char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    perror("Could not open the file");
    return NULL;
  }
  // get the file size;
  fseek(file, 0, SEEK_END);
  size_t file_size = ftell(file);

  // Go back to the beginning of the file
  rewind(file);

  // Get the first two letters to see if this is a  p6 ppm image;
  char type[3] = {0};
  fscanf(file, "%2s", type);

  if (strcmp(type, "P6") != 0) {
    perror("Not a ppm image");
    fclose(file);
    return NULL;
  }

  ppmimage *result = malloc(sizeof *result);

  // Write the number of cols and rows in the ppmimage struct
  fscanf(file, "%u %u", &(result->cols), &(result->rows));

  // Write the max value of pixels
  fscanf(file, "%u", &(result->maxval));

  fgetc(file); // Remove white space in header;
  size_t offset = ftell(file);

  // Exclude the header from the size;
  size_t pixelsSize = file_size - offset;

  // Allocate the memory and then write the file into the memeory;
  uint8_t *pixelData = malloc(pixelsSize);

  fread(pixelData, pixelsSize, 1, file);

  if (pixelData == NULL) {
    perror("Failed to allocate memory for the file");
    fclose(file);
    free(result);
    return NULL;
  }
  const int values_per_pixel = 3;

  result->pixels = calloc(result->rows, sizeof(Pixel *));
  for (int i = 0; i < result->rows; i++) {
    result->pixels[i] = calloc(result->cols, sizeof(Pixel));
    for (int j = 0; j < result->cols; j++) {
      uint8_t *pixel_start =
          pixelData + (i * result->cols + j) * values_per_pixel;
      result->pixels[i][j].r = pixel_start[0];
      result->pixels[i][j].g = pixel_start[1];
      result->pixels[i][j].b = pixel_start[2];
    }
  }

  fclose(file);
  free(pixelData);
  return result;
};
void ppm_destroyimage(ppmimage *image) {
  for (int x = 0; x < image->rows; x++) {
    free(image->pixels[x]);
  }
  free(image);
};
bool ppm_writeimage(const char *filename, ppmimage *image) {

  FILE *outputfile = fopen(filename, "wb");

  if (outputfile == NULL) {
    perror("Failed to open file");
    return false;
  }

  fprintf(outputfile, "P6\n%u %u\n%u\n", image->cols, image->rows,
          image->maxval);

  const int values_per_pixel = 3;

  for (int row = 0; row < image->rows; row++) {
    for (int col = 0; col < image->cols; col++) {
      fwrite(&(image->pixels[row][col].r), 1, 1, outputfile);
      fwrite(&(image->pixels[row][col].g), 1, 1, outputfile);
      fwrite(&(image->pixels[row][col].b), 1, 1, outputfile);
    }
  }
  fclose(outputfile);
  return true;
};
void pixel_multiply(Pixel *pixel, int val) {
  pixel->r *= val;
  pixel->g *= val;
  pixel->b *= val;
}
ppmimage *copy_image(ppmimage *image) {
  ppmimage *img = (ppmimage *)malloc(sizeof(ppmimage));
  if (img == NULL) {
    perror("Could not allocate memory");
  }
  img->maxval = image->maxval;
  img->rows = image->rows;
  img->cols = image->cols;

  img->pixels = (Pixel **)calloc(image->rows, sizeof(Pixel *));

  for (int row = 0; row < image->rows; row++) {
    img->pixels[row] = calloc(image->cols, sizeof(Pixel));

    memcpy(img->pixels[row], image->pixels[row], image->cols * sizeof(Pixel));
  }
  return img;
}
double pixel_luminance(ppmimage *image, int row, int col) {
  int red = image->pixels[row][col].r;
  int green = image->pixels[row][col].g;
  int blue = image->pixels[row][col].b;

  return 0.299 * red + 0.587 * green + 0.114 * blue;
}
