#include "../../includes/my.h"

static void free_perceptron(my_perceptron_t *P)
{
    my_matrix_free(1, &(P->theta));
}

void my_perceptron_free(const unsigned int count, ...)
{
    va_list args;
    va_start(args, count);
    unsigned int i;
    for (i = 0; i < count; i++) {
        my_perceptron_t *P = va_arg(args, my_perceptron_t *);
        free_perceptron(P);
    }
    va_end(args);
}
