#include <stdio.h>
#include <math.h>
#include <stdbool.h>
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

// NOTE: Fun note
// Ctrl+C = interrupt program
// Ctrl+Z = suspend program
// Ctrl+D = EOF = end of file
// Ctrl+L = EOL = end of line
// Ctrl+X = stop, Ctrl+Q = resume
// Ctrl+[ = ESC
// Ctrl+J = Enter