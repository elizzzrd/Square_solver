#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include "structures.h"
#include "tests.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"




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
        square_solve(&Coefs, &Solution);


        if (Solution.type == (unsigned) data_for_tests[i].check_solution.type)
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
                    if (!(double_comparison(Solution.x0, data_for_tests[i].check_solution.x0)))
                    {
                        printf("FAILED: for coefs (a = %.2lf, b = %.2lf, c = %.2lf) received x0 = %.2lf (it should be x0 = %.2lf)\n",
                        Coefs.a, Coefs.b, Coefs.c, 
                        Solution.x0, data_for_tests[i].check_solution.x0); 
                        failed++;
                    }
                    break;
                }
                case TWO_REAL_ROOTS:
                {
                    if (!(double_comparison(Solution.real_roots[0], data_for_tests[i].check_solution.real_roots[0]) && 
                        double_comparison(Solution.real_roots[1], data_for_tests[i].check_solution.real_roots[1])))
                    {
                        printf("FAILED: for coefs (a = %.2lf, b = %.2lf, c = %.2lf) received x1 = %.2lf, x2 = %.2lf (it should be x1 = %.2lf x2 = %.2lf)\n",
                        Coefs.a, Coefs.b, Coefs.c, 
                        Solution.real_roots[0],Solution.real_roots[1],
                        data_for_tests[i].check_solution.real_roots[0], data_for_tests[i].check_solution.real_roots[1]); 
                        failed++;
                    }
                    break;
                }
                case TWO_COMPLEX_ROOTS:
                {
                    if (!(double_comparison(Solution.complex_roots[0].imag, data_for_tests[i].check_solution.complex_roots[0].imag) &&
                    double_comparison(Solution.complex_roots[1].imag, data_for_tests[i].check_solution.complex_roots[1].imag) &&
                    double_comparison(Solution.complex_roots[0].real, data_for_tests[i].check_solution.complex_roots[0].real) &&
                    double_comparison(Solution.complex_roots[1].real, data_for_tests[i].check_solution.complex_roots[1].real)))
                    {
                        double imag0 = data_for_tests[0].check_solution.complex_roots[0].imag;
                        char sign0 = (imag0 >= 0) ? '+' : '-';
                        double imag1 = data_for_tests[1].check_solution.complex_roots[1].imag;
                        char sign1 = (imag1 >= 0) ? '+' : '-';


                        printf("FAILED with complex numbers:\n");
                        printf("for coefs (a = %.2lf, b = %.2lf, c = %.2lf) received x1 = %.2lf %c %.2lfi, x2 = %.2lf %c %.2lfi",
                            Coefs.a, Coefs.b, Coefs.c, 
                            Solution.complex_roots[0].real, sign0, fabs(Solution.complex_roots[0].imag),
                            Solution.complex_roots[1].real, sign1, fabs(Solution.complex_roots[1].imag));
                        printf(" (it should be x1 = %.2lf %c %.2lfi, x2 = %.2lf %c %.2lfi)\n",
                            data_for_tests[i].check_solution.complex_roots[0].real, sign0, fabs(data_for_tests[i].check_solution.complex_roots[0].imag),
                            data_for_tests[i].check_solution.complex_roots[1].real, sign1, fabs(data_for_tests[i].check_solution.complex_roots[1].imag));
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



