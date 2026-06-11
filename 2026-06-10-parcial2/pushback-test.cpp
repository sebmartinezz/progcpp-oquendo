#include <valarray>
#include <print>
int main (){
    std::valarray<double> v (2);
    double a = 1.678;
    double b = 1.234;
    v.pushback(a);
    v.pushback(b);
    std::println("{}", v);
}