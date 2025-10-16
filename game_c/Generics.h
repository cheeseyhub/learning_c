#include <raylib.h>
struct movementComponent {
  float velocity;
  int up;
  int down;
  int left;
  int right;
};
void GenericControls(struct movementComponent *o);
void GenericMovement(struct movementComponent *o, float *posX, float *posY,
                     float *deltaTime);
