#include "../../includes/my.h"

void my_Perceptron_Print(my_Perceptron *P) {
    printf("Perceptron's Bias: %f\n", P->bias);
    printf("Perceptron's Theta: \n");
    my_Matrix_Print(1, &(P->theta));
}