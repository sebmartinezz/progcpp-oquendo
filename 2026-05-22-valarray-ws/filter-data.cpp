#include <valarray>
#include <cmath>
#include <print>
#include <numeric>
#include <cassert>

int main(int argc, char**argv)
{
    long N = 1000;
    const double pi = M_PI;

    std::valarray<double> v (0.0, N);

    //llenar los datos desde 0 hasta 2pi
    std::iota(std::begin(v), std::end(v), 0.0);
    v *= (2.0 * pi / (N - 1));

    std::valarray<double> filtered = v[std::abs(std::sin(v))<=0.5];

    std::println("{}", filtered);

    return 0;
}
