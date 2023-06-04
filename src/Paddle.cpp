#include "Paddle.h"

Paddle::Paddle(const Vector2& pos, float length, float speed, const Vector2& winSize)
{
    this->initPos = pos;
    this->length = length;
    this->speed = speed;
    this->winSize = winSize;

    this->pos = pos;
}

void Paddle::draw() { DrawRectangleRounded({pos.x, pos.y, length / 8, length}, 0.8, 0, RAYWHITE); }

void Paddle::process(float delta)
{
    if (IsKeyDown(KEY_A) && pos.y > speed * delta)
    {
        pos.y -= speed * delta;
    }

    if (IsKeyDown(KEY_D) && pos.y < winSize.y - speed * delta - length)
    {
        pos.y += speed * delta;
    }
}

void Paddle::reset() { this->pos = initPos; }
