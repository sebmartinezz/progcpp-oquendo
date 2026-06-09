#include <vector>
#include <print>
#include <cmath>
#include <cassert>

double dot (const std::vector<double>&v, const std::vector<double>&u);

int main (int argc, char **argv)
{
    std::vector<double> m= {1.234, 2.89, 3.5678};
    std::vector<double> n{4.263, 5.678, 8.9123};

    double mdotn = dot(m, n);

    std::println("{:25.16e}", mdotn);

    return 0;
}

double dot (const std::vector<double>&v, const std::vector<double>&u)
{
    assert(v.size()==u.size());
    double prod {0};

    for (int ii=0; ii<v.size(); ii++){
        prod+= v[ii]*u[ii];
    }

    return prod;

}