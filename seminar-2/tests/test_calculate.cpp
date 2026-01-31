#include <catch2/catch_test_macros.hpp>
#include <calculate.h>

TEST_CASE("Calculator works correctly") {
  SECTION("Normal addition") {
    REQUIRE(calculate(1, 2, '+') == 3);
    REQUIRE(calculate(-101, 11, '+') == -90);
    REQUIRE(calculate(-43, -256, '+') == -299);
  }
  SECTION("Normal subtraction") {
    REQUIRE(calculate(1, 2, '-') == -1);
    REQUIRE(calculate(-101, 11, '-') == -112);
    REQUIRE(calculate(-43, -256, '-') == 213);
  }
  SECTION("Using incorrect operation") {
    REQUIRE(calculate(1, 2, '*') == 2);
    REQUIRE(calculate(-101, 11, '/') == 11);
    REQUIRE(calculate(-43, -256, '(') == -256);
  }
}