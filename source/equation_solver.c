#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include "structures.h"
#include "equation_solver.h"
#include "floating_point_arithmetic.h"


void square_solve(SquareEquationCoefs * Coef, QuadraticSolution * Solution)
{
    if (is_zero(Coef->a))
	{
		linear_equation_solve(Coef, Solution);
	}
	else
	{
		square_equation_solve(Coef, Solution);
	}
}


void linear_equation_solve(SquareEquationCoefs * coef, QuadraticSolution * roots)
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

        clamp_to_zero(&roots->x0);

        assert(!isnan(roots->x0) && "Root cant be nan");
        assert(!isinf(roots->x0) && "Root cant be infinity");
	}
}


void square_equation_solve(SquareEquationCoefs *coef, QuadraticSolution *roots)
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
        double sqrt_D = sqrt(D);
		roots->real_roots[0] = (-b + sqrt_D) / (2*a);
		roots->real_roots[1] = (-b - sqrt_D) / (2*a);

        if (roots->real_roots[0] > roots->real_roots[1])
        {
            double temp = roots->real_roots[1];
            roots->real_roots[1] = roots->real_roots[0];
            roots->real_roots[0] = temp;
        }

        clamp_to_zero(&roots->real_roots[0]);
        clamp_to_zero(&roots->real_roots[1]);
       
        assert(!isnan(roots->real_roots[0]) && "Root cant be nan");
        assert(!isinf(roots->real_roots[0]) && "Root cant be infinity");
        assert(!isnan(roots->real_roots[1]) && "Root cant be nan");
        assert(!isinf(roots->real_roots[1]) && "Root cant be infinity"); 
	}
	else if (is_zero(D)) 
	{
        roots->type = ONE_REAL_ROOT;

        roots->x0 = (-b) / (2*a);

        clamp_to_zero(&roots->x0);

        assert(!isnan(roots->x0) && "Root cant be nan");
        assert(!isinf(roots->x0) && "Root cant be infinity");
	}
	else {
		roots->type = TWO_COMPLEX_ROOTS;

		double real = (-b) / (2*a);
		double imag = (sqrt(-D)) / (2*a);


		roots->complex_roots[0].real = real;
		roots->complex_roots[0].imag = imag;
		roots->complex_roots[1].real = real;
		roots->complex_roots[1].imag = -imag;

        assert(!isnan(real) && "Root cant be nan");
        assert(!isnan(imag) && "Root cant be infinity");
        assert(!isinf(real) && "Root cant be nan");
        assert(!isinf(imag) && "Root cant be infinity");
	}
}
