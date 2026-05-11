# include <iostream>
# include <cmath>
int isprime(int m);
int largest_prime_factor(int m);
int main(void)
{
std::cout << largest_prime_factor(9) << std::endl;
std::cout << largest_prime_factor(97) << std::endl;
std::cout << largest_prime_factor(100) << std::endl;
std::cout << largest_prime_factor(12345) << std::endl;
std::cout << largest_prime_factor(1000099) << std::endl;
std::cout << largest_prime_factor(5412345) << std::endl;
//std::cout << largest_prime_factor(95412341) << std::endl;
//std::cout << largest_prime_factor(35412347) << std::endl;
//std::cout << largest_prime_factor(835412343) << std::endl;
return 0;
}
int isprime(int m)
{
    if(m<=1){
        return false;
    }

    for(long i = 2; i <= std::sqrt(m)+1 ; i++){ //para mayores a sqrt(n) ya verifiqué con los menores, +1 para que no se trunque

        if(m%i==0){
            return 0;
        }
    }
    return 1;
}
int largest_prime_factor(int m)
{
    for (long j = m; j>=1; j--){

        if (isprime(j)==1 && m%j == 0){
            return j;
        }
    }
    return 1;
}