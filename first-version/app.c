#include <stdio.h>
#include <math.h>
#include <float.h>

struct input {
	double a;
	double b;
	double c;
};

enum SolutionType {
	NO_SOLUTION,
	ALL_REAL_NUMBERS,
	ONE_REAL_ROOT,
	TWO_REAL_ROOTS,
	TWO_COMPLEX_ROOTS,
};

typedef struct {
	double real;
	double imag;
} ComplexNumber;


struct output {
	enum SolutionType type;
	union {
		double x0;
		double real_roots[2];
		ComplexNumber complex_roots[2];
	};
};

void clean_input(void);
double get_coef(void);
void get_input(struct input *ptr);
void linear_equation_solve(struct input *coef, struct output *roots);
void square_equation_solve(struct input *coef, struct output *roots);
void show_solution(struct output *ptr);


int main(void)
{
	struct input Coefs;
	struct output Solution;

	printf("Solving ax^2 + bx + c = 0\n");
	get_input(&Coefs);

	printf("You've entered:\n");
	printf("a = %.2lf, b = %.2lf, c = %.2lf\n", Coefs.a, Coefs.b, Coefs.c);

	if (fabs(Coefs.a) < DBL_EPSILON)
	{
		linear_equation_solve(&Coefs, &Solution);
	}
	else
	{
		square_equation_solve(&Coefs, &Solution);
	}

	show_solution(&Solution);

	printf("The program is finished.\n");
    return 0;
}


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
	if ((fabs(coef->b)) < DBL_EPSILON)
		if ((fabs(coef->c)) < DBL_EPSILON)
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
	else if ((fabs(D)) < DBL_EPSILON) {
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
