#include "compose.hpp"
#include <doctest/doctest.h>

auto increment = [](auto n) { return ++n; };

auto decrement = [](auto n) { return --n; };

auto sum = [](auto a, auto b) { return a + b; };

auto produce_1 = [] { return 1; };

TEST_CASE("function with single function argument should compose") {
  auto id = rd::compose(increment, decrement);
  CHECK(id(2) == 2);
}

TEST_CASE("a.b, b accepting multiple arguments should also compose") {
  auto sum_minus_1 = rd::compose(decrement, sum);
  CHECK(sum_minus_1(2, 3) == 4);
}

TEST_CASE("a.b, b accepting zero arguments should also compose") {
  auto produce_0 = rd::compose(decrement, produce_1);
  CHECK(produce_0() == 0);
}
