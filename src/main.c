#include "../includes/my.h"

double __mysq(double x) {
    return x + 1;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    my_Matrix features = {.m = 0, .n =0};
    my_Matrix targets = {.m = 0, .n =0};
    my_Matrix prediction = {.m = 0, .n =0};

    my_Matrix_Create(2, 10, 1, &features);
    my_Matrix_Create(2, 1, 1, &targets);
    my_Matrix_RandInt(0, 20, 2, &features, &targets);

    my_Matrix_Print(2, &features, &targets);

    my_Perceptron P = {.theta.m = 0, .theta.n = 0};

    my_Perceptron_Create(10, 1, &P);
    my_Perceptron_Print(1, &P);

    printf("%f\n", my_Perceptron_calcErrorMSE(&P, &features, &targets));
    my_Perceptron_Predict(&P, &features, &prediction);
    my_Matrix_Print(1, &prediction);

    my_Perceptron_Train(&P, &features, &targets, 0.001, 10000);
    
    printf("Training completed!\n");

    printf("%f\n", my_Perceptron_calcErrorMSE(&P, &features, &targets));
    my_Perceptron_Predict(&P, &features, &prediction);
    my_Matrix_Print(1, &prediction);

    my_Perceptron_Print(1, &P);

    my_Perceptron_Free(1, &P);

    my_Matrix_Free(3, &features, &targets, &prediction);

    return 0;
}