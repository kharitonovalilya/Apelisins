#include <catch2/catch_test_macros.hpp>
#include <input_checkers.h>

TEST_CASE("Creating new string without spaces works correctly") {
  SECTION("Getting a correct string") {
    REQUIRE(esc_erase("") == "");
    REQUIRE(esc_erase("   ") == "");
    REQUIRE(esc_erase("123") == "123");
    REQUIRE(esc_erase("+  -+") == "+-+");
    REQUIRE(esc_erase("52-101") == "52-101");
    REQUIRE(esc_erase("178 +   56") == "178+56");
    REQUIRE(esc_erase("123  + 89 - 0") == "123+89-0");
    REQUIRE(esc_erase("   56  - 78 + 0") == "56-78+0");
  }
}