#pragma once

#include "VectorUtils.h"
#include "raylib.h"

class Ball
{
  public:
    Ball(const Vector2& pos, float radius, float speed);

    Vector2 pos;
    float radius;
    Vector2 velocity;

    void draw();
    void process(float delta);
    void reset();

  private:
    Vector2 initPos;
    float speed;

    Vector2 generateRandomVelocity();
};