#include<iostream>

int sum_divisors(int N); //declaracion


int main()
{
    const int N1 = 10;
    std::cout<<"suma = "<<sum_divisors(N1)<<std::endl;

    const int N2 = 4;
    std::cout<<"suma = "<<sum_divisors(N2)<<std::endl;
    return 0;
}

int sum_divisors(int N) //definicion
{
    int suma = 0;

    for(int ii=2; ii<N; ii++){
        if (N%ii == 0){
            suma += ii;
        }
    }

return suma;

}