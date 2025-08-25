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

// TODO: complex number can be separated?
typedef struct {
	double real;
	double imag;
} ComplexNumber;


typedef struct { 
	enum SolutionType type;
	union {
		double x0;
		double real_roots[2]; // TODO: You can use real_roots for both linear and quadratic case, if one or more roots are absent, you can replace them with a NAN
		ComplexNumber complex_roots[2];
	};
} QuadraticSolution;


