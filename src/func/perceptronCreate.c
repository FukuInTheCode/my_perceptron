#include "../../includes/my.h"

void __CreatePerceptron(my_Perceptron *P, const unsigned int inputsSize) {
    my_Matrix_Create(inputsSize, 1, 1, &(entity->theta));
    my_Matrix_RandFloat(-1, 1, 1, &(entity->theta));
    entity->bias = my_randFloat(-1, 1);
}

void my_Perceptron_Create(const unsigned int inputsSize, const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0; i<count; i++) {
        my_Perceptron *P = va_arg(args, my_Perceptron *);
        __CreatePerceptron(P, inputsSize);
    }
}