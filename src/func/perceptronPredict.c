#include "../../includes/my.h"

void my_Perceptron_Predict(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *predictions) {
    my_Matrix withoutBias = {.m=0, .n=0};
    my_Matrix_Product(&withoutBias, 2, inputs, &(P->theta));
    my_Matrix_AddScalar(&withoutBias, P->bias, predictions);
    my_Matrix_Free(1, &withoutBias);
}