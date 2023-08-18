#include "../../includes/my.h"

static void create_preceptron(my_perceptron_t *P, my_percep_funcs_t *funcs)
{
    my_matrix_create(P->inputs_size, P->outputs_size, 1, &(P->theta));
    my_matrix_randfloat(-1, 1, 1, &(P->theta));
    P->bias = my_randfloat(-1, 1);
    P->errorFunc = funcs->errorFunc;
    P->gradThetaFunc = funcs->gradThetaFunc;
    P->gradBiasFunc = funcs->gradBiasFunc;
}

void my_perceptron_create(my_percep_funcs_t *funcs, \
            const unsigned int count, ...)
{
    va_list args;
    va_start(args, count);
    unsigned int i;
    for (i = 0; i < count; i++) {
        my_perceptron_t *P = va_arg(args, my_perceptron_t *);
        create_preceptron(P, funcs);
    }
    va_end(args);
}
