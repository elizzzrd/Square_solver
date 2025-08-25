#pragma once
#include "structures.h"

typedef struct {
	const char * option;
	union {
        char * filename;
        SquareEquationCoefs coefs;
    };
} Flag;


typedef void (*program_v)(void);
typedef void (*program_a)(Flag command_argc);

char getchoice(const char *choice);
void print_help(void);
void run_tests(void);
void lets_solve_square_equation(void);
void instant_coefs_input(Flag command_argc);
void use_testdata_from_file(Flag command_argc);

