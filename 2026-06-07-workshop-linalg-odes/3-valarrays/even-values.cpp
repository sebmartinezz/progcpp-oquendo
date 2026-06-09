#include <valarray>
#include <cmath>
#include <print>
#include <cassert>
#include<random>

double mean_even_values (const std::valarray<int>&v, std::valarray<int>&evenv);

int main(int argc, char **argv){

    int n = std::stoi(argv[1]);

    std::mt19937 gen(0);
    std::uniform_int_distribution<int> dis (1000, 2500);

    std::valarray<int> u(0.0, n);
    for (int ii=0; ii<n; ii++){
        u[ii]=dis(gen);
    }
    //tenemos un random valarray u

    std::valarray<int> evenu;
    double mean_even_u = mean_even_values(u, evenu);

    std::println("{} {} {}", u, evenu, mean_even_u);
    return 0;
}
double mean_even_values (const std::valarray<int>&v, std::valarray<int>&evenv){
    evenv = v[v%2==0];
    double sum{0};
    for (int ii=0; ii<evenv.size(); ii++){
        sum+=evenv[ii];
    }
    double mean = sum/evenv.size();
    return mean;
}