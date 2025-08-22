#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include "ss.h"

const double EPSILON = 1e-12;

bool is_zero(double num)
{
    if (fabs(num) < EPSILON)
        return true;
    else
        return false;
}

bool is_positive(double num)
{
    if (num > EPSILON)
        return true;
    else
        return false;
}

void clean_input(void)
{
    while (getchar() != '\n') continue;
}
