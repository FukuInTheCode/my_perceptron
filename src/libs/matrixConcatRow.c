#include "../../includes/my.h"

void my_Matrix_ConcatRow(my_Matrix *result, my_Matrix *A, my_Matrix *B) {
    if(A->n != B->n) return;
    my_Matrix_Create(A->m + B->m, A->n, 1, result);
    unsigned int i;
    unsigned int j;
    for(i=0; i<result->n; i++) {
        for(j=0; j<A->m; j++) {
            result->arr[j][i] = A->arr[j][i];
        }
        for(j=A->m; j<result->m; j++) {
            result->arr[j][i] = B->arr[j - A->m][i];
        }
    }
}