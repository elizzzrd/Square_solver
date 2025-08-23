#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include "ss.h"



int main(void)
{
	struct input Coefs;
	struct output Solution;

	printf("Solving ax^2 + bx + c = 0\n");
	get_input(&Coefs);

	printf("You've entered:\n");
	printf("a = %.2lf, b = %.2lf, c = %.2lf\n", Coefs.a, Coefs.b, Coefs.c);

	if (is_zero(Coefs.a))
	{
		linear_equation_solve(&Coefs, &Solution);
	}
	else
	{
		square_equation_solve(&Coefs, &Solution);
	}

	show_solution(Solution);

	printf("The program is finished.\n");
    return 0;
}
