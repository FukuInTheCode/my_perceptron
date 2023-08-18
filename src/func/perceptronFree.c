#include "../../includes/my.h"

void __FreePerceptron(my_perceptron_t *P) {
    my_Matrix_Free(1, &(P->theta));
}

void my_Perceptron_Free(const unsigned int count, ...) {
    va_list args;
    va_start(args, count);
    unsigned int i;
    for(i=0; i<count; i++) {
        my_perceptron_t *P = va_arg(args, my_perceptron_t *);
        __FreePerceptron(P);
    }
    va_end(args);
}