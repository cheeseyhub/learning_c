#include "./Generics.h"
#include <math.h>
#include <raylib.h>

void GenericControls(struct movementComponent *o) {
  o->up = IsKeyDown(KEY_UP);
  o->down = IsKeyDown(KEY_DOWN);
  o->left = IsKeyDown(KEY_LEFT);
  o->right = IsKeyDown(KEY_RIGHT);
}
void GenericMovement(struct movementComponent *o, float *posX, float *posY,
                     float *deltaTime, float *rotation) {
  float distance = o->velocity * *deltaTime;
  if (o->left && o->up) {
    *rotation -= 1 * distance;
  }
  if (o->right && o->up) {
    *rotation += 1 * distance;
  }
  float rad = *rotation * (PI / 180);
  if (o->up) {
    *posX += sinf(rad) * distance;
    *posY -= cosf(rad) * distance;
  }
  if (o->down) {
    *posX -= sinf(rad) * distance;
    *posY += cosf(rad) * distance;
  }
}
