#include "../../includes/my.h"

void __PrintPerceptron(my_perceptron_t *P) {
    printf("Perceptron's Bias: %f\n", P->bias);
    printf("Perceptron's Theta: \n");
    my_Matrix_Print(1, &(P->theta));
}

void my_Perceptron_Print(const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0; i<count; i++) {
        my_perceptron_t *P = va_arg(args, my_perceptron_t *);
        __PrintPerceptron(P);
    }
    va_end(args);
}