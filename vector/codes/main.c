#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double z;
} Vector;

Vector addVectors(Vector a, Vector b) {
    Vector result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

double getMagnitude(Vector v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector getUnitVector(Vector v) {
    double magnitude = getMagnitude(v);
    Vector unitVector;
    unitVector.x = v.x / magnitude;
    unitVector.y = v.y / magnitude;
    unitVector.z = v.z / magnitude;
    return unitVector;
}

Vector scaleVector(Vector v, double scaleFactor) {
    Vector result;
    result.x = v.x * scaleFactor;
    result.y = v.y * scaleFactor;
    result.z = v.z * scaleFactor;
    return result;
}

int main() {
    Vector a = {2, 3, -1};
    Vector b = {1, -2, 1};
    
    Vector result = addVectors(a, b);
    Vector unitVector = getUnitVector(result);
    
    printf("The unit vector of the resultant vector is (%.2f, %.2f, %.2f)\n", unitVector.x, unitVector.y, unitVector.z);
    
    double magnitude = 5.0;
    Vector scaledVector = scaleVector(unitVector, magnitude);
    
    printf("The vector with a magnitude of 5 units in the direction of the unit vector is (%.2f, %.2f, %.2f)\n", scaledVector.x, scaledVector.y, scaledVector.z);
    
    return 0;
}
