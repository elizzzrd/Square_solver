#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "input_output.h"
#include "floating_point_arithmetic.h"
#include "equation_solver.h"
#include "read_file.h"
#include "tests.h"
#include "command_argc.h"
#include "structures.h"


int main(int argc, char *argv[])
{
	const char *option = argv[1];
	Flag command_argc = {};
	if (argc == 1)
	{
		command_argc.option = "not found";
	}
	else if (argc == 2)
	{
		command_argc.option = argv[1];
	}
	else if (argc == 3)
	{
		command_argc.option = option;
		command_argc.filename = argv[2];
	}
	else if (argc == 5)
	{
		command_argc.option = option;
		command_argc.coefs.a = atof(argv[2]);
		command_argc.coefs.a = atof(argv[3]);
		command_argc.coefs.a = atof(argv[4]);
	}
	else
	{
		printf("\nToo many arguments in command line. Please try again or type help.\n\n");
		return 0;
	}
	program_v program_todo_void = NULL;
	program_a program_todo_argc = NULL;
	char choice = getchoice(command_argc.option);
	
	switch(choice)
	{
		case 'h': program_todo_void = print_help; break;
		case 't': program_todo_void = run_tests; break;
		case 's': program_todo_void = lets_solve_square_equation; break;
		case 'f': program_todo_argc = use_testdata_from_file; break;
		case 'c': program_todo_argc = instant_coefs_input; break;
		case 'n': printf("Programm is finished.\n\n"); return 0;
		default: assert(false && "unknown option"); break;
	}
	if (program_todo_void == NULL)
	{
		(*program_todo_argc)(command_argc);
	}
	else
	{
		(*program_todo_void)();
	}

    return 0;
}
/*

struct coefFlag
struct testFlag


*/