#include <print>
#include <iostream>
#include <cmath>

bool prime (long n);

int main(int argC; char **argv)
{
    
    long n =10000000019;
//    std::cin>>n;
    std::println("{}", prime(n));

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