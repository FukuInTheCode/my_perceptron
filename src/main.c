#include "../includes/my.h"

double __mysq(double x) {
    return x + 1;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    my_Perceptron P = {.theta.m = 0, .theta.n = 0};

    my_Perceptron_Free(1, &P);

    return 0;
}