//! @file

#pragma once

/**
 * @brief Solve linear equation
 * 
 * This function solve linear equation with coefficients in passed coef structure and write solution in roots structure
 * 
 * @param coef structure with coeficients for equation, this structure should be initialized before using function
 * @param roots structure for solution of equation, this structure should be initialized before using function
 */
void linear_equation_solve(SquareEquationCoefs *coef, QuadraticSolution *roots);

/**
 * @brief Solve square equation
 * 
 * This function solve square equation with coefficients in passed coef structure and write solution in roots structure
 * 
 * @param coef structure with coeficients for equation, this structure should be initialized before using function
 * @param roots structure for solution of equation, this structure should be initialized before using function
 */
void square_equation_solve(SquareEquationCoefs *coef, QuadraticSolution *roots);

/**
 * @brief Launch solving equation 
 * 
 * 
 * @param coef structure with coeficients for equation, this structure should be initialized before using function
 * @param roots structure for solution of equation, this structure should be initialized before using function
 */
void square_solve(SquareEquationCoefs * Coef, QuadraticSolution * Solution);