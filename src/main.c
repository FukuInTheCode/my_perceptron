#include "../includes/my.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    my_Perceptron P = {.theta.m = 0, .theta.n = 0};
    my_Matrix targets = {.m = 0, .n = 0};
    my_Matrix features = {.m = 0, .n = 0};
    my_Matrix needed = {.m=0, .n=0};
    my_Matrix prediction = {.m=0, .n=0};

    my_Perceptron_Create(2, 1, &P);
    
    my_Matrix_Create(10, 2, 1, &features);
    my_Matrix_RandInt(0, 20, 1, &features);

    // my_Matrix_Set(&features, 0, 0, 0);
    // my_Matrix_Set(&features, 1, 0, 0);

    my_Matrix_Create(2, 1, 1, &needed);
    my_Matrix_Set(&needed, 0, 0, 1);
    my_Matrix_Set(&needed, 0, 1, 1);

    my_Matrix_Product(&targets, 2, &features, &needed);

    my_Matrix_Print(3, &features, &needed, &targets);

    my_Perceptron_calcError(&P, &features, &targets);

    my_Perceptron_Free(1, &P);

    my_Matrix_Free(4, &features, &needed, &targets, &prediction);

    return 0;
}