#include "../../includes/my.h"

void my_Matrix_ConcatCol(my_Matrix *result, my_Matrix *A, my_Matrix *B) {
    if(A->m != B->m) return;
    my_Matrix_Create(A->m, A->n + B->n, 1, result);
    unsigned int i;
    unsigned int j;
    for(i=0; i<result->m; i++) {
        for(j=0; j<A->n; j++) {
            result->arr[i][j] = A->arr[i][j];
        }
        for(j=A->n; j<result->n; j++) {
            result->arr[i][j] = B->arr[i][j - A->n];
        }
    }
}