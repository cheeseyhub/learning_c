#include <math.h>
#include <raylib.h>
// #include <stdio.h>
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
  int posX;
  int posY;
  double velocity;
  double maxVelocity;
  float radius;
} Particle;

//  Functions
//  Random Number generator

double random_number() {
  // random() % (min - max + 1 ) + min;
  int max = 100;
  int min = 90;
  return floor(rand() % (max - min + 1) + min);
};

// Chance Generator
int chance() { return floor(rand() % 10); }

void MoveParticle(Particle *particle, double deltaTime) {
  particle->posX += particle->velocity * deltaTime;
  particle->posY += particle->velocity * deltaTime;
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

        10, 100, 5};
  };

  while (WindowShouldClose() == false) {

    ClearBackground(BLACK);

    BeginDrawing();

    for (int i = 0; i < numberOfParticles; i++) {
      DrawCircle(particles[i].posX, particles[i].posY, particles[i].radius,
                 WHITE);
    }

    EndDrawing();
  }

  return 0;
}
