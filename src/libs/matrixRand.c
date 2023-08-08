#include "../../includes/my.h"

void __Rand(my_Matrix *A, int minN, int maxN) {
    maxN++;
    if(minN>maxN) {
        SWAP(minN, maxN)
    }
    unsigned int i, j;
    for(i = 0; i<A->m; i++) {
        for(j = 0; j<A->n; j++) {
            my_Matrix_Set(A, j, i, rand() % (maxN - minN) + minN);
        }
    }
}

void my_Matrix_Rand(int minN, int maxN, const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i = 0; i<count; i++) {
        my_Matrix *A = va_arg(args, my_Matrix *);
        __Rand(A, minN, maxN);
    }
    va_end(args);
}