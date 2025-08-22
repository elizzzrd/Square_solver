#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include "ss.h"

const double EPSILON = 1e-12;

void clean_input(void)
{
    while (getchar() != '\n') continue;
}

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
		if (scanf("%lf", &temp) != 1) {
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

void linear_equation_solve(struct input *coef, struct output *roots)
{
	if (is_zero(coef->b))
		if (is_zero(coef->c))
		{
			roots->type = ALL_REAL_NUMBERS;
		}
		else
		{
			roots->type = NO_SOLUTION;
		}
	else {
		roots->x0 = (-coef->c)/ (coef->b);
		roots->type = ONE_REAL_ROOT;
	}
}

void square_equation_solve(struct input *coef, struct output *roots)
{
	double b = coef->b;
	double a = coef->a;
	double c = coef->c;

	double D = b*b - 4*a*c;

	if (D > 0)
	{
		roots->type = TWO_REAL_ROOTS;
		roots->real_roots[0] = (-b + sqrt(D)) / (2*a);
		roots->real_roots[1] = (-b - sqrt(D)) / (2*a);
	}
	else if (is_zero(D)) {
		roots->x0 = (-b) / (2*a);
		roots->type = ONE_REAL_ROOT;
	}
	else {
		roots->type = TWO_COMPLEX_ROOTS;

		double real = (-b) / (2*a);
		double imag = (sqrt(-D)) / (2*a);

		roots->complex_roots[0].real = real;
		roots->complex_roots[0].imag = imag;

		roots->complex_roots[1].real = real;
		roots->complex_roots[1].imag = -imag;
	}
}

void show_solution(struct output *ptr)
{
	switch (ptr->type) {
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
			printf("x = %.2lf\n", ptr->x0);
			break;
		}
		case TWO_REAL_ROOTS:
		{
			printf("Two real roots:\n");
			printf("x1 = %.2lf\n", ptr->real_roots[0]);
			printf("x2 = %.2lf\n", ptr->real_roots[1]);
			break;
		}
		case TWO_COMPLEX_ROOTS:
		{
			printf("Two complex roots:\n");
			for (int i = 0; i < 2; i++) {
                double imag = ptr->complex_roots[i].imag;
                char sign = (imag >= 0) ? '+' : '-';
                printf("x%d = %.2f %c %.2fi\n", i + 1, ptr->complex_roots[i].real,
                       sign, fabs(imag));
            }
            break;
		}
		default:
			fprintf(stderr, "Unknown SolutionType\n");
			break;
	}
}


bool is_zero(double num)
{
    if (fabs(num) < EPSILON)
        return true;
    else
        return false;
}
