#include <math.h>
#include <stdio.h>

int main() {
    double x = 0.0 / 0.0; // NaN
    double y = 1.0 / 0.0; // +Inf
    double z = -1.0 / 0.0; // -Inf

    if (isnan(x)) {
        printf("x is NaN\n");
    }


    if (isinf(y)) {
        printf("y is Infinity\n");
    }


    if (isinf(z)) {
        printf("z is Infinity\n");
    }

    if (isfinite(1.0)) {
        printf("1.0 is finite\n");
    }

    return 0;
}
