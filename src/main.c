#include "../includes/my.h"

double __mysq(double x) {
    return x + 1;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    my_Perceptron P = {.theta.m = 0, .theta.n = 0};
    my_Matrix features = {.m = 0, .n = 0};
    my_Matrix targets = {.m = 0, .n = 0};
    my_Matrix needed = {.m=0, .n=0};
    my_Matrix prediction = {.m=0, .n=0};
    my_Matrix test = {.m=0, .n=0};

    my_Perceptron_Create(2, 1, &P);
    
    my_Matrix_Create(10, 2, 1, &features);
    my_Matrix_RandInt(0, 20, 1, &features);

    my_Matrix_Create(2, 1, 1, &needed);
    my_Matrix_Set(&needed, 0, 0, 1);
    my_Matrix_Set(&needed, 0, 1, 1);

    my_Matrix_Product(&targets, 2, &features, &needed);

    my_Perceptron_Predict(&P, &features, &prediction);

    my_Matrix_Print(4, &features, &needed, &targets, &prediction);

    printf("starting Error: %f\n", my_Perceptron_calcErrorMSE(&P, &features, &targets));

    my_Perceptron_Print(1, &P);

    my_Perceptron_Train(&P, &features, &targets, 0.0005, 10000);
    printf("Trained!\n");

    printf("finished Error: %f\n", my_Perceptron_calcErrorMSE(&P, &features, &targets));
    my_Perceptron_Predict(&P, &features, &prediction);

    my_Matrix_Print(1, &prediction);

    my_Perceptron_Print(1, &P);

    my_Perceptron_Free(1, &P);

    my_Matrix_Free(5, &features, &needed, &targets, &prediction, &test);

    return 0;
}