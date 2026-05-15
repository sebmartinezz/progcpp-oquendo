#include <cmath>
#include <print>
#include <string>


long sum_digits ( long n);

int main(int argc, char **argv){
    long n = std::stol(argv[1]);

    std::println("{}", sum_digits(n));
    return 0;
}

long sum_digits(long n){

    std::string N = std::to_string(n);
    long length = N.length();
    long suma {0};

    for (long i=0; i <length; i++){

        long h = std::pow (10, length-i);
        long d = std::pow(10, length-1-i);
        long digito= (n%h)/d;
        suma += digito;
    }
    return suma;
}