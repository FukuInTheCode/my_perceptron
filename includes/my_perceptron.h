#pragma once
#define MYPERCEPTRONH

typedef struct my_Perceptron {
    my_Matrix theta;
    double bias;
} my_Perceptron;

double my_Perceptron_calcError(my_Perceptron *entity, my_Matrix *inputs, my_Matrix *targets);