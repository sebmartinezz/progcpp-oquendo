
#include <print>
#include <cstdio>
#include "./numerical_calculus.h"

double fun(double x);

int main (int argc, char **argv)
{
    double A = 0.0;
    double B =1.0;
    double gausstres = gauss3(A, B, fun);
    std::println("{}", gausstres);
  return 0;
}

double fun(double x)
{
 return 2*std::exp(-x*x)/std::sqrt(M_PI);
}