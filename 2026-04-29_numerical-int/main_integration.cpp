
#include <print>
#include <cstdio>
#include "./numerical_calculus_.h"

double fun(double x);

int main (int argc, char **argv)
{
  std::println("{}", trapezoidal (0.0, 1.0, 1000, fun));
  return 0;
}

double fun(double x)
{
  return std::pow(x, 2);
}