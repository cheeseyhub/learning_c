#include <raylib.h>

struct Paddle {
  float x;
  float y;
  int width;
  int height;
};

struct Ball {
  float x;
  float y;
  int radius;
};

void ballMovement(struct Ball *ball, float deltaTime) {
  float velocity = 50 * deltaTime;
  ball->x += velocity;
  ball->y += velocity;
};

int main() {

  int windowWidth = 1366;
  int windowHeight = 800;
  InitWindow(windowWidth, windowHeight, "Pong Game");

  // Paddle one
  struct Paddle paddle = {0, 0, 10, 30};

  // Paddle two
  struct Paddle paddleTwo = {windowWidth - 10, 0, 10, 30};

  // Ball
  struct Ball ball = {windowWidth / 2.0, windowHeight / 2.0, 10};

  while (WindowShouldClose() == false) {
    float deltaTime = GetFrameTime();
    // Ball movement
    ballMovement(&ball, deltaTime);

    BeginDrawing();
    // ClearBackground
    ClearBackground(BLACK);

    // Draw Player
    DrawRectangle(paddle.x, paddle.y, paddle.width, paddle.height, BLUE);
    // Draw Enemy;
    DrawRectangle(paddleTwo.x, paddleTwo.y, paddleTwo.width, paddleTwo.height,
                  BLUE);
    // Draw The ball
    DrawCircle(ball.x, ball.y, ball.radius, WHITE);

    EndDrawing();
  }
  return 0;
}
