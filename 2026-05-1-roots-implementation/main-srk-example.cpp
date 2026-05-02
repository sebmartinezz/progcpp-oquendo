

#include <cstdio>
#include "./numerical_calculus_.h"

double srkf (double x);


int main (int argc, char **argv)
{

    //nr :double x0, double tol, long int nmax, fptr f, dptr d, double h

    double x0 = 10;
    double tol = 1e-5;
    long int nmax = 1e4;
    double h = 1e-5;
    std::println("specific volume: {}", nr(x0, tol, nmax, srkf, dcentral, h));
    return 0;
}

double srkf (double x){ //x es v gorro en el ejemplo

    //valores para el metano
    double R = 8.205;
    double t_c = 190.7;
    double p_c = 45.8;
    double w = 0.008;

    double T=-40+273; //en kelvin xd
    double V = 3;
    double P = 50;

    //valores para skr
    double m = 0.48508 + 1.5517*w - 0.1561*w*w;
    double a = 0.42747*R*t_c*R*t_c/p_c;
    double b = 0.08664*R*t_c/p_c;
    double alpha =(1+m*(1-std::sqrt(T/t_c)))*(1+m*(1-std::sqrt(T/t_c)));

    return (R*T/(x-b))- (alpha*a/(x*(x-b))) - P;
}