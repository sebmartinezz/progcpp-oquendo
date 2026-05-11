#include <cmath>
#include <print>
#include "numerical_calculus.h"

double fun(double x); // 1d function

int main (int argc, char *argv[])
{
  double A = 0.0;
  double B = 1.0;

  double g5 = gauss5(A, B, fun);
  double g11 = gauss11(A, B, fun);

  std::println("{:25.16e} {:25.16e}", g5, g11);
  
  return 0;
}

double fun(double x)
{
  return 2*std::exp(-x*x)/std::sqrt(M_PI);
}

double foo (double x, double y){

  return 2*x+y;
}