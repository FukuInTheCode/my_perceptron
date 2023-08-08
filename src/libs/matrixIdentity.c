#include "../../includes/my.h"

void __Identity(my_Matrix *A) {
    if(A->m != A->n) return;
    unsigned int i, j;
    for(i = 0; i<A->m; i++) {
        for(j = 0; j<A->n; j++) {
            my_Matrix_Set(A, j, i, 0);
        }
    }
    for(i = 0; i<A->m; i++) {
        my_Matrix_Set(A, i, i, 1);
    }
}

void my_Matrix_Identity(const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0; i<count ;i++) {
        my_Matrix *A = va_arg(args, my_Matrix *);
        __Identity(A);
    }
    va_end(args);
}