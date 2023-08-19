#include "../../includes/my.h"

void my_perceptron_train(my_perceptron_t *P, my_matrix_t *inputs, \
                my_matrix_t *targets, my_params_t *hparams)
{
    my_matrix_t grad_theta = {.m = 0, .n = 0};
    my_matrix_t grad_theta_alpha = {.m = 0, .n = 0};
    my_matrix_t new_theta = {.m = 0, .n = 0};
    double grad_bias;

    for (uint16_t i = 0; i < hparams->iterations; i++) {
        if (P->error_func(P, inputs, targets) < hparams->threshold) break;
        P->funcs.grad_theta_func(P, inputs, targets, &grad_theta);

        my_matrix_multiplybyscalar(&grad_theta, -1 * alpha, &grad_theta_alpha);

        grad_bias = P->funcs.grad_bias_func(P, inputs, targets);
        grad_bias *= hparams->alpha;

        my_matrix_add(&new_theta, 2, &(P->theta), &grad_theta_alpha);
        P->bias = P->bias - grad_bias;
        my_matrix_copy(&new_theta, &(P->theta));
    }
    printf("took %d iterations\n", i++);
    my_matrix_free(3, &grad_theta, &grad_theta_alpha, &new_theta);
}
