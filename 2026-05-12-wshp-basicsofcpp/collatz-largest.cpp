#include <cmath>
#include <print>

void collatz ( long n);

int main ( int argc, char **argv)
{

    long m = std::stol(argv[1]);
    collatz(m);

    return 0;
}

void collatz ( long n)
{
    long long mayor = n;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        //actualizo en cada iteración el mayor
        if (n > mayor) {
            mayor = n;
        }
    }
    std::println("{}", mayor);
}

//si fuera el numero de terminos seria un contador y yiap