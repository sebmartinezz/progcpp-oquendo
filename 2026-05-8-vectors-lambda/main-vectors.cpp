#include <cmath>
#include <print>
#include "numerical_calculus.h"

double fun(double x); // 1d function

int main (int argc, char *argv[])
{
  double A = 0.0;
  double B = 1.0;
  int NSTEPS = 10;
  double g5 = gauss5(A, B, fun);


  std::println("{:24.16e} ",g5);
  
  return 0;
}

double fun(double x)
{
  return 2*std::exp(-x*x)/std::sqrt(M_PI);
}