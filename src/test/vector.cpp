#include "vector.h"

#include "../vector/vector2.h"

bool vectorTest() {
  const Vector2 v1(2, 3), v2(5, 6);
  Vector2 ans;

  if (v1 == v1) {
    return false;
  }

  if (!(v1 != v1)) {
    return false;
  }

  ans = v1 + v2;
  if (ans != Vector2(7, 9)) {
    return false;
  }

  ans = v1 - v2;
  if (ans != Vector2(-3, -3)) {
    return false;
  }

  ans = v1 * v2;
  if (ans != Vector2(10, 18)) {
    return false;
  }

  ans = v1 / v2;
  if (ans != Vector2(2 / 5, 3 / 6)) {
    return false;
  }

  ans = v1 + 7;
  if (ans != Vector2(9, 10)) {
    return false;
  }

  ans = v1 - 7;
  if (ans != Vector2(-5, -4)) {
    return false;
  }

  ans = v1 * 7;
  if (ans != Vector2(14, 21)) {
    return false;
  }

  ans = v1 / 7;
  if (ans != Vector2(2 / 7, 3 / 7)) {
    return false;
  }

  return true;
}
