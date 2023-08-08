#include "../../includes/my.h"


int __ProductisValid(va_list args, const unsigned int count) {
    my_Matrix* A = va_arg(args, my_Matrix*);
    unsigned int insideN = A->n;
    unsigned int i;
    for(i=0; i<(count-1); i++) {
        A = va_arg(args, my_Matrix*);
        if(A->m != insideN) return 1;
        insideN = A->n;
    }
    return 0;
}

void __Product(my_Matrix* A, my_Matrix* B, my_Matrix* result) {
    if(A->n != B->m) return;

    my_Matrix_Create(A->m, B->n, 1, result);

    unsigned int i, j;
    for(i=0; i<result->m; i++) {
        double* row = my_Matrix_GetRow(A, i);
        for(j=0;j<result->n; j++) {
            double column[B->m];
            my_Matrix_GetColumn(B, j, column);
            my_Matrix_Set(result, i, j, dot_product(row, column, A->n));
        }
    } 
}


void my_Matrix_Product(my_Matrix* result, const unsigned int count, ...) {
    va_list args;
    va_list args_copy;
    va_copy(args_copy, args);
    va_start(args_copy, count);
    if (__ProductisValid(args_copy, count) == 1) {
        va_end(args_copy);
        return;
    }
    va_end(args_copy);
    va_start(args, count);
    my_Matrix* A = va_arg(args, my_Matrix*);
    my_Matrix copy = {.m = 0, .n = 0};
    my_Matrix_Copy(A, &copy);
    unsigned int i;
    for(i=0; i < (count-1); i++) {
        my_Matrix* B = va_arg(args, my_Matrix*);
        __Product(&copy, B, result);
        my_Matrix_Copy(result, &copy);
    }
    my_Matrix_Free(1, &copy);
}