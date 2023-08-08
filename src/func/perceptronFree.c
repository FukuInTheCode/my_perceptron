#include "../../includes/my.h"

void __FreePerceptron(my_Perceptron *P) {
    my_Matrix_Free(1, &(P->theta));
}

void my_Perceptron_Free(const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0; i<count; i++) {
        my_Perceptron *P = va_arg(args, my_Perceptron *);
        __FreePerceptron(P);
    }
}