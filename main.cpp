#include "AiPaddle.h"
#include "Ball.h"
#include "Paddle.h"
#include "raylib.h"

Color Green = {38, 185, 154, 255};
Color Dark_Green = {20, 160, 133, 255};
Color Light_Green = {129, 204, 184, 255};

int playerScore = 0;
int aiScore = 0;

void checkBallCollision(Ball& ball, Paddle& player, AiPaddle& ai, const Vector2& winSize);

int main()
{
    Vector2 winSize = {480, 320};

    Ball ball = {{winSize.x / 2, winSize.y / 2}, winSize.y / 30, 400};

    float padLength = winSize.y / 4;
    Paddle player = {{winSize.x - padLength / 8 - 20, winSize.y / 2 - padLength / 2}, padLength, 200, winSize};
    AiPaddle ai = {{20, winSize.y / 2 - padLength / 2}, padLength, 200, &ball.pos, winSize};

    InitWindow(winSize.x, winSize.y, "Ping Pong");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawRectangle(0, 0, winSize.x / 2, winSize.y, Dark_Green);
        DrawRectangle(winSize.x / 2, 0, winSize.x / 2, winSize.y, Green);
        DrawCircle(winSize.x / 2, winSize.y / 2, winSize.y / 6, Light_Green);

        player.draw();
        ai.draw();
        ball.draw();

        DrawText(TextFormat("%i", aiScore), winSize.x / 4, 10, 32, RAYWHITE);
        DrawText(TextFormat("%i", playerScore), winSize.x * 3 / 4, 10, 32, RAYWHITE);

        DrawFPS(10, 10);

        EndDrawing();

        float frameTime = GetFrameTime();

        player.process(frameTime);
        ai.process(frameTime);
        ball.process(frameTime);

        checkBallCollision(ball, player, ai, winSize);

        if (IsKeyDown(KEY_SPACE))
        {
            ball.reset();
        }
    }

    CloseWindow();

    return 0;
}

void checkBallCollision(Ball& ball, Paddle& player, AiPaddle& ai, const Vector2& winSize)
{
    if (ball.pos.y - ball.radius <= 0 || ball.pos.y + ball.radius >= winSize.y)
    {
        ball.velocity.y *= -1;
    }

    if (CheckCollisionCircleRec(ball.pos, ball.radius,
                                {player.pos.x, player.pos.y, player.length / 8, player.length}) ||
        CheckCollisionCircleRec(ball.pos, ball.radius, {ai.pos.x, ai.pos.y, ai.length / 8, ai.length}))
    {
        ball.velocity.x *= -1.2;
        ball.velocity.y *= 1.2;
    }

    if (ball.pos.x + ball.radius < 0)
    {
        ball.reset();
        player.reset();
        ai.reset();
        playerScore++;
    }
    else if (ball.pos.x - ball.radius > winSize.x)
    {
        ball.reset();
        player.reset();
        ai.reset();
        aiScore++;
    }
}
