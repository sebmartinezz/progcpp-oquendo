

#include <cstdio>
#include "./numerical_calculus_.h"


double volumef (double h, double V);


int main (int argc, char **argv)
{
    //double nr (double x0, double tol, long int nmax, fptr f, dptr d, double h)
    double x0 = 2;
    double tol = 1e-5;
    long int nmax = 1e10;
    double h = 1e-10;


    for (double V = 1; V <=62; V ++){

        std::println("V: {}, h: {}", V, nr_with_v(x0, V, tol, nmax, volumef, dcentral_with_v, h));
    }

    return 0;
}

double volumef (double h, double V)
{ //ejemplo 6.16 opt2

    double R =2.0;
    double L = 5;

    double aux1 = std::acos((R-h)/R);
    double aux2 = std::sqrt(2*R*h-h*h);
    return L*(R*R*aux1- (R-h)*aux2)-V; //f(h)=0, find h

}
