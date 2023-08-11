#include "../../includes/my.h"

double my_power(double x, unsigned int n) {
    int res = 1;
    unsigned int i;
    for(i=0; i<n; i++) {
        res *= x;
    }
    return res;
}