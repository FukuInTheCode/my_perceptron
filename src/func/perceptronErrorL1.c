#include "../../includes/my.h"

double __abs(double x) {
    return my_abs(x);
}

double my_Perceptron_calcErrorL1(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets) {
    my_Matrix Prediction = {.m=0, .n=0};
    my_Perceptron_Predict(P, inputs, &Prediction);

    my_Matrix NegTargets = {.m=0, .n=0};
    my_Matrix_MultiplyByScalar(targets, -1, &NegTargets);

    my_Matrix difference = {.m=0, .n=0};
    my_Matrix_Add(&difference, 2, &Prediction, &NegTargets);

    my_Matrix differenceSquared = {.m=0, .n=0};
    my_Matrix_ApplyFunc(&difference, __square, &differenceSquared);
    
    double res = my_Matrix_Sum(&differenceSquared);
    res /= inputs->m * 2;

    my_Matrix_Free(4, &Prediction, &difference, &NegTargets, &differenceSquared);

    return res;
}