# OpenACC-Project

Files introduction:

1. rowdist.c
   This is a parallel c code accelerated by OpenACC. It can be compiled with Omni OpenACC compiler and run on
   CPU-GPU platform. The function reads the nrow * ncol-dimeonsion matrix from "mat.txt" file and stores it in
   an array "X". The Euclidean distance between ith row and jth row is computed and stored as the [i,j] element
   of the matrix "Xdist". The dimension of "Xdist" is nrow * nrow. It is stored as an array.

   To compile it, you should have an OpenACC compiler, for example omni(http://omni-compiler.org/openacc.html)
   the command for compilation:
		ompcc -acc -o rowdist rowdist.c
   to run:
		./rowdist mat.txt

2. mat.txt
   This is .txt file to store matrix. First line gives the row number m and column number n while the following
   are entries of the m * n matrix.

3. rowdist.cpp
   This is Rcpp file. Please run it with following commands.

 library(Rcpp) \n
 Rcpp::sourceCpp('rowdist.cpp') \n
 a = matrix(1:12, nrow = 3);
 rowdist(a)
 rowdist(a)
     [,1] [,2] [,3]
[1,]    0    2    4
[2,]    2    0    2
[3,]    4    2    0

   For any questions, please feel free to contact me at bxli at ucdavis.edu.
   Thanks!
   
   Bingxi Li
