#pragma once
#define MYPERCEPTRONH

typedef struct my_Perceptron {
    my_Matrix theta;
    double bias;
} my_Perceptron;

void my_Perceptron_Create(const unsigned int inputsSize, const unsigned int count, ...);
void my_Perceptron_Free(const unsigned int count, ...);
void my_Perceptron_Print(const unsigned int count, ...);
void my_Perceptron_Predict(my_Perceptron *P, my_Matrix *inputs, my_Matrix *predictions);
double my_Perceptron_calcError(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets);