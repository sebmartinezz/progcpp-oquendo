#include <cmath>
#include <print>
#include "numerical_calculus.h"


double foo(double x, double y);

int main (int argc, char *argv[])
{
  double A = 0.0;
  double B = 1.0;
  
  for (double Y = 0; Y <= 15; Y++){

    auto fooaux = [Y](double x){
      return foo(x, Y);
    };

    double g11 = gauss11(A, B, fooaux);
    double teo = 1 + Y;
    std::println("{:25.16e} {:25.16e} {:25.16e}", Y, g11, teo);
  }

  return 0;
}


double foo (double x, double y){

  return 2*x+y;
}