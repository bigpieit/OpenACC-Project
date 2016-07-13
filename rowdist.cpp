#include <Rcpp.h>
#include <math.h>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
NumericMatrix rowdist(NumericMatrix X) {
  int nrow = X.nrow();
  int ncol = X.ncol();
  NumericMatrix Xdist(nrow, nrow);
  double sum, diff;
  
  for (int i = 0; i < nrow; i++) {
    for (int j = 0; j < nrow; j++) {
      sum = 0.0;
      for (int k = 0; k < ncol; k++) {
        diff = X(i,k) - X(j,k);
        sum += pow(diff, 2.0);
      }
      Xdist(i,j) = pow(sum,0.5); 
    }
  }
  return Xdist;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//
