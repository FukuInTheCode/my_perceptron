#pragma once
#define MYPERCEPTRONH

#include "./my_matrix.h"

typedef struct my_perceptron my_perceptron_t;

typedef double (*ErrorTemplate)(my_perceptron_t *, my_Matrix *, my_Matrix *);
typedef void (*GradThetaTemplate)(my_perceptron_t *, my_Matrix *, \
                    my_Matrix *, my_Matrix *);
typedef double (*GradBiasTemplate)(my_perceptron_t *, my_Matrix *, my_Matrix *);

typedef struct my_perceptron {
    ErrorTemplate errorFunc;
    GradThetaTemplate gradThetaFunc;
    GradBiasTemplate gradBiasFunc;
    my_Matrix theta;
    double bias;
} my_perceptron_t;

typedef struct my_percep_funcs {
    ErrorTemplate errorFunc;
    GradThetaTemplate gradThetaFunc;
    GradBiasTemplate gradBiasFunc;
} my_percep_funcs_t;

void my_Perceptron_Create(const unsigned int inputsSize, const unsigned int outputsSize, ErrorTemplate errorFunc, GradThetaTemplate gradThetaFunc, GradBiasTemplate gradBiasFunc, const unsigned int count, ...);
void my_Perceptron_Free(const unsigned int count, ...);
void my_Perceptron_Print(const unsigned int count, ...);
void my_Perceptron_Predict(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *predictions);
double my_Perceptron_calcErrorMSE(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets);
void my_Perceptron_GradTheta(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets, my_Matrix *result);
void my_Perceptron_Train(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets, const double alpha, const unsigned int stepsN, const double treshold);
double my_Perceptron_GradBias(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets);
double my_Perceptron_calcErrorL1(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets);