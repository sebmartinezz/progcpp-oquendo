#include <valarray>
#include <cmath>
#include <print>
#include <cassert>
#include<random>

void crossprod (const std::valarray<double>&v, const std::valarray<double>& u, std::valarray<double>&vcrossu);

int main(int argc, char **argv){

    std::valarray<double> a = {1.234, 4.876, 9.1234};
    std::valarray<double> b = {5.897, 7.654, 1.23};
    std::valarray<double> acrossb (0.0, 3);

    crossprod(a, b, acrossb);
    std::println("{} {} {}", a, b, acrossb);
    return 0;
}

void crossprod (const std::valarray<double>&v, const std::valarray<double>& u, std::valarray<double>&vcrossu){
    assert(v.size()==u.size());
    assert(u.size()==vcrossu.size());
    assert(vcrossu.size()==3);

    vcrossu[0] = v[1]*u[2]-v[2]*u[1];
    vcrossu[1] = -(v[0]*u[2]-v[2]*u[0]);
    vcrossu[2] = v[0]*u[1]-v[1]*u[0];

}