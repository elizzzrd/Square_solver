#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "tests.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"
#include <assert.h>
#include "read_file.h"

/*
static Test data_for_tests[] = {
    {{.a = 0, .b =  0, .c = 0}, {.type = ALL_REAL_NUMBERS}},
    {{.a = 0, .b =  0, .c = 1}, {.type = NO_SOLUTION}},
    {{.a = 0, .b = 0, .c = 0.00001}, {.type = NO_SOLUTION}},
    {{.a = 1, .b =  0, .c = 0}, {.type = ONE_REAL_ROOT, .x0 = 0}},
    {{.a = 1, .b =  2, .c = 1}, {.type = ONE_REAL_ROOT, .x0 = -1}},
    {{.a = 0, .b =  4, .c = 2}, {.type = ONE_REAL_ROOT, .x0 = -0.5}},
    {{.a = 1, .b = -2, .c = 1}, {.type = ONE_REAL_ROOT, .x0 = 1}},
    {{.a = 1e-10, .b = 2e-10, .c = 1e-10}, {.type = ONE_REAL_ROOT, .x0 = -1}}, 
    //{{.a = 1, .b = 1e6, .c = 1}, {.type = TWO_REAL_ROOTS, .real_roots[0] = -999999.999999, .real_roots[1] = -0.000001}},
    {{.a = 1, .b =  5, .c = 6}, {.type = TWO_REAL_ROOTS, .real_roots[0] = -3, .real_roots[1] = -2}},
    {{.a = 1, .b = -5, .c = 6}, {.type = TWO_REAL_ROOTS, .real_roots[0] = 2, .real_roots[1] = 3}},
    {{.a = 1, .b =  0, .c = 1}, {.type = TWO_COMPLEX_ROOTS, .complex_roots[0].real = 0, 
                                                            .complex_roots[0].imag = 1, 
                                                            .complex_roots[1].real = 0, 
                                                            .complex_roots[1].imag = -1},},
    {{.a = 1, .b =  2, .c = 2}, {.type = TWO_COMPLEX_ROOTS, .complex_roots[0].real = -1, 
                                                            .complex_roots[0].imag = 1, 
                                                            .complex_roots[1].real = -1,
                                                            .complex_roots[1].imag = -1},}
    };

    static const size_t number_of_tests = sizeof(data_for_tests) / sizeof(data_for_tests[0]);
*/



int main(void)
{
    Test data_for_tests[NMAX];
    read_file(data_for_tests, "tests/data.txt");
    static const size_t number_of_tests = sizeof(data_for_tests) / sizeof(data_for_tests[0]);
    printf("\nTesting equation solver\n\n");

    int failed = 0;
    failed = test_solve_square(data_for_tests, number_of_tests);

    if (!failed)
    {
        printf("All tests passed!\n\n");
    }
    else
    {
        printf("%d tests failed.\n", failed);
    }

    return 0;
}