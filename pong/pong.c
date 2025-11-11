#include <math.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>

struct Paddle {
  double x;
  double y;
  unsigned int width;
  unsigned int height;
  double velocity;
  unsigned int score;
};

struct Ball {
  double x;
  double y;
  unsigned int radius;
  double velocityX;
  double velocityY;
  double velocityLimit;
};
double std_random(int max, int min) { return rand() % (max - min + 1) + min; }

void ballMovement(struct Ball *ball, float deltaTime, int windowWidth,
                  int windowHeight, unsigned int *playerOneScore,
                  unsigned int *playerTwoScore) {

  if (ball->y + ball->radius > windowHeight || ball->y - ball->radius < 0) {
    ball->velocityY *= -1;
  }
  float velocityX = ball->velocityX * deltaTime;
  float velocityY = ball->velocityY * deltaTime;

  ball->x += velocityX;
  ball->y += velocityY;

  if (ball->x + ball->radius >= windowWidth) {

    ball->x = windowWidth / 2.0;
    ball->y = windowHeight / 2.0;

    ball->velocityX = std_random(200, 100);
    ball->velocityY = std_random(200, 100);

    *playerOneScore = *playerOneScore + 1;

  } else if (ball->x - ball->radius <= 0) {

    ball->x = windowWidth / 2.0;
    ball->y = windowHeight / 2.0;

    ball->velocityX = std_random(200, 100);
    ball->velocityY = std_random(200, 100);

    *playerTwoScore = *playerTwoScore + 1;
  }
};
int distance_formula(struct Ball *ball, struct Paddle *paddle) {

  double closestX = ball->x;
  double closestY = ball->y;

  int collisionXValue = 1;
  int collisionYValue = 1;

  if (ball->x < paddle->x) {

    closestX = paddle->x;

  } else if (ball->x > paddle->x + paddle->width) {
    closestX = paddle->x + paddle->width;
    collisionXValue = 1;
  }

  if (ball->y < paddle->y) {

    closestY = paddle->y;
  } else if (ball->y > paddle->y + paddle->height) {
    closestY = paddle->y + paddle->height;

    collisionYValue = 1;
  }

  double distance =
      pow(pow(ball->x - closestX, 2) + pow(ball->y - closestY, 2), 2);
  double ballSquareRadius = pow(ball->radius, 2);

  if (distance <= ballSquareRadius) {
    return collisionXValue + collisionYValue;
  } else {
    // Do nothing value
    return 5;
  }
};

void paddleBallCollision(struct Ball *ball, struct Paddle *paddle,
                         float deltaTime, int windowWidth, int windowHeight) {

  int result = distance_formula(ball, paddle);
  if (result == 1) {
    ball->velocityY *= 1;
    ball->velocityX *= -1;
  } else if (result == 2) {
    ball->velocityY *= 1.2;
    ball->velocityX *= -1.2;
  } else if (result == 0) {
    ball->velocityY *= -1.4;
    ball->velocityX *= -1.4;
  }

  // Limits of speed
  if (ball->velocityX < -ball->velocityLimit) {
    ball->velocityX = -ball->velocityLimit;
  } else if (ball->velocityX > ball->velocityLimit) {
    ball->velocityX = ball->velocityLimit;
  }

  if (ball->velocityY < -ball->velocityLimit) {
    ball->velocityY = -ball->velocityLimit;
  } else if (ball->velocityY > ball->velocityLimit) {
    ball->velocityY = ball->velocityLimit;
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
  struct Paddle playerOne = {0, 0, paddlesWidth, paddlesHeight};

  // Paddle two
  struct Paddle playerTwo = {windowWidth - paddlesWidth, 0, paddlesWidth,
                             paddlesHeight};
  playerOne.velocity = 400;
  playerTwo.velocity = 400;

  // Scores
  playerOne.score = 0;
  playerTwo.score = 0;

  // Ball
  struct Ball ball = {windowWidth / 2.0, windowHeight / 2.0, 10};
  ball.velocityX = -200;
  ball.velocityY = -200;
  // Limits of ball speed;
  ball.velocityLimit = 500;

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
    DrawText(TextFormat("Score: %d", playerOne.score), 0, 0, 30, WHITE);
    DrawText(TextFormat("Score: %d", playerTwo.score), windowWidth - 135, 0, 30,
             WHITE);
    EndDrawing();
  }
  return 0;
}
