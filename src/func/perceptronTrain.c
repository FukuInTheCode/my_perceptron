#include "../../includes/my.h"

void my_Perceptron_Train(my_Perceptron *P, my_Matrix *inputs, my_Matrix *targets, const
 double alpha, const unsigned int stepsN) {
    my_Matrix GradTheta = {.m=0, .n=0};
    my_Matrix GradThetaAlpha = {.m=0, .n=0};
    my_Matrix newTheta = {.m=0, .n=0};
    double gradBias;

    unsigned int i;
    for(i=0; i<stepsN; i++) {
        my_Perceptron_GradTheta(P, inputs, targets, &GradTheta);
    
        my_Matrix_MultiplyByScalar(&GradTheta, -1 * alpha, &GradThetaAlpha);
 
        gradBias = my_Perceptron_GradBias(P, inputs, targets);
        gradBias *= alpha;

        my_Matrix_Add(&newTheta, 2, &(P->theta), &GradThetaAlpha);

        P->bias = P->bias + gradBias;

        my_Matrix_Copy(&newTheta, &(P->theta));

    }

    my_Matrix_Free(3, &GradTheta, &GradThetaAlpha, &newTheta);
}