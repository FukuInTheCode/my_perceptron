#include "../../includes/my.h"

void my_Matrix_AddCol(my_Matrix *A, const unsigned int n, my_Matrix *result) {
    if(n > A->n) return;    
    my_Matrix_Create(A->m, A->n + 1, 1, result);
    unsigned int i;
    unsigned int j;
    unsigned int i2 = 0;
    unsigned int j2;
    for(i=0; i<result->m; i++) {
        j2 = 0;
        for(j=0; j<result->n; j++) {
            if(j == n) continue;
            result->arr[i][j] = A->arr[i2][j2];
            j2++;
        }
        i2++;
    }
}