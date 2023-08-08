#include "../../includes/my.h"

void my_Perceptron_Create(my_Perceptron *entity, const unsigned int inputsSize) {
    my_Matrix_Create(inputsSize, 1, 1, &(entity->theta));
    my_Matrix_RandFloat(-1, 1, 1, &(entity->theta));
    entity->bias = my_randFloat(-1, 1);
}