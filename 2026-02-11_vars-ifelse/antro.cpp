

#include<print>

void verificar (int age); //declarar funciones previamente


int main() {


    int edad1=15;

    verificar(edad1);

    verificar(20);

    return 0;
}


//implementar
void verificar (int age)
{
    if (age>= 18) {
        std::println("SI puede entrar");
    }else{
        std::println("No puede entrar, es menor de edad");
    }
}