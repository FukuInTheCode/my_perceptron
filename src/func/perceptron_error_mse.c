#include "../../includes/my.h"

static double my_square(double x)
{
    return x * x;
}

double my_perceptron_calcerror_mse(my_perceptron_t *P, my_matrix_t *inputs, \
                                        my_matrix_t *targets)
{
    my_matrix_t prediction = {.m = 0, .n = 0};
    my_perceptron_predict(P, inputs, &prediction);

    my_matrix_t neg_targets = {.m = 0, .n = 0};
    my_matrix_multiplybyscalar(targets, -1, &neg_targets);

    my_matrix_t difference = {.m = 0, .n = 0};
    my_matrix_add(&difference, 2, &prediction, &neg_targets);

    my_matrix_t difference_squared = {.m = 0, .n = 0};
    my_matrix_applyfunc(&difference, my_square, &difference_squared);

    double res = my_matrix_sum(&difference_squared);
    res /= inputs->m * 2;

    my_matrix_free(4, &prediction, &difference,\
                &neg_targets, &difference_squared);

    return res;
}
