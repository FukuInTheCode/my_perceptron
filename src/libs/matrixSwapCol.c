#include "../../includes./my.h"

void my_Matrix_SwapCol(my_Matrix *A, const unsigned int a, const unsigned int b, my_Matrix *result) {
    if(a >= A->n || b >= A->n) return;
    my_Matrix_Copy(A, result);
    unsigned int i;
    for(i=0; i<result->m; i++) {
        SWAP(result->arr[i][a], result->arr[i][b])
    }
}