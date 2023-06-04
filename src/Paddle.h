#pragma once

#include "raylib.h"

class Paddle
{
  public:
    Paddle(const Vector2& pos, float length, float speed, const Vector2& winSize);

    Vector2 pos;
    float length;

    void draw();
    void process(float delta);
    void reset();

  private:
    Vector2 initPos;
    float speed;
    Vector2 winSize;
};