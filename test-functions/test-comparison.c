#include <math.h>
#include <stdbool.h>

const double EPSILON = 1e-12;


bool is_zero(double num)
{
    if (fabs(num) < EPSILON)
        return true;
    else
        return false;
}

