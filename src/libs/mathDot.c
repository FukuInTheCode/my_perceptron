#include "../../includes/my.h"

double dot_product(double* a, double* b, unsigned int size) {
    int result = 0;
    unsigned int i;
    for(i = 0; i<size; i++) {
        result += a[i]*b[i];
    }
    return result;
}