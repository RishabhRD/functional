#include "pipeable.hpp"
#include <doctest/doctest.h>

auto concat =
    rd::pipeable([](int a, std::string b) { return std::to_string(a) + b; });

TEST_CASE("Making a function pipeable also makes it reverse curryable") {
  auto concat_with_hello = concat(" hello");
  CHECK(concat_with_hello(1) == "1 hello");
}

TEST_CASE("Calling function with all arguments invoke the function") {
  auto concat_with_hello = concat(1, " hello");
  CHECK(concat_with_hello == "1 hello");
}

TEST_CASE("Should be pipeable") {
  CHECK((1 | concat(" hello")) == "1 hello");
  auto concat_with_hello = concat(" hello");
  auto ans1 = 1 | concat_with_hello();
  auto ans2 = 1 | concat_with_hello;
  CHECK(ans1 == "1 hello");
  CHECK(ans2 == "1 hello");
}
