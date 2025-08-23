#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <assert.h>
#include "structures.h" /// TODO: better not use relative headers, prefer "-I headers"
#include "input_output.h"
#include "floating_point_arithmetic.h"

void skip_line(void) // TODO: better name, skip_line?
{
    while (getchar() != '\n') continue; // TODO: What if EOF + Ctrl+D?
}

void read_input(SquareEquationCoefs *coef) 
{
	printf("Enter a, b, c:\n");
	printf("a = ");
	coef->a = read_coef();

	printf("b = ");
	coef->b = read_coef();

	printf("c = ");
	coef->c = read_coef();
}

double read_coef(void)
{
	double temp = 0;

	while (scanf("%lf", &temp) != 1 || isnan(temp) || isinf(temp)) {
		skip_line();
		printf("Invalid coefficient. Please try again: ");
	}

	skip_line();
	return temp;

}

void print_solution(const QuadraticSolution ptr)
{
	switch (ptr.type) {
		case NO_SOLUTION:
		{
			printf("The equation has no solutions\n");
			break;
		}
		case ALL_REAL_NUMBERS:
		{
			printf("x belongs to the real numbers.\n");
			break;
		}
		case ONE_REAL_ROOT: // TODO: you could differentiate two roots with the same value (x - 2)^2 = 0 and one linear root x - 5 = 0
		{
			printf("One real root:\n");
			printf("x = %.2lf\n", ptr.x0); // TODO: 

			break;
		}
		case TWO_REAL_ROOTS:
		{
			printf("Two real roots:\n");
			printf("x1 = %.2lf\n", ptr.real_roots[0]);
		    printf("x1 = %.2lf\n", ptr.real_roots[1]);

			break;
		}
		case TWO_COMPLEX_ROOTS:
		{
			printf("Two complex roots:\n");
			for (int i = 0; i < 2; i++) {
                double imag = ptr.complex_roots[i].imag;
                char sign = (imag >= 0) ? '+' : '-';
                printf("x%d = %.2f %c %.2fi\n", i + 1, ptr.complex_roots[i].real,
                       sign, fabs(imag));
            }
            break;
		}
		default: 
			assert(false && "Unknown SolutionType\n");
			break;
	}
}
