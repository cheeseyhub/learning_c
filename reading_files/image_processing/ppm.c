#include "ppm.h"
#include "fcntl.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/mman.h"
#include <stdint.h>

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
  fgetc(file);
  off_t offset = ftell(file);

  uint8_t *rawData =mmap(NULL,file_size,PROT_READ,MAP_PRIVATE,file_desc,0);

  if(rawData == MAP_FAILED)
  {
      perror("Memory Map Failed.");
      fclose(file);
      free(result);
      return NULL;
  }
  uint8_t bytes_per_value= (result->maxval > 256 ? 2: 1);
  const int values_per_pixel = 3;

  uint8_t *pixelData = rawData + offset ;
  result->pixels = calloc(result->rows,sizeof(Pixel*));
  for(int y = 0 ; y <result->rows; y++)
  {
      result->pixels[y] = calloc(result->cols,sizeof(Pixel));
      for(int x = 0; x < result->cols;x++)
      {
          uint8_t *pixel_start = pixelData + (y * result->cols * values_per_pixel * bytes_per_value) + (x *values_per_pixel * bytes_per_value);
          if(bytes_per_value == 1)
          {
              result->pixels[y][x].r = pixel_start[0];
              result->pixels[y][x].g = pixel_start[1];
              result->pixels[y][x].b = pixel_start[2];
          }
          else {
              result->pixels[y][x].r = (pixel_start[0] << 8) | pixel_start[1];
              result->pixels[y][x].g = (pixel_start[2] << 8) | pixel_start[3];
              result->pixels[y][x].b = (pixel_start[4] << 8) | pixel_start[5];

          }
      }
  }


  if(munmap(rawData, file_size) == -1 ){
      perror("Error unmapping the data");
  }
  fclose(file);
  return result;
};
void ppm_destroyimage(ppmimage *image) {
    for(int x = 0 ; x <image->rows;x++)
    {
       free(image->pixels[x]) ;
    }
    free(image);

};
bool ppm_writeimage(const char *filename, ppmimage *image) {

   FILE *outputfile = fopen(filename,"wb");

   if(outputfile == NULL)
   {
       perror("Failed to open file");
       return false;
   }

   fprintf(outputfile,"P6\n%u %u\n%u\n",image->cols,image->rows,image->maxval);

   uint8_t bytes_per_value = (image->maxval > 256 ? 2: 1);
   const int values_per_pixel = 3;

   for(int row = 0  ; row <image->rows;row++)
   {
       for(int col = 0 ; col <image->cols;col++)
       {
           fwrite(&(image->pixels[row][col].r),bytes_per_value,1,outputfile);
           fwrite(&(image->pixels[row][col].g),bytes_per_value,1,outputfile);
           fwrite(&(image->pixels[row][col].b),bytes_per_value,1,outputfile);
       }
   }
   fclose(outputfile);
   return true;
};
