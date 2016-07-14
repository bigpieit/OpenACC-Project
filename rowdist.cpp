#include <Rcpp.h>
#include <math.h>
using namespace Rcpp;

void compute(double *X, double* Xdist, int nrow, int ncol) {
  int i, j, k;
  double sum, diff;
  
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < nrow; j++) {
      sum = 0.0;
      for (k = 0; k < ncol; k++) {
        diff = X[i + k * nrow] - X[j + k *nrow];
        sum += pow(diff, 2);
      }
      sum = pow(sum, 0.5);
      Xdist[i + j*nrow] = sum;
    }
  }
}

// [[Rcpp::export]]
NumericMatrix rowdist(NumericMatrix x) {
  int nrow = x.nrow();
  int ncol = x.ncol();
  NumericMatrix y(nrow, nrow);
  compute(REAL(x), REAL(y), nrow, ncol);
  return y;
}

