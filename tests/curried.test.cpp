#include "curried.hpp"
#include <doctest/doctest.h>

auto sum = rd::curried([](auto a, auto b) { return a + b; });

TEST_CASE("curried function should invoke actual function when called with "
          "enough arguments") {
  CHECK(sum(1, 2) == 3);
}

TEST_CASE("curried function should return function with given arguments binded "
          "in front") {
  auto sum_1 = sum(1);
  CHECK(sum_1(2) == 3);
}
