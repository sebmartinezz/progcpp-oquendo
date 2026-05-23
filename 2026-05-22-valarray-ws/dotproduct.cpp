#include <valarray>
#include <cmath>
#include <print>
#include <cassert>

void fill_valarray(std::valarray<double>&v, long s);
double dotprod (std::valarray<double>&v, long s1, std::valarray<double>&u, long s2);

int main(int argc, char**argv)
{
    long size = std::stol(argv[1]);

    std::valarray<double> a (0.0, size);
    std::valarray<double> b (0.0, size);
    fill_valarray(a, size);
    fill_valarray(b, size);
    b=b+1;
    
    double ab = dotprod(a, size, b, size);
    std::println("{} {} {}", a, b, ab);




    return 0;
}

void fill_valarray(std::valarray<double>&v, long s){

    for (int ii = 0; ii<s; ii++){
        v[ii]=ii;
    }

}
double dotprod (std::valarray<double>&v, long s1, std::valarray<double>&u, long s2){

    assert(s1==s2);
    std::valarray<double> aux (0.0, s1);
    aux = v*u;
    double dotprod = aux.sum();
    return dotprod;

}


