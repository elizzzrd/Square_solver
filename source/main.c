#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include "structures.h"
#include "input_output.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"
#include "tests.h"


static Test data_for_tests[] = {
    {{.a = 0, .b = 0, .c = 0}, {.type = ALL_REAL_NUMBERS}},
    {{.a = 0, .b = 0, .c = 1}, {.type = NO_SOLUTION}},
    {{.a = 0, .b = 4, .c = 2}, {.type = ONE_REAL_ROOT, .x0 = -0.5}},
    {{.a = 1, .b = -2, .c = 1}, {.type = ONE_REAL_ROOT, .x0 = 1}},
    {{.a = 1, .b = -5, .c = 6}, {.type = TWO_REAL_ROOTS, .real_roots[0] = 2, .real_roots[1] = 3}},
    {{.a = 1, .b = 2, .c = 2}, {.type = TWO_COMPLEX_ROOTS, .complex_roots[0].real = -1, 
        .complex_roots[0].imag = 1, .complex_roots[1].real = -1, .complex_roots[1].imag = -1}}
};

size_t number_of_tests = sizeof(data_for_tests) / sizeof(data_for_tests[0]);


int main(void)
{
	SquareEquationCoefs Coefs;
	QuadraticSolution Solution;

	printf("Solving ax^2 + bx + c = 0\n\n");
	read_input(&Coefs);

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

	print_solution(Solution);

	test_solve_square(data_for_tests, number_of_tests);

	printf("The program is finished.\n");
    return 0;
}
