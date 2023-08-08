#include "../includes/my.h"

int main(int argc, char* argv[]) {
    my_Matrix A = {.m=0, .n=0};
    my_Matrix_Create(2, 2, 1, &A);
    my_Matrix_RandFloat(-10, 10, 1, &A);
    
    my_Matrix B = {.m=0, .n=0};
    my_Matrix_Create(2, 2, 1, &B);
    my_Matrix_RandInt(-10, 10, 1, &B);

    my_Matrix_Print(2, &A, &B);

    my_Matrix_Free(2, &A, &B);

    return 0;
}