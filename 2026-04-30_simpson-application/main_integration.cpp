
#include <print>
#include <cstdio>
#include "./numerical_calculus_.h"

double fun(double x);
double int_teo_fun (double x);


int main (int argc, char **argv)
{
  double a = 0.0;
  double b = 1.0;
  double t = int_teo_fun(b)-int_teo_fun(a); //valor teórico de la integral

    for (int n=1; n<=500; n++)
  {

    double h = (b-a)/n;

    double trap = trapezoidal(a, b, n, fun);
    double simp = simpson(a, b, n, fun);
    double traprich = richardson_integrals(a, b, n, 2, fun, trapezoidal);
    double simprich = richardson_integrals(a, b, n, 4, fun, simpson);

    double e_trap = std::abs(1-trap/t);
    double e_simp = std::abs(1-simp/t);
    double e_traprich = std::abs(1-traprich/t);
    double e_simprich = std::abs(1-simprich/t);


    std::println("{:25.5e} {:25.16e} {:25.16e} {:25.16e} {:25.16e}", h, e_trap, e_simp, e_traprich, e_simprich);

  }
  return 0;
}

double fun(double x){
  
  return std::cos(x);

}
double int_teo_fun (double x){
  return::sin(x);
}
