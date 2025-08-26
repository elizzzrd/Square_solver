#pragma once



typedef struct { 
	double a;
	double b;
	double c;
} SquareEquationCoefs;

enum SolutionType {
	NO_SOLUTION,       // = 0,
	ALL_REAL_NUMBERS,  // = 1,
	ONE_REAL_ROOT,     // = 2,
	TWO_REAL_ROOTS,    // = 3,
	TWO_COMPLEX_ROOTS, // = 4,
};


typedef struct {
	double real;
	double imag;
} ComplexNumber;


typedef struct { 
	enum SolutionType type;
	union {
		double x0;
		double real_roots[2]; 
		ComplexNumber complex_roots[2];
	};
} QuadraticSolution;


