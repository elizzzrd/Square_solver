#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include "structures.h"
#include "input_output.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"




int main(void)
{
	SquareEquationCoefs Coefs;
	QuadraticSolution Solution;

	printf("Solving ax^2 + bx + c = 0\n\n");
	read_input(&Coefs);

	printf("\nYou've entered:\n");
	printf("a = %.2lf, b = %.2lf, c = %.2lf\n\n", Coefs.a, Coefs.b, Coefs.c);

	if (is_zero(Coefs.a))
	{
		linear_equation_solve(&Coefs, &Solution);
	}
	else
	{
		square_equation_solve(&Coefs, &Solution);
	}

	print_solution(Solution);


	printf("The program is finished.\n");
    return 0;
}
