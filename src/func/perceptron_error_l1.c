#include "../../includes/my.h"

double my_perceptron_calcerror_l1(my_perceptron_t *P, my_matrix_t *inputs, \
                                    my_matrix_t *targets)
{
    my_matrix_t prediction = {.m = 0, .n = 0};
    my_perceptron_predict(P, inputs, &prediction);

    my_matrix_t neg_targets = {.m = 0 , .n = 0};
    my_matrix_multiplybyscalar(targets, -1, &neg_targets);

    my_matrix_t difference = {.m = 0, .n = 0};
    my_matrix_add(&difference, 2, &prediction, &neg_targets);

    my_matrix_t absolute_difference = {.m = 0, .n = 0};
    my_matrix_applyfunc(&difference, my_abs, &absolute_difference);

    double res = my_matrix_sum(&absolute_difference);
    res /= inputs->m;

    my_Matrix_Free(4, &prediction, &difference, \
        &neg_targets, &absolute_difference);

    return res;
}