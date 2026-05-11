#include <string>
#include "./pg.h"

int main(int argc, char **argv)
{


    for (long n = 1; n <= 20; n++)
    {
        long x = pg(n);
        double norma = std::sqrt(std::pow(x, 2) + std::pow(x+2, 2));

        std::println("{} {:25.16e}", n, norma);
    }
    return 0;


}