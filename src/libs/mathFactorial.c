#include "../../includes/my.h"

unsigned ll my_Factorial(const unsigned int n) {
    unsigned ll res = 1;
    unsigned int i;
    for(i=1; i<=n; i++) {
        res *= i;
    }
    return res;
}