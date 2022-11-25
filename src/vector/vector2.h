#pragma once

class Vector2 {
 private:
  double x;
  double y;

 public:
  Vector2();
  Vector2(double x, double y);

  Vector2 operator+() const;
  Vector2 operator-() const;

  Vector2 operator+(const Vector2& v) const;
  Vector2 operator-(const Vector2& v) const;
  Vector2 operator*(const Vector2& v) const;
  Vector2 operator/(const Vector2& v) const;

  Vector2 operator+(double i) const;
  Vector2 operator-(double i) const;
  Vector2 operator*(double i) const;
  Vector2 operator/(double i) const;

  bool operator==(const Vector2& v) const;
  bool operator!=(const Vector2& v) const;
};
