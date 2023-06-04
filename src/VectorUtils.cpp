#include "VectorUtils.h"

void operator+=(Vector2& left, const Vector2& right)
{
    left.x += right.x;
    left.y += right.y;
}

Vector2 operator*(const Vector2& left, float right) { return {left.x * right, left.y * right}; }