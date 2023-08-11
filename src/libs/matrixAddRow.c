#include "../../includes/my.h"

void my_Matrix_AddRow(my_Matrix *A, const unsigned int m, my_Matrix *result) {
    if(m > A->m) return;    
    my_Matrix_Create(A->m + 1, A->n, 1, result);
    unsigned int i;
    unsigned int j;
    unsigned int i2 = 0;
    unsigned int j2;
    for(i=0; i<result->m; i++) {
        if(i == m) continue;
        j2 = 0;
        for(j=0; j<result->n; j++) {
            result->arr[i][j] = A->arr[i2][j2];
            j2++;
        }
        i2++;
    }
}