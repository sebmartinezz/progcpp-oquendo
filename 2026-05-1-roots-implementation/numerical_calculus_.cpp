
#include "./numerical_calculus_.h"

//derivs

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
  double aux2 =d(x, h/2, f); //en richardson cambia h
  double aux3 = std::pow(2, p);

  return (aux3*aux2 - aux1)/(aux3-1);
}


//integrals

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


//roots

double bracketing (double xmin, double xmax, double toler, long int nmax, fptr f){

  double r{0};

  for (long int niter = 0; niter <= nmax; niter ++){

    r = (xmax + xmin)/2;

    if (f(r)<=toler){
      return r;
    }
    else if (f(r)*f(xmin)<0){
      xmax = r;
      r = (xmin+xmax)/2;
    }
    else if (f(r)*f(xmin)>0){
      xmin = r;
      r = (xmin+xmax)/2;
    }
  }

  std::println("max iter reached");
  return r;
}


double nr (double x0, double tol, long int nmax, fptr f, dptr d, double h){

  if (std::fabs(f(x0))<=tol){
    return x0;
  }

  double x1{0};

  for (long niter=0; niter <= nmax; niter++){

    if (std::fabs(d(x0, h, f))<1e-15){

      std::println("deriv nula en x0");
      return x0;

    }

    
    double aux0 = f(x0)/d(x0, h, f);
    x1 = x0 - aux0;

    if (std::fabs(f(x1))<=tol){
      return x1;
    }else{
      x0=x1;
    }
  }
  std::println("max iter reached");
  return x1;
}
