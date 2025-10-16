#include "./Generics.h"
#include <raylib.h>

// Structure of Car
struct Car {
  float posX;
  float posY;
  int width;
  int height;
  Color color;
  struct movementComponent move;
};

int main(void) {
  int windowWidth = 1366;
  int windowHeight = 768;

  InitWindow(windowWidth, windowHeight, "Game");

  struct Car car = {
      windowWidth / (float)2, windowHeight / (float)2, 10, 20, BLACK,
      {.velocity = 0.2}};

  float deltaTime = GetFrameTime();
  while (WindowShouldClose() == false) {

    GenericControls(&car.move);
    GenericMovement(&car.move, &car.posX, &car.posY, &deltaTime);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(car.posX, car.posY, car.width, car.height, car.color);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
