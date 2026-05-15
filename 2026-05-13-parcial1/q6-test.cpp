#include <iostream>

int main(){

    int x = 5;
    int y = 10;
    int z;

    z= x+y;
    std::cout << "la suma de x e y es: " << z << std::endl;

    if (z>10){

        std::cout << "z es mayor que 10." << std::endl;
    } else{
        std::cout << "z no es mayor que 10." << std::endl;
    }


}