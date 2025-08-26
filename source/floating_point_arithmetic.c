#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "structures.h"
#include "floating_point_arithmetic.h"



bool is_zero(double num)
{
    return (fabs(num) < EPSILON);
}

bool is_positive(double num)
{
    return (num > EPSILON);
}


void clamp_to_zero(double * number)
{
    if (is_zero(*number))
    {
        *number = 0;
    }
}

bool double_comparison(double number1, double number2)
{
    return (fabs(number1 - number2) < EPSILON);
}


bool convert_to_float(const char *str_to_convert, double * double_number) 
{
    if (str_to_convert == NULL) return false;

    char *end_of_str;
    strtod(str_to_convert, &end_of_str);

    if ((*end_of_str) == '\0')
    {
        (*double_number) = (*str_to_convert);
        return true;
    }
    else
    {
        return false;
    }
}





