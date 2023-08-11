#include "../../includes/my.h"

int my_randInt(int minN, int maxN) {
    maxN++;
    if(minN>maxN) {
        SWAP(minN, maxN)
    }
    return rand() % (maxN - minN) + minN;
}

double my_randFloat(double minN, double maxN) {
    if(minN>maxN) {
        SWAP(minN, maxN)
    }
    double range = (maxN - minN); 
    double div = RAND_MAX / range;
    return minN + (rand() / div);
}