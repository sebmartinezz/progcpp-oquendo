
#pragma once //resuelve el problema de incluirlo varias veces
#include <functional>
#include <cmath>
#include <print>
#include <vector>


//alias pa que quede más cortico
using fptr = std::function<double(double)>; //1d function pointer
using dptr = std::function<double(double, double, fptr)>; //deriv pointer
using Iptr = std::function<double(double, double, int, fptr)>;


double dforward(double x, double h, fptr f);
double dcentral(double x, double h, fptr f);
double richardson_derivs (double x, double h, int p, fptr f, dptr d);



double trapezoidal (double a, double b, int ninter, fptr f);
double simpson (double a, double b, int ninter, fptr f);
double richardson_integrals (double a, double b, int n, int p, fptr f, Iptr I);
double gauss3 (double a, double b, fptr f);
double gauss5(double a, double b, fptr f);
double gauss11(double a, double b, fptr f);

double bracketing (double xmin, double xmax, double toler, long int nmax, fptr f); //si ya se onta
double nr (double x0, double tol, long int nmax, fptr f, dptr d, double h);