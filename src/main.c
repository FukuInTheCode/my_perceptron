#include "../includes/my.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    my_Perceptron P = {.theta.m = 0, .theta.n = 0};
    my_Matrix y = {.m = 0, .n = 0};
    my_Matrix features = {.m = 0, .n = 0};
    my_Matrix needed = {.m=0, .n=0};

    my_Perceptron_Create(2, 1, &P);

    my_Matrix_Create(10, 2, 1, &features);
    my_Matrix_RandInt(0, 20, 1, &features);

    my_Matrix_Create(2, 1, 1, &needed);
    my_Matrix_Set(&needed, 0, 0, 1);
    my_Matrix_Set(&needed, 0, 1, 1);

    my_Matrix_Product(&y, 2, &features, &needed);

    my_Matrix_Print(3, &features, &needed, &y);

    my_Perceptron_Print(1, &P);

    my_Perceptron_Free(1, &P);

    my_Matrix_Free(3, &features, &needed, &y);

    return 0;
}