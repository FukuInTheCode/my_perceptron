#include "../../includes/my.h"

double my_Matrix_Det(my_Matrix *A) {
    if(A->m != A->n) {
        fprintf(stderr, "Matrix is not square matrix!");
        exit(1);
    } else if(A->m == 1) return A->arr[0][0];

    double det = 0;
    unsigned int i;
    for(i=0; i<A->n; i++){
        my_Matrix subMatrix = {.m=0, .n=0};
        my_Matrix_GetSubMatrix(A, 0, i, &subMatrix);
        double sign = my_power(-1.0, i);
        det += sign * A->arr[0][i] * my_Matrix_Det(&subMatrix);
        my_Matrix_Free(1, &subMatrix);
    }
   
    return det;
}