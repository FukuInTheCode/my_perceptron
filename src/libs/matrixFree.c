#include "../../includes/my.h"

void __Free(my_Matrix* A) {
    unsigned int i;
    for (i = 0; i < A->m; i++) {
        free(A->arr[i]);
    }
    free(A->arr);
}

int __FreeisValid(my_Matrix* A) {
    return (A->m == 0 || A->n == 0 || A->arr == NULL) ? 84: 0;
}

void my_Matrix_Free(const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for (i = 0; i < count; i++) {
        my_Matrix *A = va_arg(args, my_Matrix *);
        if(__FreeisValid(A) == 84) continue;
        __Free(A);
    }
    va_end(args);
}