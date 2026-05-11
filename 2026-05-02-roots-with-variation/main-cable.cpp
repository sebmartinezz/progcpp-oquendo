

#include <cstdio>
#include "./numerical_calculus_.h"

double height (double Ta, double x);


int main (int argc, char **argv)
{

    //double nr_with_v (double x0, double v, double tol, long int nmax, fptrv f, dptrv d, double h)
    double x0 = 500;
    double tol = 1e-5;
    long int nmax = 1e4;
    double h = 1e-8;

    for (double x = -150; x <= 100; x ++){

        if (std::abs(x)>22){
            std::println("x: {} Tension: {}", x, nr_with_v(x0, x, tol, nmax, height, dcentral_with_v, h));
        }
        //tensiones que mantienen y constante con x variando
    }

    return 0;
}

double height (double Ta, double x) //t being tension, x variable para graf
{
    //ejemplo 6.17 opt2

    double w =10.0;
    double y0 = 5.0;
    double y= 15;

    return Ta * std::cosh(w*x/Ta) / w + y0 - Ta/w - y;

}
