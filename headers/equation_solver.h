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

/**
 * @brief Solve equation if D > 0
 * 
 * 
 * @param a coeficient a
 * @param b coeficient b
 * @param c coeficient c
 * @param D discriminant
 * @param roots structure for solution of equation, this structure should be initialized before using function
 */
void D_positive_solve(double a, double b, double c, double D, QuadraticSolution *roots);

/**
 * @brief Solve equation if D == 0
 * 
 * 
 * @param a coeficient a
 * @param b coeficient b
 * @param c coeficient c
 * @param D discriminant
 * @param roots structure for solution of equation, this structure should be initialized before using function
 */
void D_zero_solve(double a, double b, double c, double D, QuadraticSolution *roots);

/**
 * @brief Solve equation if D < 0
 * 
 * 
 * @param a coeficient a
 * @param b coeficient b
 * @param c coeficient c
 * @param D discriminant
 * @param roots structure for solution of equation, this structure should be initialized before using function
 */
void D_negative_solve(double a, double b, double c, double D, QuadraticSolution *roots);