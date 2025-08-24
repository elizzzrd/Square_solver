#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "structures.h"
#include <string.h>
#include <assert.h>
#include "input_output.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"
#include "read_file.h"
#include "tests.h"
#include "command_argc.h"



const char *options[] = {
	"--help",
	"--tests",
	"--solve",
	"-h",
	"-t",
	"-s"
}; 


char getchoice(char *choice)
{
	size_t index = sizeof(options)/ sizeof(options[0]);
	for (size_t i = 0; i < index; i++)
	{
		if (strcmp(options[i], choice) == 0)
		{
			if (choice[1] == '-')
			{
				return (options[i][2]);
			}
			else
			{
				return (options[i][1]);
			}
		}
	}

    printf("Sorry, you command has not been found.\n");
	return ('n');
}


void print_help(void)
{
    
	printf("\nThis program is able to solve square equations!!\n"
		   "Enter coefficients a,b,c for equation ax^2 + bx + c = 0\n"
		   "and you'll receive a solution.\n\n");
}

void run_tests(void)
{
	Test data_for_tests[NMAX];
    read_file(data_for_tests);
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
}

void lets_solve_square_equation(void)
{
	SquareEquationCoefs Coefs;
	QuadraticSolution Solution;

	printf("Solving ax^2 + bx + c = 0\n\n");
	read_input(&Coefs);

	printf("\nYou've entered:\n");
	printf("a = %.2lf, b = %.2lf, c = %.2lf\n\n", Coefs.a, Coefs.b, Coefs.c);

	square_solve(&Coefs, &Solution);

	print_solution(Solution);

	printf("The program is finished.\n");
}