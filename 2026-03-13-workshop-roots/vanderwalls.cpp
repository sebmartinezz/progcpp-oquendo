//goal:encontrar el volumen en la ecuación de van der walls
//(p+a/v^2)(v-b)=RT
#include <print>
#include <cmath>


double fun (double v);
double df_central (double x, double h);
double newton_raphson ( double x0, double eps, long nmax);

int main(int argc, char **argv){

    double V = newton_raphson(1 , 1.0e-10, 1000);
    std::println("the volume is {:25.16e} {}", V, fun (V));
    return 0;
}

double fun (double x){ //x=volumen

    const double A = 3.592;
    const double B = 0.04267;
    const double R = 0.08206;
    const double P = 10.0;
    const double T = 300.0;

    return (P+A/(x*x))*(x-B)-R*T;
}


double df_central(double x, double h){

    return (fun(x+h)-fun(x-h))/(2*h);
}

double newton_raphson ( double x0, double eps, long nmax){

    double x1{0};

    if (std::fabs(fun(x0))<=eps){
        return x0;
    }
    
    for(long iter = 0; iter < nmax; iter++){
    
        x1 = x0 - fun(x0)/df_central(x0, 0.01);

        if (std::fabs(fun(x1))<=eps){
            return x1;
        }else{
            x0=x1;
        }
    }
    std::println("max iter reached");
    return x1;
}