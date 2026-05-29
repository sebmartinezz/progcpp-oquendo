#include <iostream>
#include <valarray>
#include <cmath>
#include <string>
#include <print>

std::valarray<double> rotar(const std::valarray<double>& v, const std::valarray<double>& theta); 
std::valarray<double> multiply(const std::valarray<double>& M, const std::valarray<double>& v);


int main(int argc, char** argv) //recoge lo que pone en la consola
{

    std::valarray<double> v = {std::stod(argv[1]), std::stod(argv[2]), std::stod(argv[3])}; //compila de lo que ponen y crea el vector

    std::valarray<double> theta = {std::stod(argv[4]), std::stod(argv[5]), std::stod(argv[6])}; //crea el vector de los angulos

    std::valarray<double> vR = rotar(v, theta); //el vector rotado que sale de la funcion

    std::println("Vector rotado: [{}, {}, {}]", vR[0], vR[1], vR[2]);

    return 0;
}


std::valarray<double> rotar(const std::valarray<double>& v, const std::valarray<double>& theta)
{

    std::valarray<double> Rx = { //matriz en x
        1, 0, 0,
        0, cos(theta[0]), -sin(theta[0]),
        0, sin(theta[0]), cos(theta[0])
    };

    std::valarray<double> Ry = { //matriz en y
        cos(theta[1]), 0, sin(theta[1]),
        0, 1, 0,
        -sin(theta[1]), 0, cos(theta[1])
    };

    std::valarray<double> Rz = { //matriz en z
        cos(theta[2]), -sin(theta[2]), 0,
        sin(theta[2]), cos(theta[2]), 0,
        0, 0, 1
    };

    std::valarray<double> vfinal = multiply(Rx, v); //coge la matriz Rx y v, los manda a multiply, multiply regresa el vector rotado en x
    vfinal = multiply(Ry, vfinal); //coge ese resultado anterior, lo vuelve a mandar a multiply con Ry y los multiplica
    vfinal = multiply(Rz, vfinal); //coge el resultado en y y lo vuelve a mandar con Rz

    return vfinal; //devuelve el nuevo vector con tres partes x, y y z
}

std::valarray<double> multiply(const std::valarray<double>& M, const std::valarray<double>& v) //multiplioc la matriz por el vector
{
    return std::valarray<double>{
        M[0]*v[0] + M[1]*v[1] + M[2]*v[2], M[3]*v[0] + M[4]*v[1] + M[5]*v[2], M[6]*v[0] + M[7]*v[1] + M[8]*v[2]
    };
}

