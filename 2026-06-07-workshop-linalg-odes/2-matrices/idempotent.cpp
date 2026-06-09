#include <vector>
#include <cassert>
#include <print>
#include <cmath>
#include <random>

void matpow (const std::vector<double> & A, int m, int n, 
            std::vector<double>&Ap, int x, int y, int p);
void matmul (const std::vector<double>&A, int mA, int nA,
            const std::vector<double>&B, int mB, int nB,
            std::vector<double>&C, int mC, int nC);
void randomizeuniform (std::vector<double>&v, long seed);

bool idempotent (const std::vector<double>&A, int mA, int nA, int p, double eps);

int main(int argc, char **argv){

    int m = std::stoi(argv[1]);
    int P = std::stoi(argv[2]);
    double epsilon = std::stod(argv[3]);
    long s = std::stol(argv[4]);

    std::vector<double> M (m*m);
    randomizeuniform(M, s);
    
    bool b = idempotent (M, m, m, P, epsilon);
    std::println("{}", b);


    return 0;
}

void randomizeuniform (std::vector<double>&v, long seed){
    
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(0.0, 100.0);

    for (int ii = 0; ii < v.size(); ii++) {
        v[ii] = dis(gen); // Le pasamos el motor a la distribución
    }

}

bool idempotent (const std::vector<double>&A, int mA, int nA, int p, double eps){

    assert(mA==nA);
    std::vector<double> Ap (mA*nA, 0.0);
    matpow (A, mA, nA, Ap, mA, nA, p);

    for (int ii = 0; ii<mA; ii++){
        for (int jj= 0; jj<nA; jj++){
            if (std::abs(Ap[ii*nA+jj]-A[ii*nA+jj])>=eps){
                return false;
            }
        }
    }

    return true;
}

void matmul (const std::vector<double>&A, int mA, int nA,
            const std::vector<double>&B, int mB, int nB,
            std::vector<double>&C, int mC, int nC)
{
  assert(nA==mB);
  assert(mC==mA);
  assert(nC==nB);

  for (int ii = 0; ii<mC; ii++) //filas
  {
    for (int jj=0; jj<nC; jj++) //columnas
    {
      C[ii*nC+jj]=0.0;
      for (int kk=0; kk<nA; ++kk)
      {
        C[ii*nC+jj]+= A[ii*nA + kk]*B[kk*nB + jj];
      }

    }
  }
}

void matpow (const std::vector<double> & A, int m, int n, std::vector<double>&Ap, int x, int y,  int p)
{
  assert(m==n && x == y && m==x);

  std::vector<double> Id (m*n, 0.0); //matriz identidad
  for (int jj=0; jj<n; jj++){
    Id[n*jj+jj]=1.0;
  }
  if (p==0){
    Ap=Id;
    return;
  }

  Ap = A; 
  std::vector<double> aux(Ap.size());

  for (int ii=1; ii<p; ii++){
    matmul(Ap, m, n,
          A, m, n,
          aux, x, y);
    Ap=aux;
  }
}