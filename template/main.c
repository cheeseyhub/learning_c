#include "include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui-4.0/src/raygui.h"

int main() {

  int windowWidth = 700;
  int windowHeight = 600;

  InitWindow(windowWidth, windowHeight, "Edit as you like it .");

  while (!WindowShouldClose()) {
    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    BeginDrawing();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
