#include <print>
#include <iostream>
#include <cmath>

bool prime (long n);
void sexyprimessmaller(long n);


int main(int argC, char **argv)
{
    
    long m =std::stol(argv[1]);
    sexyprimessmaller(m);

    return 0;
}


bool prime (long n){

    if(n<=1){
        return false;
    }

    for(long i = 2; i <= std::sqrt(n)+1 ; i++){ //para mayores a sqrt(n) ya verifiqué con los menores, +1 para que no se trunque

        if(n%i==0){
            return false;
        }
    }
    return true;
}

void sexyprimessmaller (long n){


    for (long ii=0; ii<= n; ii++){

        if (prime(ii) && prime(ii+6)){
            std::println("{} {}", ii, ii+6);
        }
    }

}
