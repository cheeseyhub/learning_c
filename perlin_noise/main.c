#include "include/raylib.h"
#include "stdio.h"
#include <math.h>
#include <stdlib.h>

int chance() { return rand() % 10; }
float randf() {

  int neg = chance() > 5 ? 1 : -1;

  return neg * ((float)rand() / (float)RAND_MAX);
}

int main() {

  int windowWidth = 600;
  int windowHeight = 600;

  int scale = 5;

  int rows = windowWidth / scale;
  int cols = windowHeight / scale;
  int gap = 2;

  InitWindow(windowWidth, windowHeight, "Perlin noise");

  Vector2 vectorMatrix[rows][cols];
  // Filling the vectorMatrix with random values between -1 and 1;
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      vectorMatrix[row][col] = {randf(), randf()};
    }
  }
  while (!WindowShouldClose()) {
    ClearBackground(BLACK);
    BeginDrawing();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
