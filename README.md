# Antra-Uzduotis
# v1.1
* Šioje versijoje pakeista v1.0 (iš pirmos užduoties) buvusį struct studentas į class studentas.
* Palyginta programos, naudojanti struct iš v1.0 ir programos, naudojanti class iš v1.1 (dabartinė versija) realizacijos sparta, naudojant vieną fiksuotą konteinerį: vektorių.
* Testvimas atliktas su 10 pažymių:
![o3](https://user-images.githubusercontent.com/90559062/149841169-58348263-cde5-45e8-8b04-6a23e9034c9a.png)

* Taip pat atlikta eksperimentinė analizė priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us:
* Flag O1 (testavimas atliktas su 10 pažymių):
![1 1](https://user-images.githubusercontent.com/90559062/149841231-e1dbe278-a2e2-42a8-a13c-b8c371f2befa.png)
* Flag O2 (testavimas atliktas su 10 pažymių):
![o2](https://user-images.githubusercontent.com/90559062/149841216-cdaccbcb-ba1c-4ad2-b7f0-490a9c9455bd.png)
* Flag O3 - primojo testo rezultatai. 

# v1.2
Realizuoti operatoriai:
* copy constructor;
* copy assignment operator;
* destructor;
* lyginimo operatoriai.

# v1.5
Vietoj vienos Studentass klasės, sukurtos dvi klasės:
* bazinė klasė: Asmuo;
* išvestinė klasė: Studentass.

Klasė Asmuo yra abstarkti klasė.

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

