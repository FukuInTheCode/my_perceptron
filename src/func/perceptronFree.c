#include "../../includes/my.h"

void my_Perceptron_Free(my_Perceptron *P) {
    my_Matrix_Free(1, &(P->theta));
}