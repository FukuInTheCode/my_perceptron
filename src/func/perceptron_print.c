#include "../../includes/my.h"

static void print_perceptron(my_perceptron_t *P)
{
    printf("Perceptron's Bias: %f\n", P->bias);
    printf("Perceptron's Theta: \n");
    my_matrix_print(1, &(P->theta));
}

void my_perceptron_print(const unsigned int count, ...)
{
    va_list args;
    va_start(args, count);
    unsigned int i;
    for (i = 0; i < count; i++) {
        my_perceptron_t *P = va_arg(args, my_perceptron_t *);
        print_perceptron(P);
    }
    va_end(args);
}
