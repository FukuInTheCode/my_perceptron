#include "../../includes/my.h"

double dot_product(double* a, double* b, unsigned int size) {
    int result = 0;
    unsigned int i;
    for(i = 0; i<size; i++) {
        result += a[i]*b[i];
    }
    return result;
}

double my_power(double x, unsigned int n) {
    int res = 1;
    unsigned int i;
    for(i=0; i<n; i++) {
        res *= x;
    }
    return res;
}

int my_randInt(int minN, int maxN) {
    maxN++;
    if(minN>maxN) {
        SWAP(minN, maxN)
    }
    return rand() % (maxN - minN) + minN;
}

double my_randFloat(double minN, double maxN) {
    maxN++;
    if(minN>maxN) {
        SWAP(minN, maxN)
    }
    double range = (maxN - minN); 
    double div = RAND_MAX / range;
    return minN + (rand() / div);
}