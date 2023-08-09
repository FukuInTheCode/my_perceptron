#include "../includes/my.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    my_Perceptron P = {.theta.m = 0, .theta.n = 0};

    my_Perceptron_Create(2, 1, &P);

    my_Perceptron_Print(&P);

    my_Perceptron_Free(1, &P);

    return 0;
}