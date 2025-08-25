#pragma once
#include "structures.h"

typedef struct {
    int type;
    union {
		double x0;
		double real_roots[2];
		ComplexNumber complex_roots[2];
	};
} Check_answers;


typedef struct {
    SquareEquationCoefs test_coefs;
    Check_answers check_solution;
} Test;


int test_solve_square(Test data_for_tests[], size_t number_of_tests);

