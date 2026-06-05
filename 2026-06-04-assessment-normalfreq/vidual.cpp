#include <print>
#include <eigen3/Eigen/Dense>
#include <complex>
#include <cmath>
#include <iostream>

//El codigo se ejecuta sin la bandera -I ya que tiene el eigen3 en el #include

void solvesystem(double k, double m1, double m2); //Funcion que resuelve el problema de los valores propios

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "ERROR.\nUsage:\n" << argv[0] << " K M1 M2\n"; //Si escribes mas o menos argumentos de los solicitados el programa no se ejecutara
    return 1;
  }

  //Para poder ver todos los resultados respecto a la variacion de m1 porfavor escribir en la linea de comandos:
  //for m in 1.0 2.0 4.0 8.0 10.0 16.0 20.0 30.0 35.0 38.0 40.0 42.0 45.0 48.0 50.0 55.0 80.0 100.0 150.0 200.0 300.0 400.0 500.0 600.0 800.0; do ./a.out 200 $m 40; done
  //Esto evitara que se tenga que ejecutar 26 veces el programa para ver los resultados en todo el rango a explorar

  const double K  = std::stod(argv[1]); //N/m -->Guardamos los argumentos en la linea de comandos
  const double M1 = std::stod(argv[2]); //kg
  const double M2 = std::stod(argv[3]); //kg
  std::println("k:{}\tM1:{}\tM2:{}", K, M1, M2);
  solvesystem(K, M1, M2);//-->Llamamos a la funcion
  return 0;
}

void solvesystem(double k, double m1, double m2)
{
  double aux1 = (2.0*k)/m1;
  double aux2 = -k/m1;
  double aux3 = -k/m2;
  double aux4 = (2.0*k)/m2;
  Eigen::Matrix2d M;
  M << aux1, aux2, aux3, aux4;//-->Creamos la matriz a la que vamos a hallar los valores propios
Eigen::EigenSolver<Eigen::Matrix2d> es(M);//-->Hallamos los valores propios
Eigen::VectorXd V(2);
V(0) = es.eigenvalues()[0].real();
V(1) = es.eigenvalues()[1].real();//--> Creamos un vector que guarda los valores propios
if(m1 >= 42){std::cout << "Frecuencias normales de oscilacion: " << std::sqrt(V[1]) << " , " << std::sqrt(V[0]) << std::endl;}//Agregamos un if para que organizar las ramas de las graficas y que Eigen no genere esa X al ordenar de mayor a menor, generando un cruzamiento.
else{std::cout << "Frecuencias normales de oscilacion: " << std::sqrt(V[0]) << " , " << std::sqrt(V[1]) << std::endl;}//-->Imprimimos la raiz cuadrada de cada valor propio 


}