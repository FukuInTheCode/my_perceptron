#include "../../includes/my.h"

void my_Perceptron_GradTheta(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets, my_Matrix *result) {
    my_Matrix prediction = {.m=0, .n=0};
    my_Perceptron_Predict(P, inputs, &prediction);

    my_Matrix negTargets = {.m=0, .n=0};
    my_Matrix_MultiplyByScalar(targets, -1, &negTargets);

    my_Matrix difference = {.m=0, .n=0};
    my_Matrix_Add(&difference, 2, &prediction, &negTargets);

    my_Matrix inputsT = {.m=0, .n=0};
    my_Matrix_T(inputs, &inputsT);
    
    my_Matrix notMean = {.m=0, .n=0};
    my_Matrix_Product(&notMean, 2, &inputsT, &difference);

    my_Matrix_MultiplyByScalar(&notMean, 1.0/inputs->m, result);

    my_Matrix_Free(5, &inputsT, &prediction, &difference, &negTargets, &notMean);
}

double my_Perceptron_GradBias(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets) {
    my_Matrix prediction = {.m=0, .n=0};
    my_Perceptron_Predict(P, inputs, &prediction);

    my_Matrix negTargets = {.m=0, .n=0};
    my_Matrix_MultiplyByScalar(targets, -1, &negTargets);

    my_Matrix difference = {.m=0, .n=0};
    my_Matrix_Add(&difference, 2, &prediction, &negTargets);

    double res = my_Matrix_Sum(&difference);

    my_Matrix_Free(3, &prediction, &negTargets, &difference);

    return res / inputs->m;
}