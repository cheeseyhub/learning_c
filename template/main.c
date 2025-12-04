#include "include/config.h"
#include "include/raylib.h"
#include "include/raymath.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui-4.0/src/raygui.h"

int main() {

  int windowWidth = 700;
  int windowHeight = 600;

  InitWindow(windowWidth, windowHeight, "Edit as you like it .");

  while (!WindowShouldClose()) {
    ClearBackground(BLACK);

    BeginDrawing();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
