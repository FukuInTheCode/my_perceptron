#include "../../includes/my.h"

void __CreatePerceptron(my_perceptron_t *P, const unsigned int inputsSize,\
const unsigned int outputsSize, ErrorTemplate errorFunc, GradThetaTemplate gradThetaFunc, GradBiasTemplate gradBiasFunc) {
    my_Matrix_Create(inputsSize, outputsSize, 1, &(P->theta));
    my_Matrix_RandFloat(-1, 1, 1, &(P->theta));
    P->bias = my_randFloat(-1, 1);
    P->errorFunc = errorFunc;
    P->gradThetaFunc = gradThetaFunc;
    P->gradBiasFunc = gradBiasFunc;
}

void my_Perceptron_Create(const unsigned int inputsSize, const unsigned int outputsSize, ErrorTemplate errorFunc, GradThetaTemplate gradThetaFunc, GradBiasTemplate gradBiasFunc, const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0; i<count; i++) {
        my_perceptron_t *P = va_arg(args, my_perceptron_t *);
        __CreatePerceptron(P, inputsSize, outputsSize, errorFunc, gradThetaFunc, gradBiasFunc);
    }
    va_end(args);
}