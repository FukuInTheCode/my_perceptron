#include "../../includes/my.h"

void my_Matrix_Copy(my_Matrix* A, my_Matrix* copy) {
    my_Matrix_Create(A->m, A->n, 1, copy);
    unsigned int i, j;
    for(i = 0; i<A->m; i++) {
        for(j=0; j<A->n; j++) {
            my_Matrix_Set(copy, j, i, A->arr[i][j]);
        }
    }
}

