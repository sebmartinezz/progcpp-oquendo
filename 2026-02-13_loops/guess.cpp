//juego de adivinar un numero
#include <iostream>
#include <random>
/*
definir un numero por parte del programa
repetir lo siguiente:
    imprimir un msj pidiendo el numero
    leer el numero
    si el numero leido es mayor al que defini entonces imprimir el numero es mayor
    si es menor imprimir es menor
    si es igual:premio, terminar iteració

*/

void guess_game(void);


int main (void)
{
    guess_game();

    return 0;
}


//implementar
void guess_game(void)
{


    std::mt19937 gen(10);
    std::uniform_int_distribution<int> dist(1, 100);
    int rand = dist(gen);


    int x = -rand;
    std::cout<<"ingresa un numero\n";
    std::cin>>x;

        while (x!=rand)
        {
            if (x>rand){
                std::cout<<"el número que ingresaste es mayor al random\n";
            }else{
                std::cout<<"el número que ingresaste es menor al random\n";
            }

        std::cout<<"ingresa otro número\n";//change
        std::cin>>x;
        }

    std::cout<<"ganasteeeeee\n";

    return;//salir a main
}