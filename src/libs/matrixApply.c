#include "../../includes/my.h"

void my_Matrix_ApplyFunc(my_Matrix *A, UnaryFunction func, my_Matrix *result) {
    my_Matrix_Copy(A, result);
    unsigned int i;
    unsigned int j;

    for(i=0; i<result->m; i++) {
        for(j=0; j<result->n; j++) {
            my_Matrix_Set(result, j, i, func(result->arr[i][j]));
        }
    }
}