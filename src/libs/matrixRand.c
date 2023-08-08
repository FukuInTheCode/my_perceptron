#include "../../includes/my.h"

void __RandFloat(my_Matrix *A, double minN, double maxN) {
    unsigned int i, j;
    for(i = 0; i<A->m; i++) {
        for(j = 0; j<A->n; j++) {
            my_Matrix_Set(A, j, i, my_randFloat(minN, maxN));
        }
    }
}

void my_Matrix_RandFloat(double minN, double maxN, const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i = 0; i<count; i++) {
        my_Matrix *A = va_arg(args, my_Matrix *);
        __RandFloat(A, minN, maxN);
    }
    va_end(args);
}

void __RandInt(my_Matrix *A, int minN, int maxN) {
    unsigned int i, j;
    for(i = 0; i<A->m; i++) {
        for(j = 0; j<A->n; j++) {
            my_Matrix_Set(A, j, i, my_randInt(minN, maxN));
        }
    }
}

void my_Matrix_RandInt(int minN, int maxN, const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i = 0; i<count; i++) {
        my_Matrix *A = va_arg(args, my_Matrix *);
        __RandInt(A, minN, maxN);
    }
    va_end(args);
}