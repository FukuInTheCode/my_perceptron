#include "../../includes/my.h"

void my_perceptron_predict(my_perceptron_t *P, my_matrix_t *inputs, \
                                my_matrix_t *predictions)
{
    my_matrix_t without_bias = {.m = 0, .n = 0};
    my_matrix_product(&without_bias, 2, inputs, &(P->theta));
    my_matrix_addscalar(&without_bias, P->bias, predictions);
    my_matrix_free(1, &without_bias);
}
