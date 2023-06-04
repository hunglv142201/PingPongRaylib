#include "Ball.h"

Ball::Ball(const Vector2& pos, float radius, float speed)
{
    this->initPos = pos;
    this->radius = radius;
    this->speed = speed;

    this->pos = pos;
    this->velocity = generateRandomVelocity();
}

void Ball::draw() { DrawCircleV(pos, radius, {243, 213, 91, 255}); }

void Ball::process(float delta) { pos += velocity * delta; }

void Ball::reset()
{
    this->pos = initPos;
    this->velocity = generateRandomVelocity();
}

Vector2 Ball::generateRandomVelocity()
{
    int dir[] = {-1, 1};

    int x = GetRandomValue(50, 100);
    int y = GetRandomValue(20, 100);

    float dX = dir[GetRandomValue(0, 1)] * x * speed / (x + y);
    float dY = dir[GetRandomValue(0, 1)] * y * speed / (x + y);

    return {dX, dY};
}
