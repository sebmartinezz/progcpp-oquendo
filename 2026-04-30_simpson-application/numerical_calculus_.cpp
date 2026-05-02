
#include "./numerical_calculus_.h"

double dforward(double x, double h, fptr f)
{
  return (f(x+h) - f(x))/(h);
}

double dcentral(double x, double h, fptr f)
{
  return (f(x+h) - f(x-h))/(2*h);
}


double richardson_derivs (double x, double h, int p, fptr f, dptr d)
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

double simpson (double a, double b, int ninter, fptr f){

  if (ninter%2!=0){
    ninter ++;
  }
  double h {(b-a)/ninter}; //partición uniforme
  double sum1 = 0;
  double sum2 = 0;
  double total = 0;

  for (int i = 1; i<= (ninter/2); i++){

    sum1 +=f(a+(2*i-1)*h);
  }
  for (int j = 1; j<= ((ninter/2)-1); j++){

    sum2 +=f(a+(2*j)*h);
  }

  total = h/3* (f(a)+ 4*sum1 +2*sum2+f(b));
  return total;
}

double richardson_integrals (double a, double b, int n, int p, fptr f, Iptr I)
{
  double aux1 = I(a, b, n, f);
  double aux2 =I(a, b, 2*n, f); //ACA CAMBIA EL PASO
  double aux3 = std::pow(2, p);

  return (aux3*aux2 - aux1)/(aux3-1);

}