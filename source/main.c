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
	int returned_value = parse_flags(argc, argv);

	if (returned_value == -1)
	{
		printf("\n\nIncorrect flag input. Please try again or type help.\n");
	}
	else
	{
		printf("\n%d flags has been executed\n", (returned_value == 0) ? 1: returned_value);
	}


	printf("Program is finished.\n\n");
	
    return 0;
}
