#include "../../includes/my.h"

void my_Matrix_T(my_Matrix* A, my_Matrix* T) {
    my_Matrix_Create(A->n, A->m, 1, T);
    unsigned int i, j;
    for(i = 0; i< T->m; i++) {
        for(j = 0; j<T->n; j++) {
            T->arr[i][j] = A->arr[j][i];
        }
    }
}

void my_Matrix_PowerInt(my_Matrix* A, const unsigned int n, my_Matrix* result) {
    if(A->m != A->n) return;
    if(n==0) {
        my_Matrix_Identity(1, result);
        return;
    } else if(n == 1) {
        my_Matrix_Copy(A, result);
        return;
    }

    unsigned int i;
    my_Matrix copy;
    my_Matrix_Copy(A, &copy);
    for(i=2; i<=n; i++) {
        my_Matrix_Product(result, 2, A, &copy);
        my_Matrix_Copy(result, &copy);
    }
}

void my_Matrix_Adjugate(my_Matrix *A, my_Matrix *result) {
    if(A->m != A->n) {
        fprintf(stderr, "Matrix is not a square matrix!");
        exit(1);
    } else if(A->m == 1) return my_Matrix_Identity(1, result);

    my_Matrix_Create(A->m, A->n, 1, result);
    unsigned int i;
    unsigned int j;
    for(i=0; i<result->m; i++) {
        for(j=0; j<result->n; j++){
            my_Matrix sub = {.m=0, .n=0};
            my_Matrix_GetSubMatrix(A, i, j, &sub);
            double cofactor = my_power(-1, i+j) * my_Matrix_Det(&sub);
            my_Matrix_Set(result, i, j, cofactor);
            my_Matrix_Free(1, &sub);
        }
    }
}