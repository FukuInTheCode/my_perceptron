#pragma once
#define MYPERCEPTRONH

typedef struct my_Perceptron {
    my_Matrix theta;
    double bias;
} my_Perceptron;

void my_Perceptron_Create(my_Perceptron *entity, const unsigned int inputsSize);
void my_Perceptron_Free(const unsigned int count, ...);