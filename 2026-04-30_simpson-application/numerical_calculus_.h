
#pragma once //resuelve el problema de incluirlo varias veces
#include <functional>
#include <cmath>

//alias pa que quede más cortico
using fptr = std::function<double(double)>; //function pointer
using dptr = std::function<double(double, double, fptr)>; //deriv pointer
using Iptr = std::function<double(double, double, int, fptr)>;

double dforward(double x, double h, fptr f);
double dcentral(double x, double h, fptr f);
double richardson (double x, double h, int p, fptr f, dptr d);
double trapezoidal (double a, double b, int ninter, fptr f);
double simpson (double a, double b, int ninter, fptr f);
double richardson_integrals (double a, double b, int n, int p, fptr f, Iptr I);