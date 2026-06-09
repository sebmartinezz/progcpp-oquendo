#include <vector>
#include <print>
#include <cmath>
#include <cassert>

void sort (const std::vector<double>&v, std::vector<double>&sorted);

int main (int argc, char **argv)
{
    std::vector<double> u = {200.18, 4, 98, 1.21, 3, 4.5, 12, 1837678634, 4, 5.987, 12345.987};
    std::vector<double> sortedu (u.size(), 0.0);

    sort(u, sortedu);

    std::println("{} \n{}", u, sortedu);

    return 0;
}

void sort (const std::vector<double>&v, std::vector<double>&sorted){

    assert(sorted.size()==v.size());
    sorted = v;
    std::sort(sorted.begin(), sorted.end());
}