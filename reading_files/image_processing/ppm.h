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

#endif
