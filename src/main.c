#include "../includes/my.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    my_Perceptron P = {.theta.m = 0, .theta.n = 0};

    my_Perceptron_Create(&P, 2);

    printf("%u, %u\n", P.theta.m, P.theta.n);

    my_Perceptron_Free(1, &P);

    return 0;
}