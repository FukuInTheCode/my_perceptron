#include "../../includes/my.h"

double my_Perceptron_calcError(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets) {
    my_Matrix *Prediction = {.m=0, .n=0};

    my_Perceptron_Predict(P, inputs, &Prediction);

    my_Matrix_Free(1, &Prediction);
}