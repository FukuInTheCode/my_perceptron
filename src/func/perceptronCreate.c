#include "../../includes/my.h"

void my_Perceptron_Create(my_Perceptron *entity, const unsigned int inputsSize) {
    my_Matrix_Create(inputsSize, 1, 1, entity->theta);
}