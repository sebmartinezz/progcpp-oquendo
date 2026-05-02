
#include <print>
#include <cstdio>
#include "./numerical_calculus_.h"


//1. cómo calculo el teorico
//2. cómo imprimo mi tabla de datos
//3. cómo hago el plot

double fun(double x); // 1d function
double deriv_teo (double x);
void print (std::string fname);

int main (int argc char **argv)
{
  print("errores.txt");
  return 0;
}



double fun(double x)
{
  return 2*std::sin(x*x) + 4/(x*x);
}

double deriv_teo(double x)
{
  return 4*x*std::cos(x*x)- 8.0/(x*x*x);
}



void print (std::string fname){

  double x = 10.234;
  double t = deriv_teo(x);

  FILE * file = std::fopen(fname.c_str(), "w");

  for (int n=-20; n<=-1; n++)
  {
    if (t==0){
      continue;
    }
    double h= std::pow( 10.0, n);
    double f = dforward(x, h, fun);
    double rf = richardson(x, h, 1, fun, dforward);
    double c = dcentral(x, h, fun);
    double rc = richardson(x, h, 2, fun, dcentral);

    double e_f = std::abs(1-f/t);
    double e_rf = std::abs(1-rf/t);
    double e_c = std::abs(1-c/t);
    double e_rc = std::abs(1-rc/t);


    std::println(file, "{:25.5e} {:25.16e} {:25.16e} {:25.16e} {:25.16e}", h, e_f, e_rf, e_c, e_rc);

  }
  std::fclose(file);

}
