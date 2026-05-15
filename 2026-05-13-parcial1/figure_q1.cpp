#include <cmath>
#include <print>
#include <string>


long sum_digits ( long n);

int main(int argc, char **argv){
    
    for (long n = 2; n<=100; n++){
        std::println("{:10} {:10}", n, sum_digits(n));   
    }
    return 0; 
}

long sum_digits(long n){

    std::string N = std::to_string(n);
    long length = N.length();
    long suma {0};

    for (float i = 0.0; i <length; i++){

        long h = std::pow (10, length-i);
        long d = std::pow(10, length-1-i);
        long digito= (n%h)/d;
        suma += digito;
    }
    return suma;
}