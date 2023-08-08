#include "../../includes/my.h"

void my_Perceptron_Predict(my_Perceptron *entity, my_Matrix *inputs, my_Matrix *predictions) {
    my_Matrix withoutBias = {.m=0, .n=0};
    my_Matrix_Product(&withoutBias, 2, inputs, entity->theta);
    my_Matrix_AddScalar(&withoutBias, entity->bias, predictions);
}