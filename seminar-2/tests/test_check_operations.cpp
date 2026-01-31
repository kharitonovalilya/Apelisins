#include <catch2/catch_test_macros.hpp>
#include <input_checkers.h>

TEST_CASE("String format is correct") {
  SECTION("Ordinary format") {
    REQUIRE(check_right_operations("") == true);
    REQUIRE(check_right_operations("+5") == true);
    REQUIRE(check_right_operations("-5") == true);
    REQUIRE(check_right_operations("123") == true);
    REQUIRE(check_right_operations("1+2+3") == true);
    REQUIRE(check_right_operations("+42-90-67-80") == true);
    REQUIRE(check_right_operations("-56+87-98-43-111") == true);
  }
  SECTION("With additional spaces") {
    REQUIRE(check_right_operations(" ") == true);
    REQUIRE(check_right_operations("56 ") == true);
    REQUIRE(check_right_operations("1  -2 -  3") == true);
    REQUIRE(check_right_operations(" 42 - 90  -67   - 80") == true);
    REQUIRE(check_right_operations("  0- 1-45  -9 -  0-3") == true);
  }
  SECTION("Incorrect operations") {
    REQUIRE(check_right_operations("+") == false);
    REQUIRE(check_right_operations("-") == false);
    REQUIRE(check_right_operations("+ -") == false);
    REQUIRE(check_right_operations("111 + + 67") == false);
    REQUIRE(check_right_operations("111 - - 67") == false);
    REQUIRE(check_right_operations(" 87 +6  - 9 + - 0") == false);
    REQUIRE(check_right_operations("  9 - 76 + 22  + 888 -  + 8") == false);
  }
  SECTION("Incorrect numbers position") {
    REQUIRE(check_right_operations("1 2") == false);
    REQUIRE(check_right_operations("5     8") == false);
    REQUIRE(check_right_operations("1  -2 5  -  3") == false);
    REQUIRE(check_right_operations(" 4 2 - 90  -67   - 80") == false);
  }
}