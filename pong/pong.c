#include <math.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

struct Paddle {
  double x;
  double y;
  int width;
  int height;
  double velocity;
  int score;
};

struct Ball {
  float x;
  float y;
  int radius;
  double velocityX;
  double velocityY;
};
double std_random() { return rand() % (200 - 100 + 1); }

void ballMovement(struct Ball *ball, float deltaTime, int windowWidth,
                  int windowHeight, int *playerOneScore, int *playerTwoScore) {

  if (ball->y + ball->radius > windowHeight || ball->y - ball->radius < 0) {
    ball->velocityY *= -1;
  }
  float velocityX = ball->velocityX * deltaTime;
  float velocityY = ball->velocityY * deltaTime;

  ball->x += velocityX;
  ball->y += velocityY;

  if (ball->x + ball->radius > windowWidth) {

    ball->x = windowWidth / 2.0;
    ball->y = windowHeight / 2.0;

    ball->velocityX = std_random();
    ball->velocityY = std_random();

    *playerOneScore = *playerOneScore + 1;

  } else if (ball->x - ball->radius < 0) {

    ball->x = windowWidth / 2.0;
    ball->y = windowHeight / 2.0;

    ball->velocityX = std_random();
    ball->velocityY = std_random();

    *playerTwoScore = *playerTwoScore + 1;
  }
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
  srand(time(0));

  int windowWidth = 1366;
  int windowHeight = 768;

  int paddlesWidth = 20;
  int paddlesHeight = 80;

  InitWindow(windowWidth, windowHeight, "Pong Game");

  // Paddle one
  struct Paddle playerOne = {0, 0, paddlesWidth, paddlesHeight};

  // Paddle two
  struct Paddle playerTwo = {windowWidth - paddlesWidth, 0, paddlesWidth,
                             paddlesHeight};
  playerOne.velocity = 300;
  playerTwo.velocity = 300;

  // Scores
  playerOne.score = 0;
  playerTwo.score = 0;

  // Ball
  struct Ball ball = {windowWidth / 2.0, windowHeight / 2.0, 10};
  ball.velocityX = -100;
  ball.velocityY = -100;

  while (WindowShouldClose() == false) {

    float deltaTime = GetFrameTime();

    // Ball movement
    ballMovement(&ball, deltaTime, windowWidth, windowHeight, &playerOne.score,
                 &playerTwo.score);

    // PLAYER PADDLE MOVEMENT
    playerPaddleMovement(&playerOne, windowWidth, deltaTime);

    // enemyPaddleMovement
    enemyPaddleMovement(&playerTwo, windowWidth, deltaTime);

    // Paddle limits
    paddleLimits(&playerOne, windowWidth, windowHeight);
    paddleLimits(&playerTwo, windowWidth, windowHeight);

    // Collision
    paddleBallCollision(&ball, &playerOne, deltaTime, windowWidth,
                        windowHeight);
    paddleBallCollision(&ball, &playerTwo, deltaTime, windowWidth,
                        windowHeight);
    BeginDrawing();

    // ClearBackground
    ClearBackground(BLACK);

    // Draw Player
    DrawRectangle(playerOne.x, playerOne.y, playerOne.width, playerOne.height,
                  BLUE);

    // Draw Enemy;
    DrawRectangle(playerTwo.x, playerTwo.y, playerTwo.width, playerTwo.height,
                  BLUE);

    // Draw The ball
    DrawCircle(ball.x, ball.y, ball.radius, WHITE);

    // Drawing Scores
    DrawText(TextFormat("PlayerOne , %d", playerOne.score), 0, 0, 30, WHITE);
    EndDrawing();
  }
  return 0;
}
