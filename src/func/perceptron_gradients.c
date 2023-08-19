#include "../../includes/my.h"

void my_perceptron_grad_theta(my_perceptron_t *P, my_matrix_t *inputs, \
                    my_matrix_t *targets, my_matrix_t *result)
{
    my_matrix_t prediction = {.m = 0, .n = 0};
    my_perceptron_predict(P, inputs, &prediction);

    my_matrix_t neg_targets = {.m = 0, .n = 0};
    my_matrix_multiplybyscalar(targets, -1, &neg_targets);

    my_matrix_t difference = {.m = 0, .n = 0};
    my_matrix_add(&difference, 2, &prediction, &neg_targets);

    my_matrix_t inputs_transpose = {.m = 0, .n = 0};
    my_matrix_transpose(inputs, &inputs_transpose);

    my_matrix_t not_mean = {.m = 0, .n = 0};
    my_matrix_product(&not_mean, 2, &inputs_transpose, &difference);

    my_matrix_multiplybyscalar(&not_mean, 1.0 / inputs->m, result);

    my_matrix_free(5, &inputs_transpose, &prediction, &difference, \
                        &neg_targets, &not_mean);
}

double my_perceptron_grad_bias(my_perceptron_t *P, my_matrix_t *inputs, \
                        my_matrix_t *targets)
{
    my_matrix_t prediction = {.m = 0, .n = 0};
    my_perceptron_predict(P, inputs, &prediction);

    my_matrix_t neg_targets = {.m = 0, .n = 0};
    my_matrix_multiplybyscalar(targets, -1, &neg_targets);

    my_matrix_t difference = {.m = 0, .n = 0};
    my_matrix_add(&difference, 2, &prediction, &neg_targets);

    double res = my_matrix_sum(&difference);

    my_matrix_free(3, &prediction, &neg_targets, &difference);

    return res / inputs->m;
}
