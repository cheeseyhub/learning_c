#include "utility.h"
#include <math.h>

struct coords calculate_distance(float playerX, float enemyX, float playerY,
                                 float enemyY) {
  struct coords distance;

  distance.x = playerX - enemyX;
  distance.y = playerY - enemyY;

  distance.angle = atan2(distance.y, distance.x) * (180 / M_PI);

  return distance;
}
