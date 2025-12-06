#include "ppm.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

void grayscale(ppmimage *image) {
  for (int i = 0; i < image->rows; i++) {
    for (int j = 0; j < image->cols; j++) {
      int average = (image->pixels[i][j].r + image->pixels[i][j].g +
                     image->pixels[i][j].b) /
                    3;
      image->pixels[i][j].r = average;
      image->pixels[i][j].g = average;
      image->pixels[i][j].b = average;
    }
  }
}

void colorInversion(ppmimage *image) {
  for (int i = 0; i < image->rows; i++) {
    for (int j = 0; j < image->cols; j++) {
      image->pixels[i][j].r = 255 - image->pixels[i][j].r;
      image->pixels[i][j].g = 255 - image->pixels[i][j].g;
      image->pixels[i][j].b = 255 - image->pixels[i][j].b;
    }
  }
}

void edgeDetection(ppmimage *image, int threshold) {
  // Horizontal Grid
  int Gx[3][3] = {
      {-1, 0, +1},
      {-2, 0, +2},
      {-1, 0, +1},
  };
  // Vertical Grid
  int Gy[3][3] = {
      {+1, +2, +1},
      {0, 0, 0},
      {-1, -2, -1},
  };

  ppmimage *img = copy_image(image);

  // Applying transformation to the pixels;
  for (int imageRow = 0; imageRow < image->rows; imageRow++) {
    for (int imageCol = 0; imageCol < image->cols; imageCol++) {

      double horizontalMag = 0;
      double verticalMag = 0;

      for (int kx = -1; kx <= 1; kx++) {

        int pixelIndexX = imageRow + kx;
        int kernelIndexX = kx + 1; // Cycling between 0 , 1 ,2

        // Skip if Horizontal pixel are outside the image bounds.
        if (pixelIndexX < 0 || pixelIndexX >= image->rows) {
          continue;
        }

        for (int ky = -1; ky <= 1; ky++) {

          int pixelIndexY = imageCol + ky;
          int kernelIndexY = ky + 1; // cycling between 0 , 1 ,2

          // Skip if vertical pixel are outside the image bounds.
          if (pixelIndexY < 0 || pixelIndexY >= image->cols) {
            continue;
          }

          horizontalMag += (pixel_luminance(img, pixelIndexX, pixelIndexY)) *
                           Gx[kernelIndexX][kernelIndexY];
          verticalMag += (pixel_luminance(img, pixelIndexX, pixelIndexY)) *
                         Gy[kernelIndexX][kernelIndexY];
        }
      }

      double TotalMagnitude =
          sqrt((horizontalMag * horizontalMag) + (verticalMag * verticalMag));

      if (TotalMagnitude > threshold) {
        image->pixels[imageRow][imageCol].r = 255;
        image->pixels[imageRow][imageCol].g = 255;
        image->pixels[imageRow][imageCol].b = 255;
      } else {

        image->pixels[imageRow][imageCol].r = 0;
        image->pixels[imageRow][imageCol].g = 0;
        image->pixels[imageRow][imageCol].b = 0;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  // If less than two arguments are given then. print the usage.
  if (argc < 4) {
    printf("Usage: %s <input_file_path>  <output_file_name> -<process_letter> "
           "<optional_threshold_number_value_if_E_is_chosen> \n",
           argv[0]);
    printf("\n-----------------------------------------------------\n");
    printf("-E for sobel's algorithim for edge detection\n");
    printf("-G for grayscale\n");
    printf("-I for color Inversion\n");
    printf("\n-----------------------------------------------------\n");
    return 1;
  }
  // Read the image
  ppmimage *image = ppm_readimage(argv[1]);
  if (image == NULL) {
    perror("Error reading the file ");
    return 1;
  }

  if (strcmp(argv[3], "-E") == 0) {
    int threshold = atoi(argv[4]);
    printf("%d", threshold);

    // Default threshold if not defined;
    if (!threshold) {
      threshold = 200;
    }
    edgeDetection(image, threshold);
  } else if (strcmp(argv[3], "-I") == 0) {
    colorInversion(image);
  } else if (strcmp(argv[3], "-G") == 0) {
    grayscale(image);
  } else {
    printf("Enter a valid argument like -I , -G , -E");
    return 1;
  }

  // Write the image
  ppm_writeimage(argv[2], image);

exit_jump:
  ppm_destroyimage(image);
  return 0;
}
