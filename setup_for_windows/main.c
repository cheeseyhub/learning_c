#include "include/raylib.h"

int main() {

  int windowWidth = 800;
  int windowHeight = 600;

  InitWindow(windowWidth, windowHeight, "This is a title");

  while (WindowShouldClose() == false) {
    ClearBackground(BLACK);

    BeginDrawing();

    EndDrawing();
  }

  return 0;
}
