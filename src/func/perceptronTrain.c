#include "../../includes/my.h"

void my_Perceptron_Train(my_perceptron_t *P, my_Matrix *inputs, my_Matrix *targets, const
 double alpha, const unsigned int stepsN, const double treshold) {
    my_Matrix GradTheta = {.m=0, .n=0};
    my_Matrix GradThetaAlpha = {.m=0, .n=0};
    my_Matrix newTheta = {.m=0, .n=0};
    double gradBias;

    unsigned int i;
    for(i=0; i<stepsN; i++) {
        if(P->errorFunc(P, inputs, targets) < treshold) break;
        P->gradThetaFunc(P, inputs, targets, &GradTheta);
    
        my_Matrix_MultiplyByScalar(&GradTheta, -1 * alpha, &GradThetaAlpha);
 
        gradBias = P->gradBiasFunc(P, inputs, targets);
        gradBias *= alpha;

        my_Matrix_Add(&newTheta, 2, &(P->theta), &GradThetaAlpha);

        P->bias = P->bias - gradBias;

        my_Matrix_Copy(&newTheta, &(P->theta));

    }
    printf("took %d iterations\n", i++);
    my_Matrix_Free(3, &GradTheta, &GradThetaAlpha, &newTheta);
}