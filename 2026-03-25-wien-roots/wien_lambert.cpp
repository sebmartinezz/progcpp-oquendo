#include <print>
#include <cmath>

double fun (double x, double z);
double df_central(double x, double z, double h);
double ntn_raphson(double x0, double z, double eps, long nmax);

int main (int argc, char** argv){

    for (double z = -1/M_E; z<=2; z+=0.01){
        double w0 = ntn_raphson(0.1, z, 1.0e-6, 10000);
        std::println("{} {} {}",w0, z, fun(w0, z) );
    }
    return 0;
}


double fun (double x, double z){ //x =w0 función de lambert

    return x*std::exp(x)-z;
}

double df_central(double x, double z, double h){

    return (fun(x+h, z)-fun(x-h, z))/(2*h);
}

double ntn_raphson(double x0, double z, double eps, long nmax){

    double x1{0};

    if (std::fabs(fun(x0, z))<=eps){
        return x0;
    }
    
    for(long iter = 0; iter < nmax; iter++){
    
        x1 = x0 - fun(x0, z)/df_central(x0, z, 0.01);

        if (std::fabs(fun(x1, z))<=eps){
            return x1;
        }else{
            x0=x1;
        }
    }
    std::println("max iter reached");
    return x1;

}
