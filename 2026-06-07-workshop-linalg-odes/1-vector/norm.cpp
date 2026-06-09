#include <vector>
#include <print>
#include <cmath>

double norm (const std::vector<double>&v);

int main (int argc, char **argv)
{
    std::vector<double> u= {1, 2, 3};
    double N = norm(u);
    std::println("{:25.16e}", N);

    return 0;
}

double norm (const std::vector<double>&v)
{
    double n {0};
    for (int ii=0; ii<v.size(); ii++){
        n+=v[ii]*v[ii];
    }
    n=std::sqrt(n);
    return n;

}