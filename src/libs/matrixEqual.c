#include "../../includes/my.h"

int my_Matrix_Equals(my_Matrix *A, my_Matrix *B) {
    if(A->m != B->m || A->n != B->n) return FALSE;
    unsigned int i;
    unsigned int j;
    for(i=0; i<A->m; i++) {
        for(j=0; j<A->n; j++) {
            if(A->arr[i][j] != B->arr[i][j]) return FALSE;
        }
    }
    return TRUE;
}