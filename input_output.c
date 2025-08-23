#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include "ss.h"

void get_input(struct input *ptr)
{
	printf("Enter a, b, c:\n");
	printf("a = ");
	ptr->a = get_coef();

	printf("b = ");
	ptr->b = get_coef();

	printf("c = ");
	ptr->c = get_coef();
}

double get_coef(void)
{
	double temp = 0;
	while (1)
	{
		if (scanf("%lf", &temp) != 1 || isnan(temp) || isinf(temp)) {
			clean_input();
			printf("Invalid coefficient. Please try again: ");
			continue;
		}
		else
		{
			break;
		}
	}
	clean_input();
	return temp;

}

void show_solution(const struct output ptr)
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
		case ONE_REAL_ROOT:
		{
			printf("One real root:\n");
			printf("x = %.2lf\n", ptr.x0);

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
			fprintf(stderr, "Unknown SolutionType\n");
			break;
	}
}
