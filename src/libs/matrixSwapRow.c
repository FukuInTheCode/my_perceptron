#include "../../includes./my.h"

void my_Matrix_SwapRow(my_Matrix *A, const unsigned int a, const unsigned int b, my_Matrix *result) {
    if(a >= A->m || b >= A->m) return;
    my_Matrix_Copy(A, result);
    unsigned int i;
    for(i=0; i<result->n; i++) {
        SWAP(result->arr[a][i], result->arr[b][i])
    }
}