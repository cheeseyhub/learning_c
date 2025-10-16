#include "./Generics.h"
#include <stdio.h>

void GenericControls(struct movementComponent *o) {
  o->up = IsKeyDown(KEY_UP);
  o->down = IsKeyDown(KEY_DOWN);
  o->left = IsKeyDown(KEY_LEFT);
  o->right = IsKeyDown(KEY_RIGHT);
}
void GenericMovement(struct movementComponent *o, float *posX, float *posY,
                     float *deltaTime) {
  int distance = o->velocity * *deltaTime;
  if (o->up) {
    *posY -= distance;
  }
  if (o->down) {
    *posY += distance;
  }
  if (o->left) {
    *posX -= distance;
  }
  if (o->right) {
    *posX += distance;
  }
}
