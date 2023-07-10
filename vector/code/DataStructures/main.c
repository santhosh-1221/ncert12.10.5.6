#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"                 // include user-defined library that contains required functions

int main() {
    double matA[3] = { 2.0, 3.0, -1.0 };
    double matB[3] = { 1.0, -2.0, 1.0 };
    double** a = createmat(matA[0], matA[1], matA[2]);
    double** b = createmat(matB[0], matB[1], matB[2]);

    node* linkedMatrixA = constructLinkedMatrix(a, 3, 1);
    createDatMat("a.dat",linkedMatrixA);                  // include a.dat file 
   node* linkedMatrixB = constructLinkedMatrix(b, 3, 1);
createDatMat("b.dat",linkedMatrixB);                   // function for including the b.dat file   
    printf("Linked Matrix A:\n");
    printLinkedMatrix(linkedMatrixA);
    
    printf("Linked Matrix B:\n");
    printLinkedMatrix(linkedMatrixB);

    node* linkedMatrixC = constructLinkedMatrix(a, 3,1);
    matSum(linkedMatrixC, linkedMatrixB);

    printf("Linked Matrix C = A + B:\n");               // function to print the sum of two matrices A&B
    printLinkedMatrix(linkedMatrixC);

    double e = vectorNorm(linkedMatrixC);             // finding the norm e
    printf("Norm of C: %.6lf\n", 1/e);

    scalarProduct(linkedMatrixC, 1 / e);

    printf("Scalar Product of C with 1/e:\n");
    printLinkedMatrix(linkedMatrixC);
    scalarProduct(linkedMatrixC,5.0);

    printf("Scalar Product of C with magnitude 5:\n");     // function for multiplying the scalar product with magnitude 5 units

    printLinkedMatrix(linkedMatrixC);
   createDatMat("vector.dat",linkedMatrixC);
    return 0;
}
