
#include "./numerical_calculus.h"

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


double gauss3(double a, double b, fptr f)
{
  std::vector<double> w {5.0/9.0, 8.0/9.0, 5.0/9.0};
  std::vector<double> x {-std::sqrt(3.0/5.0),  0, +std::sqrt(3.0/5.0)};

  double aux1 = (b-a)/2;
  double aux2 = (b+a)/2;

  double result = 0.0;
  for (int ii = 0; ii < 3; ii++) {
    double X = aux1*x[ii] + aux2;
    result += w[ii]*f(X);
  }

  return result*aux1;  
}

double gauss5(double a, double b, fptr f)
{
  std::vector<double> w {128.0/225.0, (322.0+13.0*std::sqrt(70.0))/900.0, (322.0+13.0*std::sqrt(70.0))/900.0, (322.0-13.0*std::sqrt(70.0))/900.0, (322.0-13.0*std::sqrt(70.0))/900.0};
  std::vector<double> x {0, (1.0/3.0)*std::sqrt(5.0-2.0*std::sqrt(10.0/7.0)), -(1.0/3.0)*std::sqrt(5.0-2.0*std::sqrt(10.0/7.0)), (1.0/3.0)*std::sqrt(5.0+2.0*std::sqrt(10.0/7.0)), -(1.0/3.0)*std::sqrt(5.0+2.0*std::sqrt(10.0/7.0))};
  //es más fácil poner los números ya calculados xd

  double aux1 = (b-a)/2;
  double aux2 = (b+a)/2;

  double result = 0.0;
  for (int ii = 0; ii < 5; ii++) {
    double X = aux1*x[ii] + aux2;
    result += w[ii]*f(X);
  }

  return result*aux1;  
}

double gauss11(double a, double b, fptr f)
{

  std::vector<double> x { 0.0000000000000000, -0.2695431559523450, 0.2695431559523450, -0.5190961292068118, 0.5190961292068118, -0.7301520055740494, 0.7301520055740494, -0.8870625997680953, 0.8870625997680953, -0.9782286581460570, 0.9782286581460570};
  std::vector<double> w {0.2729250867779006, 0.2628045445102467, 0.2628045445102467, 0.2331937645919905, 0.2331937645919905, 0.1862902109277343, 0.1862902109277343, 0.1255803694649046, 0.1255803694649046, 0.0556685671161737, 0.0556685671161737};

  double aux1 = (b-a)/2;
  double aux2 = (b+a)/2;

  double result = 0.0;
  for (int ii = 0; ii < 11; ii++) {
    double X = aux1*x[ii] + aux2;
    result += w[ii]*f(X);
  }

  return result*aux1;  
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

      std::print("deriv nula en x0, devuelvo x0:");
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
