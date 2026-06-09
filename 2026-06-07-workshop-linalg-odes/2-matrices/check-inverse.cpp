#include <vector>
#include <cassert>
#include <print>
#include <cmath>
#include <random>

void matmul (const std::vector<double>&A, int mA, int nA,
            const std::vector<double>&B, int mB, int nB,
            std::vector<double>&C, int mC, int nC);

bool checkinverse (const std::vector<double>&A, int mA, int nA,
                    const std::vector<double>&B, int mB, int nB, double eps);

int main(int argc, char **argv){
    int m = 2;
    std::vector<double> A = {2.0, 1.0, 5.0, 3.0};
    std::vector<double> B = {3.0, -1.0, -5.0, 2.0};
    double epsilon = 1e-5;

    bool es_inversa = checkinverse(A, m, m, B, m, m, epsilon);
    std::println("{}", es_inversa);

    return 0;
}

bool checkinverse (const std::vector<double>&A, int mA, int nA,
                    const std::vector<double>&B, int mB, int nB, double eps){

    assert(mA==nB && nA==mB && mA==mB);

    std::vector<double>AB(mA*nB, 0.0);
    matmul(A, mA, nA, B, mB, nB, AB, mA, nB);
    std::vector<double>BA(mB*nA, 0.0);
    matmul(B, mB, nB, A, mA, nA, BA, mB, nA);

    std::vector<double> Id (mA*nB, 0.0);
    for (int jj=0; jj<mA; jj++){
        Id[nB*jj+jj]=1.0;
    }

    for (int ii=0; ii<mA; ii++){
        for (int jj=0; jj<nB; jj++){
            if (std::abs(AB[ii*nB+jj]-Id[ii*nB+jj])>=eps){
                return false;
            }
            if (std::abs(BA[ii*nB+jj]-Id[ii*nB+jj])>=eps){
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
