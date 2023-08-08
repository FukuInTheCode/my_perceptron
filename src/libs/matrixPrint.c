#include "../../includes/my.h"

void __Print(my_Matrix *A) {
    if(A->m == 0 || A->n == 0) return;
    unsigned int i;
    unsigned int j;
    for(i=0; i<A->m; i++) {
        for(j=0;j<A->n;j++) {
            printf("%f ", A->arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void my_Matrix_Print(const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0;i<count;i++) {
        my_Matrix *A = va_arg(args, my_Matrix *);
        __Print(A);
    }
    va_end(args);
}