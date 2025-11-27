#include "include/raylib.h"
#include <stdlib.h>
#include <time.h>

double random_() {
  // Generates random value between 0 and 1;
  return (random() % 10) / 10.0;
};

int main() {

  srand(time(NULL));
  int windowWidth = 1366;
  int windowHeight = 768;

  int gap = 3;

  InitWindow(windowWidth, windowHeight, "Perlin noise");

  ClearBackground(BLACK);

  while (!WindowShouldClose()) {
    BeginDrawing();

    for (int i = 0; i < windowWidth; i += gap) {
      for (int j = 0; j < windowHeight; j += gap) {
        DrawCircle(
            i, j, 1,
            (Color){random_() * 100, random_() * 100, random_() * 100, 255});
      }
    }
    EndDrawing();
  }
  CloseWindow();

  return 0;
}
