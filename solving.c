#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <assert.h>
#include "ss.h"


void linear_equation_solve(struct input *const coef, struct output *const roots)
{
    assert(coef != NULL && "NULL pointer");
    assert(roots != NULL && "NULL pointer");

	if (is_zero(coef->b))
    {
		if (is_zero(coef->c))
		{
			roots->type = ALL_REAL_NUMBERS;
		}
		else
		{
			roots->type = NO_SOLUTION;
		}
    }
	else
    {
        roots->type = ONE_REAL_ROOT;

		roots->x0 = (-coef->c) / (coef->b);

        if (is_zero(roots->x0))
        {
            roots->x0 = 0;
        }
        assert(!isnan(roots->x0));
        assert(!isinf(roots->x0));
	}
}

void square_equation_solve(struct input *coef, struct output *roots)
{
    assert(coef != NULL && "NULL pointer");
    assert(roots != NULL && "NULL pointer");

	double b = coef->b;
	double a = coef->a;
	double c = coef->c;

	double D = b*b - 4*a*c;

	if (is_positive(D))
	{
		roots->type = TWO_REAL_ROOTS;
		roots->real_roots[0] = (-b + sqrt(D)) / (2*a);
		roots->real_roots[1] = (-b - sqrt(D)) / (2*a);

        if (is_zero(roots->real_roots[0]))
        {
            roots->real_roots[0] = 0;
        }
        if (is_zero(roots->real_roots[1]))
        {
            roots->real_roots[1] = 0;
        }

        assert(!isnan(roots->real_roots[0]));
        assert(!isnan(roots->real_roots[0]));
        assert(!isnan(roots->real_roots[1]));
        assert(!isnan(roots->real_roots[1]));
	}
	else if (is_zero(D)) {
        roots->type = ONE_REAL_ROOT;

        roots->x0 = (-b) / (2*a);

        assert(!isnan(roots->x0));
        assert(!isinf(roots->x0));

        if (is_zero(roots->x0))
        {
            roots->x0 = 0;
        }
	}
	else {
		roots->type = TWO_COMPLEX_ROOTS;

		double real = (-b) / (2*a);
		double imag = (sqrt(-D)) / (2*a);

        assert(!isnan(real));
        assert(!isnan(imag));
        assert(!isinf(real));
        assert(!isinf(imag));


		roots->complex_roots[0].real = real;
		roots->complex_roots[0].imag = imag;

		roots->complex_roots[1].real = real;
		roots->complex_roots[1].imag = -imag;
	}
}
