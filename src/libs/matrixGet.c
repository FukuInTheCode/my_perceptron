#include <stdio.h>
#include "../../includes/my.h"


double* my_Matrix_GetRow(my_Matrix* A, unsigned int i) {
    return A->arr[i];
}

void my_Matrix_GetColumn(my_Matrix* A, unsigned int n, double result[]) {
    unsigned int i;
    for(i = 0; i<A->m; i++) {
        result[i] = A->arr[i][n];
    }
}

void my_Matrix_GetSubMatrix(my_Matrix *A, const unsigned int m, const unsigned int n, my_Matrix *result) {
    my_Matrix_Create(A->m - 1, A->n - 1, 1, result);
    unsigned int i;
    unsigned int j;
    unsigned int i2 = 0;
    unsigned int j2 = 0;
    for(i2=i=0; i<A->m; i++) {
        if(i == m) continue;
        for(j2=j=0; j<A->n; j++) {
            if(j == n) continue;
            result->arr[i2][j2] = A->arr[i][j];
            j2++;
        }
        i2++;
    }
}