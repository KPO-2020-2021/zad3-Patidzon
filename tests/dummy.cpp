#include "../tests/doctest/doctest.h"
#include "example.h"
/*#include <iostream>
#include <cstdlib>
#include <cmath>
#include "vector.hh"
#include "matrix.hh"
#include "prostokat.h"*/
// Tests that don't naturally fit in the headers/.cpp files directly
// can be placed in a tests/*.cpp file. Integration tests are a good example.

TEST_CASE("complicated integration tests could be here")
{
  Dummy d;
  CHECK(d.doSomething() == true);
}

/*TEST_CASE("dodawanie wektorow") {
    double argumentsV1[] = {1.0, 2.0};
    double argumentsV2[] = {1.0, 2.0};
    double argumentsV3[] = {2.0, 4.0};
   Vector x=Vector(argumentsV1);
   Vector t=Vector(argumentsV2);
   Vector y=Vector(argumentsV3);
    CHECK(x-t == y);
}*/