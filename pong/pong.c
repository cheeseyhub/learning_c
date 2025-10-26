#include <math.h>
#include <raylib.h>

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

  int topLeftX = paddle->x;
  int topLeftY = paddle->y;

  int topRightX = paddle->x + paddle->width;
  int topRightY = paddle->y;

  int bottomLeftX = paddle->x;
  int bottomLeftY = paddle->y + paddle->height;

  int bottomRightX = paddle->x + paddle->width;
  int bottomRightY = paddle->y + paddle->height;
}

void paddleBallCollision(struct Ball *ball, struct Paddle *paddle,
                         float deltaTime, int windowWidth, int windowHeight) {

  if (distance_formula(ball, paddle) == 1) {
    ball->velocityX *= -1;
  }
};

void enemyPaddleMovement(struct Paddle *paddle, float windowWidth) {
  if (paddle->x + paddle->width > windowWidth) {
    paddle->x = windowWidth - paddle->width;
  }
  if (paddle->x < 0) {
    paddle->x = 0;
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

int main() {

  int windowWidth = 1366;
  int windowHeight = 768;

  int paddlesWidth = 30;
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
  struct Ball ball = {windowWidth / 2.0, windowHeight / 2.0, 3};
  ball.velocityX = -100;
  ball.velocityY = -100;

  while (WindowShouldClose() == false) {

    float deltaTime = GetFrameTime();

    // Ball movement
    ballMovement(&ball, deltaTime, windowWidth, windowHeight);

    // PLAYER PADDLE MOVEMENT
    playerPaddleMovement(&paddle, windowWidth, deltaTime);

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
