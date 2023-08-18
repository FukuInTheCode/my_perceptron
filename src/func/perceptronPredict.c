#include "../../includes/my.h"

void my_perceptron_predict(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *predictions)
{
    my_Matrix without_bias = {.m = 0, .n = 0};
    my_matrix_product(&without_bias, 2, inputs, &(P->theta));
    my_matrix_addscalar(&without_bias, P->bias, predictions);
    my_Matrix_Free(1, &without_bias);
}