//! @file

#pragma once


/**
 * @brief Defines a structure to represent a square equation coeficients
 */
typedef struct { 
	double a;
	double b;
	double c;
} SquareEquationCoefs;


/**
 * @brief Enum to represent a differents types of solution
 */
enum SolutionType {
	NO_SOLUTION,       // = 0,
	ALL_REAL_NUMBERS,  // = 1,
	ONE_REAL_ROOT,     // = 2,
	TWO_REAL_ROOTS,    // = 3,
	TWO_COMPLEX_ROOTS, // = 4,
};

/**
 * @brief Defines a structure to represent a complex number
 */
typedef struct {
	double real;
	double imag;
} ComplexNumber;


/**
 * @brief Defines a structure to represent a solution for equation
 */
typedef struct { 
	enum SolutionType type; //!< type of solution
	union { //!< union for different types of solution
		double x0; 
		double real_roots[2]; 
		ComplexNumber complex_roots[2];
	}; 
} QuadraticSolution;


