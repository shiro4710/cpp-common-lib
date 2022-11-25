#include "vector2.h"

Vector2::Vector2() {
  x = 0;
  y = 0;
}

Vector2::Vector2(double x, double y) {
  this->x = x;
  this->y = y;
}

Vector2 Vector2::operator+() const { return Vector2(x, y); }
Vector2 Vector2::operator-() const { return Vector2(-x, -y); }

Vector2 Vector2::operator+(const Vector2& v) const {
  return Vector2(x + v.x, y + v.y);
}
Vector2 Vector2::operator-(const Vector2& v) const {
  return Vector2(x - v.x, y - v.y);
}
Vector2 Vector2::operator*(const Vector2& v) const {
  return Vector2(x * v.x, y * v.y);
}
Vector2 Vector2::operator/(const Vector2& v) const {
  return Vector2(x / v.x, y / v.y);
}

Vector2 Vector2::operator+(double i) const { return Vector2(x + i, y + i); }
Vector2 Vector2::operator-(double i) const { return Vector2(x - i, y - i); }
Vector2 Vector2::operator*(double i) const { return Vector2(x * i, y * i); }
Vector2 Vector2::operator/(double i) const { return Vector2(x / i, y / i); }

bool Vector2::operator==(const Vector2& v) const {
  return x == v.x && y == v.y;
}
bool Vector2::operator!=(const Vector2& v) const { return !(*this == v); }
