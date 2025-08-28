//! @file

#pragma once
#include "structures.h"
#include <stdlib.h>


/**
 * @brief Defines a macros for assertion errors
 * 
 * This macros point file and line where assertion error has occurred
 * @param condition checked condition  
 */
#define MY_ASSERT(condition) \
    do { \
        if (!(condition)) \
        { \
            fprintf(stderr, "Assertion error!!!!:\n" \
                            "statement: %s is false\n" \
                            "in file %s, line %d\n", \
                   #condition, __FILE__, __LINE__); \
            abort(); \
        } \
    } while (0)



/**
 * @brief Defines a structure to for checking answers in unit test
 */
typedef struct {
    int type;
    union {
		double x0;
		double real_roots[2];
		ComplexNumber complex_roots[2];
	};
} Check_answers;


/**
 * @brief Defines a structure to storing value for unit tests
 */
typedef struct {
    SquareEquationCoefs test_coefs;
    Check_answers check_solution;
} Test;



/**
 * @brief Unit test function
 * 
 * This function use testdata for testing correct solving equation 
 * 
 * @param data_for_test list for unit test data, this list should be initialized before using function 
 * @param number_of_tests quantity of tests
 * @return amount of successful executed flags
 */
int test_solve_square(Test data_for_tests[], size_t number_of_tests);

