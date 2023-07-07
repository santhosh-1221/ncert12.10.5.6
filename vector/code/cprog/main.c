#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"
int main() {
    double e;
    int m = 3, n = 1;
    double **a,**b,**c,**C,**vector;
    a=loadtxt("a.dat",3,1);
    b=loadtxt("b.dat",3,1);
    print(a, 3, 1);
    print(b, 3, 1);
    c = matc(a, b);
    print(c, 3, 1);
    e = linalg_norm(c, m);
    printf("%lf\n", e);
    C = scalarProduct(1 / e, c);
    print(C, 3, 1);
    vector = scalarProduct(5, C);
    print(vector,m,n);
    save_vector(vector,3,1);
    return 0;
}
