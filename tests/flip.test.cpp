#include "flip.hpp"
#include <doctest/doctest.h>

TEST_CASE("should flip a function with 2 arguments") {
  auto concat = [](int a, std::string b) { return std::to_string(a) + b; };
  auto flipped_concat = rd::flip(concat);
  CHECK(flipped_concat(" hello", 2) == "2 hello");
}

TEST_CASE("should flip a function with muliple arguments") {
  auto concat = [](int a, int b, std::string c) {
    return std::to_string(a) + std::to_string(b) + c;
  };
  auto flipped_concat = rd::flip(concat);
  CHECK(flipped_concat(" hello", 2, 3) == "23 hello");
}
