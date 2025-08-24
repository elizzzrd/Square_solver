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


int main(int argc, char *argv[])
{
	char *option = argv[1];
	program_t program_todo = NULL;
	char choice = getchoice(option);

	switch(choice)
	{
		case 'h': program_todo = print_help; break;
		case 't': program_todo = run_tests; break;
		case 's': program_todo = lets_solve_square_equation; break;
		case 'n': printf("Programm is finished.\n"); return 0;
		default: assert(false && "unknown option"); break;
	}

	(*program_todo)();

    return 0;
}
