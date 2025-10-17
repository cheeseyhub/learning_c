#include "./Generics.h"
#include <raylib.h>
#include <rlgl.h>

// Structure of Car
typedef struct {
  float posX;
  float posY;
  int width;
  int height;
  Color color;
  struct movementComponent move;
  float rotation;
} Car;

int main(void) {
  int windowWidth = 1366;
  int windowHeight = 768;

  InitWindow(windowWidth, windowHeight, "Game");
  Image pickachue = LoadImage("./textures/pickachue.png");
  ImageResize(&pickachue, 50, 50);
  Texture2D pickachueTexture = LoadTextureFromImage(pickachue);

  Car car = {windowWidth / (float)2,
             windowHeight / (float)2,
             10,
             20,
             BLACK,
             {.velocity = 100},
             0};

  while (WindowShouldClose() == false) {
    float deltaTime = GetFrameTime();

    GenericControls(&car.move);
    GenericMovement(&car.move, &car.posX, &car.posY, &deltaTime, &car.rotation);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    rlPushMatrix();

    rlTranslatef(car.posX + car.width / 2.0f, car.posY + car.height / 2.0f,
                 0.0f);
    rlRotatef(car.rotation, 0.0f, 0.0f, 1.0f);

    DrawRectangle(-car.width / 2, -car.height / 2, car.width, car.height,
                  car.color);
    DrawTexture(pickachueTexture, 100, 100, WHITE);

    rlPopMatrix();
    EndDrawing();
  }

  UnloadImage(pickachue);
  CloseWindow();

  return 0;
}
