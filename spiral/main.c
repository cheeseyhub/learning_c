#include "include/raylib.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Particle
typedef struct {
  double posX;
  double posY;
  double velocityX;
  double velocityY;
  float radius;
} Particle;

double random_number() {
  int max = 100;
  int min = 90;
  return floor(rand() % (max - min + 1) + min);
};
double random_radius(int min, int max) {

  return floor(rand() % (max - min + 1) + min);
}
double random_angle() {
  int max = 360;
  int min = 0;
  return (PI / 180) * (rand() % (max - min + 1) + min);
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

  const double G = 0.066743;
  particle->velocityX += (unitVxAcceleration * G) / particle->radius;
  particle->velocityY += (unitVyAcceleration * G) / particle->radius;
}

int main() {

  srand(time(NULL));
  int windowWidth = 1366;
  int windowHeight = 768;
  int numberOfParticles = 20;

  double centerDensityRadius = 300;

  InitWindow(windowWidth, windowHeight, "This is a title");

  Particle particles[numberOfParticles];

  for (int i = 0; i < numberOfParticles; i++) {

    // Make Particles (spawn only on corners)
    // particles[i] = (Particle){
    //
    //     chance() > 5 ? (windowWidth / 2.0) + random_number()
    //                  : (windowWidth / 2.0) - random_number(),
    //
    //     chance() > 5 ? (windowHeight / 2.0) + random_number()
    //                  : (windowHeight / 2.0) - random_number(),
    //
    //     0, 0, 3};

    // Spawn all around in square

    particles[i] = (Particle){

        (windowWidth / 2.0) + (centerDensityRadius * cos(random_angle())),

        (windowHeight / 2.0) + (centerDensityRadius * sin(random_angle())),

        0, 0, 2};

    // particles[i] = (Particle){
    //
    //     (windowWidth / 2.0) + (centerDensityRadius * cos(i)),
    //
    //     (windowHeight / 2.0) + (centerDensityRadius * sin(i)),
    //
    //     0, 0, 2};
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
        // prevent particle from attracting itself
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
