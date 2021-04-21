#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "vector.hh"
#include "matrix.hh"
#include "prostokat.h"

// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.
TEST_CASE("konstruktor bez parametryczny ") {
    double argumentsV1[] = {0.0, 0.0};
    
    Vector x=Vector(argumentsV1);
   Vector t=Vector();
  
   
    CHECK(x == t);
}
TEST_CASE("dodawanie wektorow") {
    double argumentsV1[] = {1.0, 2.0};
    double argumentsV2[] = {1.0, 2.0};
    double argumentsV3[] = {2.0, 4.0};
    Vector x=Vector(argumentsV1);
   Vector t=Vector(argumentsV2);
   Vector y=Vector(argumentsV3);
   Vector a=x+t;
    CHECK(a == y);
}
TEST_CASE("odejmowanie wektorow") {
    double argumentsV1[] = {2.0, 3.0};
    double argumentsV2[] = {1.0, 2.0};
    double argumentsV3[] = {1.0, 1.0};
    Vector x=Vector(argumentsV1);
   Vector t=Vector(argumentsV2);
   Vector y=Vector(argumentsV3);
   Vector a=x-t;
    CHECK(a == y);
}
TEST_CASE("dodawanie wektorow zaokraglanie") {
    double argumentsV1[] = {1.0, 2.0};
    double argumentsV2[] = {1.0, 2.0};
    double argumentsV3[] = {1.999999, 4.0};
    Vector x=Vector(argumentsV1);
   Vector t=Vector(argumentsV2);
   Vector y=Vector(argumentsV3);
   Vector a=x+t;
   WARN_THROWS(a == y);
}
TEST_CASE("Mnozenie wektorow") {
    double argumentsV1[] = {1.0, 2.0};
    double argumentsV2[] = {2.0, 4.0};
   
    Vector x=Vector(argumentsV1);
   Vector t=Vector(argumentsV2);
  
   Vector a=x*2;
  CHECK(a == t);
}
TEST_CASE("Operator indeksowania") {
    double argumentsV1[] = {1.0, 2.0};
    int a;
   
    Vector x=Vector(argumentsV1);
   
  a=x[1];
 
  CHECK(a == 2);
}
TEST_CASE("Operator indeksowania wektora") {
    double argumentsV1[] = {1.0, 2.0};
    
   
    Vector x=Vector(argumentsV1);
   
std::ostringstream out ;
out << x;
std::cout << out.str() << std::endl;
CHECK( "1 2.0000000000 "== out.str() );
}
TEST_CASE("konstruktor bezparametryczny macierzy") {
  Matrix macierz=Matrix();
 double i ;
 i=macierz(1,1);
    
   

CHECK( i== 0 );
}
TEST_CASE("mnozenie macierzy przez wektor") {
  Matrix macierz=Matrix(90);
    double argumentsV1[] = {1.0, 2.0};
    double argumentsV2[] = {-2, 1};
    Vector odpowiedz=Vector(argumentsV2);
Vector wek=Vector(argumentsV1);
Vector wynik=macierz*wek;
    
   

CHECK( wynik== odpowiedz );
}