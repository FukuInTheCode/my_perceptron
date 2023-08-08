#include "../../includes/my.h"



int __AddisValid(va_list args, const unsigned int count) {
    my_Matrix* A = va_arg(args, my_Matrix*);
    unsigned int baseM = A->m;
    unsigned int baseN = A->n;
    unsigned int i;
    for(i=0; i<count-1; i++) {
        A = va_arg(args, my_Matrix*);
        if(A->m != baseM || A->n != baseN) return 1;
    }
    return 0;
}

void __Add(my_Matrix* result, my_Matrix* A) {
    unsigned int i, j;
    for(i=0; i<result->m; i++) {
        for(j=0; j<result->n; j++) {
            result->arr[i][j] += A->arr[i][j];
        }
    }
}


void my_Matrix_Add(my_Matrix* result, const unsigned int count, ...) {
    va_list args;
    va_list args_copy;
    va_copy(args_copy, args);
    va_start(args_copy, count);
    if (__AddisValid(args_copy, count) == 1) {
        va_end(args_copy);
        return;
    }
    va_end(args_copy);
    va_start(args, count);
    my_Matrix *A = va_arg(args, my_Matrix*);
    my_Matrix_Create(A->m, A->n, 1, result);
    my_Matrix_Copy(A, result);
    unsigned int i;
    for(i=0; i < (count-1); i++) {
        A = va_arg(args, my_Matrix*);
        __Add(result, A);
    }
    va_end(args);
}