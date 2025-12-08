#ifndef PPM_M
#define PPM_M

#include <stdbool.h>
#include <stdint.h>

typedef struct {
  uint16_t r, g, b;
} Pixel;

typedef struct {
  unsigned int rows;
  unsigned int cols;
  unsigned int maxval;

  Pixel **pixels;
} ppmimage;

ppmimage *ppm_readimage(const char *filename);
void ppm_destroyimage(ppmimage *image);
bool ppm_writeimage(const char *filename, ppmimage *image);

void pixel_multiply(Pixel *pixel, int val);
Pixel *image_pixel(ppmimage *image, int row, int col);
ppmimage *copy_image(ppmimage *image);
double pixel_luminance(ppmimage *image, int row, int col);

#endif
