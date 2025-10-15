#include "raylib.h"

// Structure of Car

struct Car {
  int posX;
  int posY;
  int width;
  int height;
  Color color;
  int velocity;
  int up;
  int down;
  int left;
  int right;
};
void Carcontrols(struct Car *o) {
  o->up = IsKeyDown(KEY_UP);
  o->down = IsKeyDown(KEY_DOWN);
  o->left = IsKeyDown(KEY_LEFT);

  o->right = IsKeyDown(KEY_RIGHT);
}
void Carmovement(struct Car *o) {
  if (o->up) {
    o->posY -= o->velocity;
  }
  if (o->down) {
    o->posY += o->velocity;
  }
  if (o->left) {
    o->posX -= o->velocity;
  }
  if (o->right) {
    o->posX += o->velocity;
  }
}

// Ball  object
struct ball {
  int centerX;
  int centerY;
  Color color;
  int radius;
  float velocity;
  int up;
  int down;
  int left;
  int right;
};
void controls(struct ball *o) {
  o->up = IsKeyDown(KEY_UP);
  o->down = IsKeyDown(KEY_DOWN);
  o->left = IsKeyDown(KEY_LEFT);

  o->right = IsKeyDown(KEY_RIGHT);
}
void movement(struct ball *o) {
  if (o->up) {
    o->centerY -= o->velocity;
  }
  if (o->down) {
    o->centerY += o->velocity;
  }
  if (o->left) {
    o->centerX -= o->velocity;
  }
  if (o->right) {
    o->centerX += o->velocity;
  }
}

int main(void) {
  int windowHeight = 1366;
  int windowWidth = 768;

  InitWindow(windowWidth, windowHeight, "raylib [core] example - basic window");

  struct Car car = {windowWidth / 2, windowHeight / 2, 10, 20, BLACK, 1};

  while (WindowShouldClose() == false) {

    Carcontrols(&car);
    Carmovement(&car);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(car.posX, car.posY, car.width, car.height, car.color);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
