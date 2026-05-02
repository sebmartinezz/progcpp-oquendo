
#pragma once //resuelve el problema de incluirlo varias veces
#include <functional>
#include <cmath>

//alias pa que quede más cortico
using fptr = std::function<double(double)>; //function pointer
using dptr = std::function<double(double, double, fptr)>; //deriv pointer

double dforward(double x, double h, fptr f);
double dcentral(double x, double h, fptr f);
double richardson (double x, double h, int p, fptr f, dptr d);