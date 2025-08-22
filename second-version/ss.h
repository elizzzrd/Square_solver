#pragma once


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
bool is_zero(double num);
