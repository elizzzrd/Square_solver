#pragma once

#include "structures.h"

struct check_answers {
    enum SolutionType type;
    union {
		double x0;
		double real_roots[2];
		ComplexNumber complex_roots[2];
	};
};

typedef struct {
    SquareEquationCoefs test_coefs;
    struct check_answers;
} Test;



int test_solve_square(Test data_for_tests[], size_t number_of_tests);

