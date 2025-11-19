#include "include/raylib.h"

int main() {

  int windowWidth = 1366;
  int windowHeight = 768;
  InitWindow(windowWidth, windowHeight, "This is a title");

  while (WindowShouldClose() == false) {

    ClearBackground(BLACK);

    BeginDrawing();

    EndDrawing();
  }

  return 0;
}
