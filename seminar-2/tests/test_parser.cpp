#include <catch2/catch_test_macros.hpp>
#include <calculate.h>

TEST_CASE("Final result is correct") {
  SECTION("Only addition") {
    REQUIRE(parse_and_count_expression("+1+2+3") == 6);
    REQUIRE(parse_and_count_expression("42+90+67+80") == 279);
    REQUIRE(parse_and_count_expression("0+1+45+9+0+3") == 58);
  }
  SECTION("Only subtraction") {
    REQUIRE(parse_and_count_expression("1-2-3") == -4);
    REQUIRE(parse_and_count_expression("42-90-67-80") == -195);
    REQUIRE(parse_and_count_expression("0-1-45-9-0-3") == -58);
  }
  SECTION("Mixed operations") {
    REQUIRE(parse_and_count_expression("-1+4-9+7") == 1);
    REQUIRE(parse_and_count_expression("101+78+9-156") == 32);
    REQUIRE(parse_and_count_expression("-56+87-98-43-111") == -221);
  }
  SECTION("Single number") {
    REQUIRE(parse_and_count_expression("0") == 0);
    REQUIRE(parse_and_count_expression("11") == 11);
    REQUIRE(parse_and_count_expression("356") == 356);
  }
}