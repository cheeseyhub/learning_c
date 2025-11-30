#include "include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui-4.0/src/raygui.h"

int main() {

  int windowWidth = 1366;
  int windowHeight = 768;


  InitWindow(windowWidth, windowHeight, "Edit as you like it .");

  while (!WindowShouldClose()) {
    ClearBackground(BLACK);
    BeginDrawing();
    
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
