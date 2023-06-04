#pragma once

#include "raylib.h"

class AiPaddle
{
  public:
    AiPaddle(const Vector2& pos, float length, float speed, Vector2* ballPos, const Vector2& winSize);

    Vector2 pos;
    float length;

    void draw();
    void process(float delta);
    void reset();

  private:
    Vector2 initPos;
    float speed;
    Vector2 winSize;

    Vector2* ballPos;
};