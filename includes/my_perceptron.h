#pragma once
#define MYPERCEPTRONH

#include "./my_matrix.h"

// typedef double (*ErrorTemplate)(my_Perceptron *, my_Matrix *, my_Matrix *);
// typedef void (*GradTemplate)(my_Perceptron *, my_Matrix *, my_Matrix *, my_Matrix *);
// typedef void (*PredictTemplate)(my_Perceptron *, my_Matrix *, my_Matrix *);

// typedef struct my_Model {
//     my_Matrix theta;
//     ErrorTemplate;
//     GradTemplate;

    

// }

typedef struct my_Perceptron {
    my_Matrix theta;
    double bias;
} my_Perceptron;

void my_Perceptron_Create(const unsigned int inputsSize, const unsigned int count, ...);
void my_Perceptron_Free(const unsigned int count, ...);
void my_Perceptron_Print(const unsigned int count, ...);
void my_Perceptron_Predict(my_Perceptron *P, my_Matrix *inputs, my_Matrix *predictions);
double my_Perceptron_calcErrorMSE(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets);
void my_Perceptron_GradTheta(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets, my_Matrix *result);
void my_Perceptron_Train(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets, const double alpha, const unsigned int stepsN);
double my_Perceptron_GradBias(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets);