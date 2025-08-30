//! @file

#pragma once
#include "structures.h"


/**
 * @brief Read coeficients for equation
 * 
 * @param coef structure with coeficients for equation, this structure should be initialized before using function 
 */
void read_input(SquareEquationCoefs *coef); 


/**
 * @brief Read double number from stdin.
 * 
 * @return Read number
 */
double read_coef(void); 


/**
 * @brief Print solution of square equation
 * 
 * @param roots structure for solution of equation 
 */
void print_solution(QuadraticSolution roots); 

/**
 * @brief Function to clear the input from the remaining characters after the input operation
 */
void skip_line(void);

