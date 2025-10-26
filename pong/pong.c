#include <math.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

struct Paddle {
  float x;
  float y;
  int width;
  int height;
  float velocity;
};

struct Ball {
  float x;
  float y;
  int radius;
  float velocityX;
  float velocityY;
};

void ballMovement(struct Ball *ball, float deltaTime, int windowWidth,
                  int windowHeight) {

  if (ball->y + ball->radius > windowHeight || ball->y - ball->radius < 0) {
    ball->velocityY *= -1;
  }
  float velocityX = ball->velocityX * deltaTime;
  float velocityY = ball->velocityY * deltaTime;

  ball->x += velocityX;
  ball->y += velocityY;
};
int distance_formula(struct Ball *ball, struct Paddle *paddle) {

  double closestX = ball->x;
  double closestY = ball->y;

  if (ball->x < paddle->x) {

    closestX = paddle->x;

  } else if (ball->x > paddle->x + paddle->width) {
    closestX = paddle->x + paddle->width;
  }

  if (ball->y < paddle->y) {

    closestY = paddle->y;

  } else if (ball->y > paddle->y + paddle->height) {

    closestY = paddle->y + paddle->height;
  }

  double distance =
      pow(pow(ball->x - closestX, 2) + pow(ball->y - closestY, 2), 2);
  double ballSquareRadius = pow(ball->radius, 2);

  if (distance <= ballSquareRadius) {
    return 1;
  } else {
    return 0;
  }
};

void paddleBallCollision(struct Ball *ball, struct Paddle *paddle,
                         float deltaTime, int windowWidth, int windowHeight) {

  if (distance_formula(ball, paddle) == 1) {
    ball->velocityX *= -1.4;
  }
};

void paddleLimits(struct Paddle *paddle, float windowWidth,
                  float windowHeight) {
  if (paddle->x + paddle->width > windowWidth) {
    paddle->x = windowWidth - paddle->width;
  }
  if (paddle->x <= 0) {
    paddle->x = 0;
  }
  if (paddle->y + paddle->height > windowHeight) {
    paddle->y = windowHeight - paddle->height;
  }
  if (paddle->y <= 0) {
    paddle->y = 0;
  }
}
void playerPaddleMovement(struct Paddle *playerPaddle, float windowWidth,
                          float deltaTime) {
  if (IsKeyDown(KEY_UP)) {
    playerPaddle->y -= playerPaddle->velocity * deltaTime;
  }
  if (IsKeyDown(KEY_DOWN)) {
    playerPaddle->y += playerPaddle->velocity * deltaTime;
  }
}
void enemyPaddleMovement(struct Paddle *playerPaddle, float windowWidth,
                         float deltaTime) {
  if (IsKeyDown(KEY_W)) {
    playerPaddle->y -= playerPaddle->velocity * deltaTime;
  }
  if (IsKeyDown(KEY_S)) {
    playerPaddle->y += playerPaddle->velocity * deltaTime;
  }
}

int main() {
  srand(time(NULL));

  int windowWidth = 1366;
  int windowHeight = 768;

  int paddlesWidth = 20;
  int paddlesHeight = 80;

  InitWindow(windowWidth, windowHeight, "Pong Game");

  // Paddle one
  struct Paddle paddle = {0, 0, paddlesWidth, paddlesHeight};

  // Paddle two
  struct Paddle paddleTwo = {windowWidth - paddlesWidth, 0, paddlesWidth,
                             paddlesHeight};
  paddle.velocity = 100;
  paddleTwo.velocity = 100;

  // Ball
  struct Ball ball = {windowWidth / 2.0, windowHeight / 2.0, 10};
  ball.velocityX = -100;
  ball.velocityY = -100;

  while (WindowShouldClose() == false) {

    float deltaTime = GetFrameTime();

    // Ball movement
    ballMovement(&ball, deltaTime, windowWidth, windowHeight);

    // PLAYER PADDLE MOVEMENT
    playerPaddleMovement(&paddle, windowWidth, deltaTime);

    // enemyPaddleMovement
    enemyPaddleMovement(&paddleTwo, windowWidth, deltaTime);
    // Paddle limits
    paddleLimits(&paddle, windowWidth, windowHeight);
    paddleLimits(&paddleTwo, windowWidth, windowHeight);

    // Collision
    paddleBallCollision(&ball, &paddle, deltaTime, windowWidth, windowHeight);
    paddleBallCollision(&ball, &paddleTwo, deltaTime, windowWidth,
                        windowHeight);
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
