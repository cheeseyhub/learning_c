#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Make Particle Structure [posX , posY, velocity,maxVelocity , radius ]
 *
 * Make Two particles for testing
 *
 * Function that generates a random number
 * Function that attracts particles.
 *  -- subtract particles x and y from each other and  set the velocity
 *  -- Normalize Vector and set the velocity there should be no division by
 * zero;
 *
 *
 * Need to use Arrays to store particles
 *
 *
 *
 * **/

// Particle
typedef struct {
  double posX;
  double posY;
  double velocityX;
  double velocityY;
  double maxVelocity;
  float radius;
} Particle;

//  Functions
//  Random Number generator

double random_number() {
  int max = 100;
  int min = 90;
  return floor(rand() % (max - min + 1) + min);
};
// Random angles
double random_Angle() {
  int max = 360;
  int min = 0;
  return floor(rand() % (max - min + 1) + min);
}

// Chance Generator
int chance() { return floor(rand() % 10); }

void MoveParticle(Particle *particle, double deltaTime) {
  particle->posX = particle->posX + (particle->velocityX * deltaTime);
  particle->posY = particle->posY + (particle->velocityY * deltaTime);
}
double calculate_attraction(Particle *particle, Particle *otherParticle) {

  // Todo calculate_attraction

  double distanceX = particle->posX - otherParticle->posX;
  double distanceY = particle->posY - otherParticle->posY;
  double vector = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

  return 1;
}

int main() {

  int windowWidth = 1366;
  int windowHeight = 768;
  int numberOfParticles = 20;

  InitWindow(windowWidth, windowHeight, "Title");

  Particle particles[numberOfParticles];

  for (int i = 0; i < numberOfParticles; i++) {

    // Make Particles
    particles[i] = (Particle){

        chance() > 5 ? (windowWidth / 2.0) + random_number()
                     : (windowWidth / 2.0) - random_number(),

        chance() > 5 ? (windowHeight / 2.0) + random_number()
                     : (windowHeight / 2.0) - random_number(),

        200,
        200,
        3000,
        5};
  };

  while (WindowShouldClose() == false) {
    double deltaTime = GetFrameTime();

    ClearBackground(BLACK);

    BeginDrawing();

    for (int i = 0; i < numberOfParticles; i++) {
      // Draw
      DrawCircle(particles[i].posX, particles[i].posY, particles[i].radius,
                 WHITE);
      // Move
      MoveParticle(&particles[i], deltaTime);
    }

    EndDrawing();
  }

  return 0;
}
