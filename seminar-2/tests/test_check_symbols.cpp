#include <catch2/catch_test_macros.hpp>
#include <input_checkers.h>

TEST_CASE("Symbol recognition works correctly") {
  SECTION("Acceptable symbols") {
    REQUIRE(check_symbols("") == true);
    REQUIRE(check_symbols("123") == true);
    REQUIRE(check_symbols("   ") == true);
    REQUIRE(check_symbols("+-+-") == true);
    REQUIRE(check_symbols("1+ 2 + 3  5 3 - 0") == true);
    REQUIRE(check_symbols("1-2+ 3  8888-6 +52") == true);
    REQUIRE(check_symbols("101-45 ++ -6---7-3") == true);
  }
  SECTION("Unacceptable symbols") {
    REQUIRE(check_symbols("2.7") == false);
    REQUIRE(check_symbols("2*7") == false);
    REQUIRE(check_symbols("(2+7)*6/8") == false);
    REQUIRE(check_symbols("1-2+3-6+52 _") == false);
    REQUIRE(check_symbols("101 &_+ -45  ?-67-3q") == false);
    REQUIRE(check_symbols("11 $ %  + 9_ hello world") == false);
  }
}