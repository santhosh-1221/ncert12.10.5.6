#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double* components;
} Vector;

Vector createVector(double x, double y, double z) {
    Vector vector;
    double* components = malloc(3 * sizeof(double));
    components[0] = x;
    components[1] = y;
    components[2] = z;
    vector.components = components;
    return vector;
}

Vector addVectors(Vector a, Vector b) {
    Vector result;
    double* components = malloc(3 * sizeof(double));
    for (int i = 0; i < 3; i++) {
        components[i] = a.components[i] + b.components[i];
    }
    result.components = components;
    return result;
}

double getMagnitude(Vector v) {
    double sumOfSquares = 0.0;
    for (int i = 0; i < 3; i++) {
        sumOfSquares += v.components[i] * v.components[i];
    }
    return sqrt(sumOfSquares);
}

Vector getUnitVector(Vector v) {
    double magnitude = getMagnitude(v);
    Vector unitVector;
    double* components = malloc(3 * sizeof(double));
    for (int i = 0; i < 3; i++) {
        components[i] = v.components[i] / magnitude;
    }
    unitVector.components = components;
    return unitVector;
}

Vector scaleVector(Vector v, double scaleFactor) {
    Vector result;
    double* components = malloc(3 * sizeof(double));
    for (int i = 0; i < 3; i++) {
        components[i] = v.components[i] * scaleFactor;
    }
    result.components = components;
    return result;
}

void freeVector(Vector v) {
    free(v.components);
}

int main() {
    Vector a = createVector(2, 3, -1);
    Vector b = createVector(1, -2, 1);
    
    Vector result = addVectors(a, b);
    Vector unitVector = getUnitVector(result);
    
    printf("The unit vector of the resultant vector is (%.2f, %.2f, %.2f)\n", unitVector.components[0], unitVector.components[1], unitVector.components[2]);
    
    double magnitude = 5.0;
    Vector scaledVector = scaleVector(unitVector, magnitude);
    
    printf("The vector with a magnitude of 5 units in the direction of the unit vector is (%.2f, %.2f, %.2f)\n", scaledVector.components[0], scaledVector.components[1], scaledVector.components[2]);
    
    freeVector(a);
    freeVector(b);
    freeVector(result);
    freeVector(unitVector);
    freeVector(scaledVector);
    
    return 0;
}

