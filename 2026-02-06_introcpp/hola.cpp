// This is a comment
#include <print> // uses the modern print, c++23
#include <vector>

int main(void) //Inicia el programa
{
    //std::println("Hello world");

    int a =9; //32b
    long int b=9; //64b
    float x=-0.987; //6 cifras
    double y= 1.1234e56; //15 cifras
    bool flag=7; //true


    std::println("{:.15e}", y);

    std::vector<double> data(5);
    data[3] = -9.85e10; //indices empiezan en 0
    return 0;
}