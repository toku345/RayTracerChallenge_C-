#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("dummy test", "[dummy]") {
  REQUIRE(1 == 1);
}
