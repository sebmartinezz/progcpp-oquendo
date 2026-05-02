
#include <print>
#include "./numerical_calculus.h"

double fun(double x); // 1d function
double g (double x);

int main (int argc, char *argv[])
{
  double x = 10.234;
  double h = 1.0e-6;
  double p_for = 1.0;
  double p_cen = 2.0;

  std::println("forward: {}", dforward(x, h, fun));
  std::println("central: {}", dcentral(x, h, fun));
  std::println("richardson forward: {}", richardson_forward(x, h, p_for, fun));
  std::println("richardson central {}", richardson_central(x, h, p_cen, fun));
  
  return 0;
}

double fun(double x)
{
  return 2*std::sin(x*x) + 4/(x*x);
}

double g (double x){
  return std::cos(x+1)+2*x*x*x*x;
}