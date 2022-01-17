# Antra-Uzduotis

# v2.0
Sukurta dokumentacija pandaudojant Doxygen.
Unit Test'ai buvo atlikti naudojant Catch2 framework'ą:
```
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
```

