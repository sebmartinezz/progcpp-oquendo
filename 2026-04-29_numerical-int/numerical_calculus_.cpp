
#include "./numerical_calculus_.h"

double dforward(double x, double h, fptr f)
{
  return (f(x+h) - f(x))/(h);
}

double dcentral(double x, double h, fptr f)
{
  return (f(x+h) - f(x-h))/(2*h);
}


double richardson (double x, double h, int p, fptr f, dptr d)
{
  double aux1 = d(x, h, f);
  double aux2 =d(x, h/2, f);
  double aux3 = std::pow(2, p);

  return (aux3*aux2 - aux1)/(aux3-1);

}

double trapezoidal (double a, double b, int ninter, fptr f){

  double h = (b-a)/ninter;
  double sum = 0;

  for (int k=1; k<=ninter-1; k++){

    sum += f(a+k*h);
  }

  return h*((f(a)+f(b))/2 + sum);
}

