#include "include/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui-4.0/src/raygui.h"

// Window Width and Height;
int windowWidth = 400;
int windowHeight = 500;

void calculatorLayout(Rectangle topPanel, Rectangle buttonDesign) {
  // Drawing the top panel.
  GuiTextBox(topPanel, "", 50, true);

  int buttonNumber = 0;
  for (int row = 0; row <= 3; row++) {
    // Button number
    int rowGap = 3;
    buttonDesign.y =
        topPanel.height + (200) + (buttonDesign.height * row) + (row * rowGap);

    for (int col = 0; col <= 3; col++) {
      int gap = 10;
      buttonDesign.x = ((buttonDesign.width + gap) * (col));
      GuiButton(buttonDesign, TextFormat("%d", buttonNumber));
      buttonNumber++;
    }
  }
}

int main() {

  InitWindow(windowWidth, windowHeight, "Edit as you like it .");

  Rectangle topPanel = {0, 0, 400, 100};
  Rectangle buttonDesign = {0, 0, 60, 40};

  while (!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
    calculatorLayout(topPanel, buttonDesign);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
