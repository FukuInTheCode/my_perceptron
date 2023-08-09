#pragma once
#define MYPERCEPTRONH

typedef struct my_Perceptron {
    my_Matrix theta;
    double bias;
} my_Perceptron;

void my_Perceptron_Create(const unsigned int inputsSize, const unsigned int count, ...);
void my_Perceptron_Free(const unsigned int count, ...);
void my_Perceptron_Print(my_Perceptron *P);