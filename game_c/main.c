#include "./Generics.h"
#include "./utility.h"
#include <math.h>
#include <raylib.h>
#include <rlgl.h>
#include <stdlib.h>

typedef struct {
  float posX;
  float posY;
  int width;
  int height;
  Color color;
  struct movementComponent move;
  float rotation;
} Position;

int main(void) {
  int windowWidth = 1366;
  int windowHeight = 768;

  InitWindow(windowWidth, windowHeight, "Game");

  // Character
  Image aeroplane = LoadImage("./textures/aeroplane.png");
  ImageResize(&aeroplane, 50, 50);
  Texture2D aeroplaneTexture = LoadTextureFromImage(aeroplane);

  // Enemy
  Texture2D enemyTexture = LoadTextureFromImage(aeroplane);

  Position aeroplanePos = {windowWidth / (float)2,
                           windowHeight / (float)2,
                           50,
                           70,
                           BLACK,
                           {.velocity = 100},
                           0};

  // Character

  // Enemy
  Position aeroplaneEnemyPos = {(float)(rand() % windowWidth),
                                10.0f,
                                50,
                                70,
                                BLACK,
                                {.velocity = 100},
                                0};

  while (WindowShouldClose() == false) {
    float deltaTime = GetFrameTime();

    // Player Controls
    GenericControls(&aeroplanePos.move);
    GenericMovement(&aeroplanePos.move, &aeroplanePos.posX, &aeroplanePos.posY,
                    &deltaTime, &aeroplanePos.rotation);

    // Calculating the distance vector
    struct coords enemy =
        calculate_distance(aeroplanePos.posX, aeroplaneEnemyPos.posX,
                           aeroplanePos.posY, aeroplaneEnemyPos.posY);

    // Enemy Movement
    float enemyAngleRad = atan2f(enemy.y, enemy.x);

    aeroplaneEnemyPos.posX +=
        cos(enemyAngleRad) * aeroplaneEnemyPos.move.velocity * deltaTime;
    aeroplaneEnemyPos.posY +=
        sin(enemyAngleRad) * aeroplaneEnemyPos.move.velocity * deltaTime;

    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Player translation logic
    rlPushMatrix();
    rlTranslatef((aeroplanePos.posX + aeroplanePos.width / 2.0f),
                 (aeroplanePos.posY + aeroplanePos.height / 2.0f), 0.0f);

    rlRotatef(aeroplanePos.rotation, 0.0f, 0.0f, 1.0f);

    DrawTexture(aeroplaneTexture, -aeroplanePos.width / 2.0f,
                -aeroplanePos.height / 2.0f, WHITE);

    rlPopMatrix();

    // Enemy translation logic
    rlPushMatrix();
    rlTranslatef(aeroplaneEnemyPos.posX + aeroplaneEnemyPos.width / 2.0f,
                 aeroplaneEnemyPos.posY + aeroplaneEnemyPos.height / 2.0f,
                 0.0f);

    rlRotatef(enemy.angle, 0.0f, 0.0f, 1.0f);

    DrawTexture(enemyTexture, -aeroplaneEnemyPos.width / 2.0f,
                -aeroplaneEnemyPos.height / 2.0f, WHITE);

    rlPopMatrix();
    EndDrawing();
  }

  UnloadImage(aeroplane);
  CloseWindow();

  return 0;
}
