#include "studentass.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

bool ifVargsiukai(float galutinis){
  if (galutinis < 5) {
    return true;
  }
  else {
    return false;
  }
}

bool ifKietiakai(float galutinis){
  if (galutinis >= 5) {
    return true;
  }
  else {
    return false;
  }
}

float galutinisPaz(float vidur, float exam){
  return 0.4 * vidur + 0.6 * exam;  
}

TEST_CASE("ifVargsiukai") {
  REQUIRE(ifVargsiukai(5) == false);
  REQUIRE(ifVargsiukai(3) == true);
  REQUIRE(ifVargsiukai(6) == false);
  REQUIRE(ifVargsiukai(1) == true);
  REQUIRE(ifVargsiukai(9) == false);
}

TEST_CASE("ifKietiakai") {
  REQUIRE(ifKietiakai(8) == true);
  REQUIRE(ifKietiakai(3) == false);
  REQUIRE(ifKietiakai(9) == true);
  REQUIRE(ifKietiakai(10) == true);
  REQUIRE(ifKietiakai(4) == false);
}

/*TEST_CASE("galutinisPaz") {
  REQUIRE(galutinisPaz(6.7, 3.0) == 4.48);
  REQUIRE(galutinisPaz(2.9, 6.0) == 4.76);
  REQUIRE(galutinisPaz(3.8, 2.0) == 2.72);
  REQUIRE(galutinisPaz(9.1, 8.0) == 8.44);
  REQUIRE(galutinisPaz(7.4, 10.0) == 8.96);
}*/

