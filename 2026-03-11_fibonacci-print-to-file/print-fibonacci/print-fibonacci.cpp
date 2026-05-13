#include<print>
#include <cmath>
#include <cstdio>


//imprimir el n-ésimo término de fibonacci
void fibonacci (long maxterm, std::string fname);

int main (int argc, char **argv){

    long m = std::stol(argv[1]);
    fibonacci(m, "fib.txt");
    return 0;
}

void fibonacci (long maxterm, std::string fname){

    FILE * file = std::fopen(fname.c_str(), "w");

    long a{1};
    long b{2};
    std::print(file, "{} {} ", a, b);

    for (long ii=1; ii<=maxterm-2; ii++){

        long c = a+b;
        std::print(file, "{} ", c);

        a=b;
        b=c;
    }

    std::fclose(file);
}