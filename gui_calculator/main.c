#include "include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui-4.0/src/raygui.h"

int main() {

  int windowWidth = 1366;
  int windowHeight = 768;

  InitWindow(windowWidth, windowHeight, "Edit as you like it .");

  bool showMessageBox = false;

  while (!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

    if (GuiButton((Rectangle){24, 24, 120, 30}, "#200#Show Message")) {
      showMessageBox = true;
    }
    // Render the message box inside of messagebox
    if (showMessageBox) {
      int result =
          GuiMessageBox((Rectangle){100, 100, 400, 500}, "#191#MessageBox",
                        "This is a message", "Nice;Cool");
      if (result >= 0) {
        showMessageBox = false;
      }
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
