//! @file
#pragma once

#include "structures.h"
#include "tests.h"
#define NFLAGS 5 //!> Quantity of cmd flags


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"


/**
 * @brief Defines a structure to represent a cmd flag
 */
typedef struct 
{
	const char * short_name; //!< flag short name 
	const char * long_name; //!< flag long name
	int flag_argc; //!< quantity of flags arguments
    int (*program_t)(char * argv[], int current_index_argv, int argc); //!< pointer to function that flag launch
} Flag_t;


/**
 * @brief Define and launch flags that were entered in cmd
 * 
 * This function use arguments of command line and use them to run flags that user enter.
 * 
 * @param argc quantity of command line arguments
 * @param argv array of pointers to command line arguments
 * @return amount of successful executed flags
 */
int parse_flags(int argc, char *argv[]);


/**
 * @brief This function сhecks if the entered by user flag is in the list of structures.
 * 
 * 
 * @param possible_flag the entered flag in the command line
 * @param flags list of Flag_t type structures with all flags
 * @return index in flags if possible_flag is appropriate or -1 if flag hasnot been found
 */
int flag_names_comparison(const char *possible_flag, Flag_t list_of_flags[]);


/**
 * @brief Shows the help information about this program.
 */
int print_help(char * argv[], int current_index_argv, int argc);


/**
 * @brief Launch square solver.
 * 
 * This function ask to enter coeficients for equation ax^2 + bx + c = 0 and enter the solution.
 */
int lets_solve_square_equation(char * argv[], int current_index_argv, int argc);


/**
 * @brief Launch unit tests.
 * 
 */
int run_tests(char * argv[], int current_index_argv, int argc);


/**
 * @brief Launch unit tests with test data from file entered in cmd.
 * 
 * 
 * @param argv array of pointers to command line arguments
 * @param argc quantity of command line arguments
 * @param current_index_argv the current argv that is parsed by the parse_flags function
 */
int use_testdata_from_file(char * argv[], int current_index_argv, int argc);


/**
 * @brief Function for launching tests from cmd.
 * 
 * This function opens entered file, reads data from it and launch unit tests 
 * 
 * @param data_for_test list for unit test data, this list should be initialized before using function
 * @param filename name of file with test data
 */
void run_tests_command_line(Test data_for_tests[], const char * filename);


/**
 * @brief Solve square equation with coeficients entered in cmd
 * 
 * 
 * @param argv array of pointers to command line arguments
 * @param argc quantity of command line arguments
 * @param current_index_argv the current argv that is parsed by the parse_flags function
 */
int instant_coefs_input(char * argv[], int current_index_argv, int argc);

