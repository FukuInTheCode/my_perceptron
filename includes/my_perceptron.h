#pragma once
#define MYPERCEPTRONH

#include "./my_matrix.h"

typedef struct my_perceptron my_perceptron_t;

typedef double (*error_template)(my_perceptron_t *, my_matrix_t *, \
                                    my_matrix_t *);
typedef void (*grad_theta_template)(my_perceptron_t *, my_matrix_t *, \
                    my_matrix_t *, my_matrix_t *);
typedef double (*grad_bias_template)(my_perceptron_t *, my_matrix_t *, \
                                    my_matrix_t *);

typedef struct my_perceptron {
    my_percep_funcs_t funcs;
    my_matrix_t theta;
    double bias;
    uint16_t inputs_size;
    uint16_t outputs_size;
} my_perceptron_t;

typedef struct my_params {
    double alpha;
    uint16_t iterations;
    double threshold;
} my_params_t;

typedef struct my_percep_funcs {
    error_template error_func;
    grad_theta_template grad_theta_func;
    grad_bias_template grad_bias_func;
} my_percep_funcs_t;

void my_perceptron_create(my_percep_funcs_t *funcs, \
            const unsigned int count, ...);
void my_perceptron_free(const unsigned int count, ...);
void my_perceptron_print(const unsigned int count, ...);
void my_perceptron_predict(my_perceptron_t *P, my_matrix_t *inputs, \
                                my_matrix_t *predictions);
double my_perceptron_calcerror_mse(my_perceptron_t *P, my_matrix_t *inputs, \
                                        my_matrix_t *targets);
void my_perceptron_grad_theta(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets, my_matrix_t *result);
void my_Perceptron_Train(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets, const double alpha, const unsigned int stepsN, const double treshold);
double my_perceptron_grad_bias(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets);
double my_perceptron_calcerror_l1(my_perceptron_t *P, my_matrix_t *inputs, \
                                    my_matrix_t *targets);
