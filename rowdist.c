#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

/*   Matrix Print    */
void matprint(double *a,int row,int col) {
	int i,j;
  	for (i = 0; i < row; i++ ) {
		for (j = 0; j < col; j++) {
      			printf("%lf ",a[i*col+j]);
    		}
    		printf("\n");
  	}
}



int main(int argc, char **argv) {
	/*     Input     */
	char *filename = argv[1];

  	/*   Read (nrow*ncol)-dimension-matrix from File  */
  	double *restrict X;
	double *restrict Xdist;
  	FILE *file = fopen(filename,"r");
  	int nrow, ncol, i;
  	fscanf(file,"%d", &nrow);
  	fscanf(file,"%d", &ncol);
	int Xlen, Xdistlen;
	Xlen = nrow * ncol;
	Xdistlen = nrow * nrow;
	/*double X[12];
	double Xdist[12];*/
  	size_t size = Xlen * sizeof(double);
  	X = (double *) malloc(size);
	size_t size_dist = Xdistlen * sizeof(double);
	Xdist = (double *) malloc(size_dist);
	
	for (i = 0; i < ncol * nrow; i++) {
		fscanf(file,"%lf",&X[i]);
  	}

	/*  Row Distance  */
	double sum;
	double diff;
	int j, k;
	
	#pragma acc data copy(X[0:Xlen], Xdist[0:Xdistlen])
	#pragma acc kernels 	
	{
		for (i = 0; i < nrow; i++) {
			for (j = 0; j < nrow; j++) {
				sum = 0.0;
				for (k = 0; k < ncol; k++) {
					diff = X[j*ncol + k] - X[i*ncol+k];
					sum += pow(diff, 2); 
				}	
				sum = pow(sum, 0.5);
				Xdist[i*nrow + j] = sum;
			}	
		}
	}	

	/*  Matrix Print  */
	printf("X     : \n");
	matprint(X, nrow, ncol);
	printf("Xdist : \n");
	matprint(Xdist, nrow, nrow);
	return 0;
}
