#include "math.h"
#include "raylib.h"

struct movementComponent {
  float velocity;
  int up;
  int down;
  int left;
  int right;
};
// Structure of Car

struct Car {
  float posX;
  float posY;
  int width;
  int height;
  Color color;
  struct movementComponent move;
};
void GenericControls(struct movementComponent *o) {
  o->up = IsKeyDown(KEY_UP);
  o->down = IsKeyDown(KEY_DOWN);
  o->left = IsKeyDown(KEY_LEFT);
  o->right = IsKeyDown(KEY_RIGHT);
}
void GenericMovement(struct movementComponent *o, float *posX, float *posY) {
  if (o->up) {
    *posY -= o->velocity;
  }
  if (o->down) {
    *posY += o->velocity;
  }
  if (o->left) {
    *posX -= o->velocity;
  }
  if (o->right) {
    *posX += o->velocity;
  }
}

int main(void) {
  int windowHeight = 1366;
  int windowWidth = 768;

  InitWindow(windowWidth, windowHeight, "raylib [core] example - basic window");

  struct Car car = {
      windowWidth / (float)2, windowHeight / (float)2, 10, 20, BLACK, {0.1}};

  while (WindowShouldClose() == false) {

    GenericControls(&car.move);
    GenericMovement(&car.move, &car.posX, &car.posY);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(car.posX, car.posY, car.width, car.height, car.color);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
