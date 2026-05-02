#include <print>
#include<cmath>

bool isprime (long n);
long sumprimes (long m);

int main (int argc, char **argv){
    
    long a = std::stol(argv[1]);
    std::println("{}", sumprimes(a));

    return 0;
}


bool isprime (long n){
    
    if (n<=1){
        return false;
    }

    for (long ii=2; ii<=std::sqrt(n); ii++){

        if (n%ii == 0){
            return false;
        }
    }
    return true;
}

long sumprimes (long m){

    long sum = 0;
    
    for (long jj=0; jj<m; jj++){
        if (isprime(jj)){
            sum+=jj;
        }
    }
    return sum;

}