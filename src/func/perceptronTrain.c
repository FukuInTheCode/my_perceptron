#include "../../includes/my.h"

void my_Perceptron_Train(my_perceptron_t *P, my_matrix_t *inputs, my_matrix_t *targets, const
 double alpha, const unsigned int stepsN, const double treshold) {
    my_matrix_t GradTheta = {.m=0, .n=0};
    my_matrix_t GradThetaAlpha = {.m=0, .n=0};
    my_matrix_t newTheta = {.m=0, .n=0};
    double gradBias;

    unsigned int i;
    for(i=0; i<stepsN; i++) {
        if(P->errorFunc(P, inputs, targets) < treshold) break;
        P->gradThetaFunc(P, inputs, targets, &GradTheta);

        my_matrix_multiplybyscalar(&GradTheta, -1 * alpha, &GradThetaAlpha);

        gradBias = P->gradBiasFunc(P, inputs, targets);
        gradBias *= alpha;

        my_matrix_add(&newTheta, 2, &(P->theta), &GradThetaAlpha);

        P->bias = P->bias - gradBias;

        my_Matrix_Copy(&newTheta, &(P->theta));

    }
    printf("took %d iterations\n", i++);
    my_matrix_free(3, &GradTheta, &GradThetaAlpha, &newTheta);
}