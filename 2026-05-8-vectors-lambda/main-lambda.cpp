#include <cmath>
#include <print>
#include "numerical_calculus.h"

double fun(double x); // 1d function
double foo (double x, double lambda); //no se podría integrar, es 2d


int main (int argc, char *argv[])
{
  double A = 0.0;
  double B = 1.0;
  double ALPHA = 2.9;


  auto faux = [ALPHA](double x){ return foo(x, ALPHA); }; 
  double g5 = gauss5(A, B, faux);
 
  std::println("{:24.16e}", g5);
  
  return 0;
}

double fun(double x)
{
  return 2*std::exp(-x*x)/std::sqrt(M_PI);
}


double foo(double x, double alpha)  // 2d function
{
  return alpha*std::exp(-alpha*x);
}