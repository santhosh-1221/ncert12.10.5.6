#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"


int main() {
    double matA[3] = { 2.0, 3.0, -1.0 };
    double matB[3] = { 1.0, -2.0, 1.0 };
    double** a = createmat(matA[0], matA[1], matA[2]);
    double** b = createmat(matB[0], matB[1], matB[2]);

    node* linkedMatrixA = constructLinkedMatrix(a, 3, 1);
    createDatMat("a.dat",linkedMatrixA);
   node* linkedMatrixB = constructLinkedMatrix(b, 3, 1);
createDatMat("b.dat",linkedMatrixB);
    printf("Linked Matrix A:\n");
    printLinkedMatrix(linkedMatrixA);
    
    printf("Linked Matrix B:\n");
    printLinkedMatrix(linkedMatrixB);

    node* linkedMatrixC = constructLinkedMatrix(a, 3,1);
    matSum(linkedMatrixC, linkedMatrixB);

    printf("Linked Matrix C = A + B:\n");
    printLinkedMatrix(linkedMatrixC);

    double e = vectorNorm(linkedMatrixC);
    printf("Norm of C: %.6lf\n", 1/e);

    scalarProduct(linkedMatrixC, 1 / e);

    printf("Scalar Product of C with 1/e:\n");
    printLinkedMatrix(linkedMatrixC);
    scalarProduct(linkedMatrixC,5.0);

    printf("Scalar Product of C with magnitude 5:\n");

    printLinkedMatrix(linkedMatrixC);
   createDatMat("vector.dat",linkedMatrixC);
    return 0;
}
