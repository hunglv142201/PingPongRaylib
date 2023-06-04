#include "AiPaddle.h"

AiPaddle::AiPaddle(const Vector2& pos, float length, float speed, Vector2* ballPos, const Vector2& winSize)
{
    this->initPos = pos;
    this->length = length;
    this->speed = speed;
    this->ballPos = ballPos;
    this->winSize = winSize;

    this->pos = pos;
}

void AiPaddle::draw() { DrawRectangleRounded({pos.x, pos.y, length / 8, length}, 0.8, 0, RAYWHITE); }

void AiPaddle::process(float delta)
{
    if (pos.y + length / 2 > ballPos->y && pos.y > speed * delta)
    {
        pos.y -= speed * delta;
    }
    else if (pos.y < winSize.y - speed * delta - length)
    {
        pos.y += speed * delta;
    }
}

void AiPaddle::reset() { this->pos = initPos; }
