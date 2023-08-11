#include "../../includes/my.h"

double __setOne(double x) {
    if(x == 0) return 1;
    return x/x;
}

void my_Matrix_One(my_Matrix *A, my_Matrix *result) {
    my_Matrix_ApplyFunc(A, __setOne, result);
}