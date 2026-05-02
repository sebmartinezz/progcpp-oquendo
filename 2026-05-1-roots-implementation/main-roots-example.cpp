

#include <cstdio>
#include "./numerical_calculus_.h"

double fun(double x);


int main (int argc, char **argv)
{
  long int nmax = 12;
  double t = 1e-15; 

  double a = -10; //para bracketing
  double b = 10;

  double x0 = -1; //para nr
  double h = 1e-10;

  std::println("{}", bracketing(a, b, t, nmax, fun));
  std::println("{}", nr(x0, t, nmax, fun, dcentral, h));

  return 0;
}

double fun(double x){

  return 10*x*x*x; //fnctn que se iguala a cero
}