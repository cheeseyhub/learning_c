#include "ppm.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

void grayscale(ppmimage *sourceImage) {
  for (int i = 0; i < sourceImage->rows; i++) {
    for (int j = 0; j < sourceImage->cols; j++) {
      int average = (sourceImage->pixels[i][j].r + sourceImage->pixels[i][j].g +
                     sourceImage->pixels[i][j].b) /
                    3;
      sourceImage->pixels[i][j].r = average;
      sourceImage->pixels[i][j].g = average;
      sourceImage->pixels[i][j].b = average;
    }
  }
}

void colorInversion(ppmimage *sourceImage) {
  for (int i = 0; i < sourceImage->rows; i++) {
    for (int j = 0; j < sourceImage->cols; j++) {
      sourceImage->pixels[i][j].r = 255 - sourceImage->pixels[i][j].r;
      sourceImage->pixels[i][j].g = 255 - sourceImage->pixels[i][j].g;
      sourceImage->pixels[i][j].b = 255 - sourceImage->pixels[i][j].b;
    }
  }
}

void edgeDetection(ppmimage *sourceImage, int threshold, int colorRetention) {
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

  ppmimage *img = copy_image(sourceImage);

  // Applying transformation to the pixels;
  for (int imageRow = 0; imageRow < sourceImage->rows; imageRow++) {
    for (int imageCol = 0; imageCol < sourceImage->cols; imageCol++) {

      double horizontalMag = 0;
      double verticalMag = 0;

      for (int kx = -1; kx <= 1; kx++) {

        int pixelIndexX = imageRow + kx;
        int kernelIndexX = kx + 1; // Cycling between 0 , 1 ,2

        // Skip if Horizontal pixel are outside the image bounds.
        if (pixelIndexX < 0 || pixelIndexX >= sourceImage->rows) {
          continue;
        }

        for (int ky = -1; ky <= 1; ky++) {

          int pixelIndexY = imageCol + ky;
          int kernelIndexY = ky + 1; // cycling between 0 , 1 ,2

          // Skip if vertical pixel are outside the image bounds.
          if (pixelIndexY < 0 || pixelIndexY >= sourceImage->cols) {
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
        if (colorRetention == 0) {
          sourceImage->pixels[imageRow][imageCol].r = 255;
          sourceImage->pixels[imageRow][imageCol].g = 255;
          sourceImage->pixels[imageRow][imageCol].b = 255;
        }
      } else {

        sourceImage->pixels[imageRow][imageCol].r = 0;
        sourceImage->pixels[imageRow][imageCol].g = 0;
        sourceImage->pixels[imageRow][imageCol].b = 0;
      }
    }
  }
};
void blur(ppmimage *sourceImage, int scale) {

  ppmimage *img = copy_image(sourceImage);

  // Applying transformation to the pixels;
  for (int imageRow = 0; imageRow < sourceImage->rows; imageRow++) {
    for (int imageCol = 0; imageCol < sourceImage->cols; imageCol++) {

      int pixel_count = 1;

      int pixel_r = 0;
      int pixel_g = 0;
      int pixel_b = 0;

      for (int kx = -scale; kx <= scale; kx++) {

        int pixelIndexX = imageRow + kx;
        int kernelIndexX = kx + 1; // Cycling between 0 , 1 ,2

        // Skip if Horizontal pixel are outside the image bounds.
        if (pixelIndexX < 0 || pixelIndexX >= sourceImage->rows) {
          continue;
        }

        for (int ky = -scale; ky <= scale; ky++) {

          int pixelIndexY = imageCol + ky;
          int kernelIndexY = ky + 1; // cycling between 0 , 1 ,2

          // Skip if vertical pixel are outside the image bounds.
          if (pixelIndexY < 0 || pixelIndexY >= sourceImage->cols) {
            continue;
          }

          pixel_r += img->pixels[pixelIndexX][pixelIndexY].r;
          pixel_g += img->pixels[pixelIndexX][pixelIndexY].g;
          pixel_b += img->pixels[pixelIndexX][pixelIndexY].b;

          pixel_count++;
        }
      }
      pixel_r /= pixel_count;
      pixel_g /= pixel_count;
      pixel_b /= pixel_count;

      sourceImage->pixels[imageRow][imageCol].r = pixel_r;
      sourceImage->pixels[imageRow][imageCol].g = pixel_g;
      sourceImage->pixels[imageRow][imageCol].b = pixel_b;
    }
  }
}

void gaussianBlur(ppmimage *sourceImage) {

  ppmimage *img = copy_image(sourceImage);

  double GAUSSIAN_KERNEL_3X3[3][3] = {
      {0.075, 0.124, 0.075}, {0.124, 0.204, 0.124}, {0.075, 0.124, 0.075}};
  // Applying transformation to the pixels;
  for (int imageRow = 0; imageRow < sourceImage->rows; imageRow++) {
    for (int imageCol = 0; imageCol < sourceImage->cols; imageCol++) {

      double pixel_r = 0;
      double pixel_g = 0;
      double pixel_b = 0;

      for (int kx = -1; kx <= 1; kx++) {

        int pixelIndexX = imageRow + kx;
        int kernelIndexX = kx + 1; // Cycling between 0 , 1 ,2

        // Skip if Horizontal pixel are outside the image bounds.
        if (pixelIndexX < 0 || pixelIndexX >= sourceImage->rows) {
          continue;
        }

        for (int ky = -1; ky <= 1; ky++) {

          int pixelIndexY = imageCol + ky;
          int kernelIndexY = ky + 1; // cycling between 0 , 1 ,2

          // Skip if vertical pixel are outside the image bounds.
          if (pixelIndexY < 0 || pixelIndexY >= sourceImage->cols) {
            continue;
          }

          pixel_r += img->pixels[pixelIndexX][pixelIndexY].r *
                     GAUSSIAN_KERNEL_3X3[kernelIndexX][kernelIndexY];
          pixel_g += img->pixels[pixelIndexX][pixelIndexY].g *
                     GAUSSIAN_KERNEL_3X3[kernelIndexX][kernelIndexY];
          pixel_b += img->pixels[pixelIndexX][pixelIndexY].b *
                     GAUSSIAN_KERNEL_3X3[kernelIndexX][kernelIndexY];
        }
      }
      sourceImage->pixels[imageRow][imageCol].r = round(pixel_r);
      sourceImage->pixels[imageRow][imageCol].g = round(pixel_g);
      sourceImage->pixels[imageRow][imageCol].b = round(pixel_b);
    }
  }
}
int main(int argc, char *argv[]) {
  // If less than two arguments are given then. print the usage.
  if (argc < 4) {

    printf(GREEN
           "\nUsage: %s <input_file_path>  <output_file_name> "
           "-<process_letter> <optional_arguments_for_process_letter>" RESET,
           argv[0]);
    printf("\n-----------------------------------------------------\n");
    printf("-E Sobel's Edge detection algorithim. \n");
    printf("-G  (Simple black and white image conversion)\n");
    printf("-I (Color Inversion algorithim)\n");
    printf("-B (Box blur Algorithim) \n");
    printf("-GB (Gaussian Blur blur Algorithim) \n");
    printf("\n-----------------------------------------------------\n");
    printf("Options for the process letters are listed below.");
    printf("\n-----------------------------------------------------\n");
    printf("-E threshold(int) colorize(1 or 0(default) GaussianBlur(1 or "
           "0(default) \n");
    printf("-G \n");
    printf("-I \n");
    printf("-B blur_amount _int\n");
    printf("-GB\n");
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
    int threshold = 100;
    int colorRetention = 0;
    int blur = 0;
    if (argc > 4) {
      threshold = atoi(argv[4]);
    }
    if (argc > 5) {
      colorRetention = atoi(argv[5]);
    }
    if (argc == 7) {

      blur = atoi(argv[6]);
    }
    if (blur == 1) {
      gaussianBlur(image);
    }
    edgeDetection(image, threshold, colorRetention);

  } else if (strcmp(argv[3], "-I") == 0) {
    colorInversion(image);
  } else if (strcmp(argv[3], "-G") == 0) {
    grayscale(image);
  } else if (strcmp(argv[3], "-B") == 0) {
    int scale = 3;
    if (argc == 5) {
      scale = atoi(argv[4]);
    }
    blur(image, scale);
  } else if (strcmp(argv[3], "-GB") == 0) {
    gaussianBlur(image);
  } else {
    printf("Enter a valid argument like -I , -G , -E, -B,-GB");
    return 1;
  }

  // Write the image
  ppm_writeimage(argv[2], image);

exit_jump:
  ppm_destroyimage(image);
  return 0;
}
