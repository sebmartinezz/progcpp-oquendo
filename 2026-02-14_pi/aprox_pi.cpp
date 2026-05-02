#include <cmath>
#include <iomanip>
#include <print>

//declara

double pi_aprox(int n);


int main(void){

    int n = 0;

    for (n=1; n<=20; n+=1){

        double pi_n = pi_aprox(n); //guarda el retorno de pi_aprox
        double error_n = std::abs(1-pi_n/M_PI);
        std::println("n: {:2d}    pi(n): {:.16e}    diferencia: {:.16e}", n, pi_n, error_n);

    }

    return 0;
}

//implementa

double pi_aprox(int n){
    double pi_n = 0.0;
    int i = 0;

    for (i=0; i<n; i+=1){

        pi_n += (1.0/std::pow(16,i))*((4.0/(8*i+1))-(2.0/(8*i+4))-(1.0/(8*i+5))-(1.0/(8*i+6)));

    }
    return pi_n;
}
