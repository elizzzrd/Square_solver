#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "structures.h"
#include "input_output.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"
#include "read_file.h"
#include "tests.h"
#include "command_argc.h"





const char *options[] = {
	"--help", "-h",
	"--tests","-t",
	"--solve", "-s",
	"--file", "-f",
	"--coefs", "-c"
}; 


char getchoice(const char *choice)
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
    printf("\nSorry, unknown flag, type help.\n");
	return ('n');
}


void print_help(void)
{
	printf("\nHello, this is square solver program!!!\n");
	printf("\nPossible flags to use:\n\n"
			"\"-h\" or \"--help\" - provide information about usage of this program.\n\n"
			"\"-s\" or \"--solve\" - launch square equations solver.\n\n"
			"\"-t\" or \"--tests\" - launch tests for equation solver.\n\n"
			"\"-f\" or \"--file\" -  launch tests for equation solver from file you provide.\n"
			"syntax: [\"name of programm\"] \"--file\" [\"path to file\"]\n\n"
			"\"-c\" or \"--coefs\" - launch square equation solver with coefficients you enter.\n"
			"syntax: [\"name of programm\"] \"--coefs\" \"a b c\" for equation ax^2 + bx + c = 0\n\n");

}


void run_tests(void)
{
	Test data_for_tests[NMAX];
    run_tests_command_line(data_for_tests, "tests/data.txt");
}

void use_testdata_from_file(Flag command_argc)
{
	Test data_for_tests[NMAX];
    run_tests_command_line(data_for_tests, command_argc.filename);
}

void run_tests_command_line(Test data_for_tests[], const char * filename)
{
	read_file(data_for_tests, filename);
    const size_t number_of_tests = sizeof(*data_for_tests) / sizeof(data_for_tests[0]);
    printf("\nTesting equation solver\n\n");

    int failed = 0;
    failed = test_solve_square(data_for_tests, number_of_tests);

    if (!failed)
    {
        printf("All tests passed!\n\n");
    }
    else
    {
        printf("%d tests failed.\n\n", failed);
    }
	printf("The program is finished.\n\n");
}


void lets_solve_square_equation(void)
{
	SquareEquationCoefs Coefs = {};
	QuadraticSolution Solution = {};

	printf("Solving ax^2 + bx + c = 0\n\n");
	read_input(&Coefs);

	printf("\nYou've entered:\n");
	printf("a = %.2lf, b = %.2lf, c = %.2lf\n\n", Coefs.a, Coefs.b, Coefs.c);

	square_solve(&Coefs, &Solution);

	print_solution(Solution);

	printf("The program is finished.\n\n");
}


void instant_coefs_input(Flag command_argc)
{
	SquareEquationCoefs Coefs = {};
	QuadraticSolution Solution = {};

	Coefs.a = command_argc.coefs.a;
	Coefs.b = command_argc.coefs.b;
	Coefs.c = command_argc.coefs.c;

	printf("\nYou've entered:\n");
	printf("a = %.2lf, b = %.2lf, c = %.2lf\n\n", Coefs.a, Coefs.b, Coefs.c);

	square_solve(&Coefs, &Solution);

	print_solution(Solution);

	printf("The program is finished.\n\n");
}


