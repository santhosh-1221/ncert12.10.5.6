#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"             // include user-defined library that contains required functions
int main() {
    double e;
    int m = 3, n = 1;
    double **a,**b,**c,**C,**vector;
    a=loadtxt("a.dat",3,1);    // load the values of vectors A and B from files
    b=loadtxt("b.dat",3,1);
    print(a, 3, 1);
    print(b, 3, 1);
    c = matc(a, b);
    print(c, 3, 1);
    e = linalg_norm(c, m);           // Finding the value of norm of c
    printf("%lf\n", e);
    C = scalarProduct(1 / e, c);
    print(C, 3, 1);
    vector = scalarProduct(5, C);     // Multiplying the product with the magnitude 5 units
    print(vector,m,n);                 // print the values of vector C
    save_vector(vector,3,1);
    return 0;
}
