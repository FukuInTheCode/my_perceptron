#include "../../includes/my.h"

static double __abs(double x) {
    return my_abs(x);
}

double my_Perceptron_calcErrorL1(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets) {
    my_Matrix Prediction = {.m=0, .n=0};
    my_Perceptron_Predict(P, inputs, &Prediction);

    my_Matrix NegTargets = {.m=0, .n=0};
    my_Matrix_MultiplyByScalar(targets, -1, &NegTargets);

    my_Matrix difference = {.m=0, .n=0};
    my_Matrix_Add(&difference, 2, &Prediction, &NegTargets);

    my_Matrix absoluteDifference = {.m=0, .n=0};
    my_Matrix_ApplyFunc(&difference, __abs, &absoluteDifference);
    
    double res = my_Matrix_Sum(&absoluteDifference);
    res /= inputs->m;

    my_Matrix_Free(4, &Prediction, &difference, &NegTargets, &absoluteDifference);

    return res;
}