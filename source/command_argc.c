#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>
#include "structures.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"
#include "read_file.h"
#include "tests.h"
#include "input_output.h"
#include "command_argc.h"




Flag_t list_of_flags[] = {
	{.short_name = "-h", .long_name = "--help", .flag_argc = 0, .program_t = print_help},
	{.short_name = "-s", .long_name = "--solve", .flag_argc = 0, .program_t = lets_solve_square_equation},
	{.short_name = "-t", .long_name = "--tests", .flag_argc = 0, .program_t = run_tests},
	{.short_name = "-f", .long_name = "--file", .flag_argc = 1, .program_t = use_testdata_from_file},
	{.short_name = "-c", .long_name = "--coefs", .flag_argc = 3, .program_t = instant_coefs_input}
};

size_t size_flag_list = sizeof(list_of_flags) / sizeof(list_of_flags[0]);


int parse_flags(int argc, char *argv[])
{
	assert(argc != 0 && "Argc cant be 0");
	assert(argv != NULL && "Argv cant be NULL");

	int executed_flags = 0;
	if (argc == 1)
	{
		return print_help(argv, 0, argc);
	}
	else
	{
		for (int current_index = 1; current_index < argc; current_index++)
		{	
			int type = flag_names_comparison(argv[current_index], list_of_flags);
			if (type == -1) 
			{
				return -1;
			}

			Flag_t flag = list_of_flags[type];
			int (*flag_todo)(char * argv[], int current_index_argv, int argc) = flag.program_t;
			int returned_value = (*flag_todo)(argv, current_index, argc);
			if (returned_value == -1)
			{
				return -1;
			}
			else 
			{
				current_index += returned_value;
				executed_flags++;
			}
		}
	}
	return executed_flags;
}


int flag_names_comparison(char *possible_flag, Flag_t flags[])
{
	assert(possible_flag != NULL && "Argv[current_index] cant be NULL");
	assert(flags != NULL && "list_of_flags cant be NULL");

	for (size_t i = 0; i < size_flag_list; i++)
	{
		if (strcmp(possible_flag, flags[i].short_name) == 0)
		{
			return (int)i;
		}
		else if (strcmp(possible_flag, flags[i].long_name) == 0)
		{
			return (int)i;
		}
	}
	return -1;
}



int print_help(char * argv[], int current_index_argv, int argc)
{
	int help_argc = 0;
	printf("\nHello(Meow), this is square solver program!!!\n");
	printf("\nPossible flags to use:\n\n"
			"\"-h\" or \"--help\" - provide information about usage of this program.\n\n"
			"\"-s\" or \"--solve\" - launch square equations solver.\n\n"
			"\"-t\" or \"--tests\" - launch tests for equation solver.\n\n"
			"\"-f\" or \"--file\" -  launch tests for equation solver from file you provide.\n"
			"syntax: [\"name of programm\"] [\"--file\"] [\"path to file\"]\n\n"
			"\"-c\" or \"--coefs\" - launch square equation solver with coefficients you enter.\n"
			"syntax: [\"name of programm\"] [\"--coefs\"] [\"a b c\"] for equation ax^2 + bx + c = 0\n"
			"\nYou can also enter several flags like this:\n"
			"syntax: [\"name of programm\"] [\"flag1 with its arguments\"] [\"flag2 with its arguments\"] and so on...\n\n");
	
	return help_argc;
}


int run_tests(char * argv[], int current_index_argv, int argc)
{
	int tests_argc = 0;
	Test data_for_tests[NMAX];
    run_tests_command_line(data_for_tests, "tests/data.txt");
	return tests_argc;
}

int use_testdata_from_file(char * argv[], int current_index_argv, int argc)
{
	int file_argc = 1;

	if ((current_index_argv + file_argc < argc))
	{
		Test data_for_tests[NMAX];
		run_tests_command_line(data_for_tests, argv[current_index_argv + 1]);
		return file_argc;
	}
	else
	{
		return -1;
	}	
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
}


int lets_solve_square_equation(char * argv[], int current_index_argv, int argc)
{
	int solve_argc = 0;
	SquareEquationCoefs Coefs = {};
	QuadraticSolution Solution = {};

	printf("Solving ax^2 + bx + c = 0\n\n");
	read_input(&Coefs);

	printf("\nYou've entered:\n");
	printf("a = %.2lf, b = %.2lf, c = %.2lf\n\n", Coefs.a, Coefs.b, Coefs.c);

	square_solve(&Coefs, &Solution);

	print_solution(Solution);

	return solve_argc;
	
}


int instant_coefs_input(char * argv[], int current_index_argv, int argc)
{
	int coefs_flags = 3;
	if ((current_index_argv + coefs_flags < argc + 1))
	{
		SquareEquationCoefs Coefs = {};
		QuadraticSolution Solution = {};

		if (convert_to_float(argv[current_index_argv + 1], &Coefs.a) && 
			convert_to_float(argv[current_index_argv + 2], &Coefs.b) &&
			convert_to_float(argv[current_index_argv + 3], &Coefs.c))
		{
			printf("\nYou've entered:\n");
			printf("a = %.2lf, b = %.2lf, c = %.2lf\n\n", Coefs.a, Coefs.b, Coefs.c);

			square_solve(&Coefs, &Solution);

			print_solution(Solution);
			return coefs_flags;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}


