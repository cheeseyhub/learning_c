#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
 * random_radius
 *
 *
 * **/

// Particle
typedef struct {
  double posX;
  double posY;
  double velocityX;
  double velocityY;
  float radius;
} Particle;

//  Functions
//  Random Number generator

double random_number() {
  int max = 100;
  int min = 90;
  return floor(rand() % (max - min + 1) + min);
};
double random_radius(int min, int max) {

  return floor(rand() % (max - min + 1) + min);
}

// Chance Generator
int chance() { return floor(rand() % 10); }

void MoveParticle(Particle *particle, double deltaTime) {

  particle->posX += (particle->velocityX * deltaTime);
  particle->posY += (particle->velocityY * deltaTime);
}
void calculate_attraction(Particle *particle, Particle *otherParticle) {

  double distanceX = otherParticle->posX - particle->posX;
  double distanceY = otherParticle->posY - particle->posY;
  double magnitude = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

  // Prevent division by zero;
  if (magnitude < 100) {
    magnitude = 100;
  }

  // Calculating Unit Vector
  double unitVxAcceleration = distanceX / magnitude;
  double unitVyAcceleration = distanceY / magnitude;

  const double G = 0.008;
  particle->velocityX += (unitVxAcceleration * G) / particle->radius;
  particle->velocityY += (unitVyAcceleration * G) / particle->radius;
}

int main() {

  srand(time(NULL));
  int windowWidth = 1366;
  int windowHeight = 768;
  int numberOfParticles = 500;

  InitWindow(windowWidth, windowHeight, "Title");

  Particle particles[numberOfParticles];

  for (int i = 0; i < numberOfParticles; i++) {

    // Make Particles
    particles[i] = (Particle){

        chance() > 5 ? (windowWidth / 2.0) + random_number()
                     : (windowWidth / 2.0) - random_number(),

        chance() > 5 ? (windowHeight / 2.0) + random_number()
                     : (windowHeight / 2.0) - random_number(),

        0, 0, 1};
  };

  while (WindowShouldClose() == false) {
    double deltaTime = GetFrameTime();

    ClearBackground(BLACK);

    BeginDrawing();

    for (int i = 0; i < numberOfParticles; i++) {
      // Draw
      DrawCircle(particles[i].posX, particles[i].posY, particles[i].radius,
                 WHITE);

      // calculate_attraction
      for (int j = 0; j < numberOfParticles; j++) {
        // prvent particle from attracting itself
        if (j != i) {
          calculate_attraction(&particles[i], &particles[j]);
        }
      }
      // Move
      MoveParticle(&particles[i], deltaTime);
    }

    EndDrawing();
  }

  return 0;
}
