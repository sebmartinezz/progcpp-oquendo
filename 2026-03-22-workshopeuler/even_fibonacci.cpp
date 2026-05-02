#include <print>
#include <cmath>

long fibonacci(long nmax);

int main (int argc, char **argv){

    long Nmax = std::stol(argv[1]);
    long suma = fibonacci (Nmax);

    std::println("{}", suma);

    return 0;
}

long fibonacci (long nmax){

    long a{1}, b{2};
    std::print ("{} {} ", a, b);

    long sum{2};

    while (b<=nmax){
        long c = a+b;

        if (c>nmax){
            break;
        }

        if (c%2==0){
            sum +=c;
        }

        std::print("{} ", c);
        a=b;
        b=c;
    }

    std::println("");
    return sum;

}
