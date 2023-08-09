#include "../../includes/my.h"

double __square(double x) {
    return x * x;
}

double my_Perceptron_calcError(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets) {
    my_Matrix Prediction = {.m=0, .n=0};

    my_Perceptron_Predict(P, inputs, &Prediction);

    my_Matrix NegTargets = {.m=0, .n=0};

    my_Matrix_MultiplyByScalar(targets, -1, &NegTargets);

    my_Matrix difference = {.m=0, .n=0};

    my_Matrix_Add(&difference, 2, &Prediction, &NegTargets);
    
    double res = my_Matrix_Sum(&difference);

    res /= inputs->m;

    my_Matrix_Free(3, &Prediction, &difference, &NegTargets);

    return res;
}