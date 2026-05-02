#include <print>
#include<cmath>

void sumsqr (long N);

int main(int argC, char **argv){
/*
    long n = std::stol(argv[1]);
      for (long k=0; k<=n; k++){
        sumsqr(k);
      }  


    return 0;
*/
    long n = std::stol(argv[1]);
    sumsqr(n);

}

void sumsqr (long N){
    long sum = 0;
    for(long ii=1; ii<N; ii++){
        sum += ii*ii;
        std::println("{}\t{}", ii+1, sum);
    }

}