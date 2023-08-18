#pragma once
#define MYPERCEPTRONH

#include "./my_matrix.h"

typedef struct my_perceptron my_perceptron_t;

typedef double (*ErrorTemplate)(my_perceptron_t *, my_matrix_t *, \
                                    my_matrix_t *);
typedef void (*GradThetaTemplate)(my_perceptron_t *, my_matrix_t *, \
                    my_matrix_t *, my_matrix_t *);
typedef double (*GradBiasTemplate)(my_perceptron_t *, my_matrix_t *, \
                                    my_matrix_t *);

typedef struct my_perceptron {
    ErrorTemplate errorFunc;
    GradThetaTemplate gradThetaFunc;
    GradBiasTemplate gradBiasFunc;
    my_matrix_t theta;
    double bias;
    uint16_t inputs_size;
    uint16_t outputs_size;
} my_perceptron_t;

typedef struct my_percep_funcs {
    ErrorTemplate errorFunc;
    GradThetaTemplate gradThetaFunc;
    GradBiasTemplate gradBiasFunc;
} my_percep_funcs_t;

void my_perceptron_create(my_percep_funcs_t *funcs, \
            const unsigned int count, ...);
void my_perceptron_free(const unsigned int count, ...);
void my_Perceptron_Print(const unsigned int count, ...);
void my_Perceptron_Predict(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *predictions);
double my_Perceptron_calcErrorMSE(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets);
void my_Perceptron_GradTheta(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets, my_matrix_t *result);
void my_Perceptron_Train(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets, const double alpha, const unsigned int stepsN, const double treshold);
double my_Perceptron_GradBias(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets);
double my_Perceptron_calcErrorL1(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets);