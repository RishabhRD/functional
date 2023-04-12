#include "bind.hpp"
#include <doctest/doctest.h>

auto sum = [](auto a, auto b, auto c) { return a + b + c; };

TEST_CASE("bind_back should work with 0 binding arguments") {
  auto sum_again = rd::bind_back(sum);
  CHECK(sum_again(1, 2, 3) == 6);
}

TEST_CASE("bind_back should work with 1 binding argument") {
  auto sum_2 = rd::bind_back(sum, 3);
  CHECK(sum_2(1, 2) == 6);
}

TEST_CASE("bind_back should work with multiple binding arguments") {
  auto sum_1 = rd::bind_back(sum, 2, 3);
  CHECK(sum_1(1) == 6);
}
