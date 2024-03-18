#include "raylib.h"

#define MAX_BALLS 100
#define BALL_SPEED 3

typedef struct {
    Vector2 position;
    Vector2 speed;
    Color color;
    float radius;
}Ball;

void updateBall(Ball *ball)
{
    ball->position.x += ball-> speed.x;
    ball->position.y += ball-> speed.y;

    if((ball->position.x >=(GetScreenWidth() - ball->radius)) || (ball->position.x <= ball->radius))
    {
        ball->speed.x *= -1;
    }
    if((ball->position.y >=(GetScreenHeight() - ball->radius)) || (ball->position.y <= ball->radius))
    {
        ball->speed.y *=-1;
    }
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Bouncing Balls");
    SetTargetFPS(60);

    Ball balls[MAX_BALLS];

    for (int i = 0; i < MAX_BALLS; i++)
    {
        balls[i].position = (Vector2){GetRandomValue(0, screenWidth), GetRandomValue(0, screenHeight)};
        balls[i].speed = (Vector2){GetRandomValue(-BALL_SPEED, BALL_SPEED), GetRandomValue(-BALL_SPEED, BALL_SPEED)};
        balls[i].color = (Color) {GetRandomValue(50, 255), GetRandomValue(50, 255), GetRandomValue(50,255), 255};
        balls[i].radius = GetRandomValue(10,30);
    }

    while(!WindowShouldClose())
    {
        for (int i = 0 ; i < MAX_BALLS; i++) {
            updateBall(&balls[i]);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < MAX_BALLS; i++) {
            DrawCircleV(balls[i].position, balls[i].radius, balls[i].color);
        }

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
