#include <iostream>

#include "./test/vector.h"

int main() {
  if (vectorTest()) {
    std::cout << "Vector error." << std::endl;
    return 1;
  }
  std::cout << "Ok." << std::endl;

  return 0;
}
