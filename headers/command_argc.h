#pragma once
#include "structures.h"
#define NFLAGS 5


typedef struct {
	const char * short_name;
	const char * long_name;
	int flag_argc;
    int (*program_t)(char * argv[], int current_index_argv, int argc);
} Flag_t;


int parse_flags(int argc, char *argv[]);
int flag_names_comparison(char *possible_flag, Flag_t list_of_flags[]);
int print_help(char * argv[], int current_index_argv, int argc);
int lets_solve_square_equation(char * argv[], int current_index_argv, int argc);
int run_tests(char * argv[], int current_index_argv, int argc);
int use_testdata_from_file(char * argv[], int current_index_argv, int argc);
void run_tests_command_line(Test data_for_tests[], const char * filename);
int instant_coefs_input(char * argv[], int current_index_argv, int argc);

