#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "tests.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"
#include <assert.h>




int test_solve_square(Test data_for_tests[], size_t number_of_tests)
{
    int failed = 0; 
    for (size_t i = 0; i < number_of_tests; i++)
    {
        SquareEquationCoefs Coefs;
        Coefs.a = data_for_tests[i].test_coefs.a;
        Coefs.b = data_for_tests[i].test_coefs.b;
        Coefs.c = data_for_tests[i].test_coefs.c;

        QuadraticSolution Solution;
        if (is_zero(Coefs.a))
	    {
		    linear_equation_solve(&Coefs, &Solution);
	    }
	    else
	    {
		    square_equation_solve(&Coefs, &Solution);
	    }



        if (Solution.type == data_for_tests[i].type)
        {
            switch (Solution.type) {
                case NO_SOLUTION:
                {
                    break;
                }
                case ALL_REAL_NUMBERS:
                {
                    break;
                }
                case ONE_REAL_ROOT: 
                { 
                    if (!(double_comparison(Solution.x0, data_for_tests[i].x0)))
                    {
                        printf("FAILED: for coefs (a = %.2lf, b = %.2lf, c = %.2lf) received x = %.2lf (it should be %.2lf)\n",
                        Coefs.a, Coefs.b, Coefs.c, Solution.x0, data_for_tests[i].x0); 
                        failed++;
                    }
                    break;
                }
                case TWO_REAL_ROOTS:
                {
                    if (!(double_comparison(Solution.real_roots[0], data_for_tests[i].real_roots[0]) && 
                        double_comparison(Solution.real_roots[1], data_for_tests[i].real_roots[1])))
                    {
                        printf("FAILED: for coefs (a = %.2lf, b = %.2lf, c = %.2lf) received x1 = %.2lf, x2 = %.2lf (it should be %.2lf %.2lf)\n",
                        Coefs.a, Coefs.b, Coefs.c, Solution.real_roots[0],Solution.real_roots[1],
                         data_for_tests[i].real_roots[0], data_for_tests[i].real_roots[1]); 
                        failed++;
                    }
                    break;
                }
                case TWO_COMPLEX_ROOTS:
                {
                    if (!(double_comparison(Solution.complex_roots[0].imag, data_for_tests[i].complex_roots[0].imag) &&
                    double_comparison(Solution.complex_roots[1].imag, data_for_tests[i].complex_roots[1].imag) &&
                    double_comparison(Solution.complex_roots[0].real, data_for_tests[i].complex_roots[0].real) &&
                    double_comparison(Solution.complex_roots[1].real, data_for_tests[i].complex_roots[1].real)))
                    {
                        printf("FAILED with complex numbers\n");
                        failed++;
                    }
                    break;
                }
                default: 
                {
			        assert(false && "Unknown SolutionType\n");
			        break;
                }
            }
        }
        else
        {
            printf("FAILED: types of solutions doesn't match");
            failed++;
        }
    }
    return failed;
}



