#include "../../includes/my.h"

void __CreatePerceptron(my_Perceptron *P, const unsigned int inputsSize, ErrorTemplate errorFunc, GradThetaTemplate gradThetaFunc, GradBiasTemplate gradBiasFunc) {
    my_Matrix_Create(inputsSize, 1, 1, &(P->theta));
    my_Matrix_RandFloat(-1, 1, 1, &(P->theta));
    P->bias = my_randFloat(-1, 1);
    P->errorFunc = errorFunc;
    P->gradThetaFunc = gradThetaFunc;
    P->gradBiasFunc = gradBiasFunc;
}

void my_Perceptron_Create(const unsigned int inputsSize, ErrorTemplate errorFunc, GradThetaTemplate gradThetaFunc, GradBiasTemplate gradBiasFunc, const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0; i<count; i++) {
        my_Perceptron *P = va_arg(args, my_Perceptron *);
        __CreatePerceptron(P, inputsSize, errorFunc, gradThetaFunc, gradBiasFunc);
    }
    va_end(args);
}