#pragma once



typedef struct { 
	double a;
	double b;
	double c;
} SquareEquationCoefs;

enum SolutionType {
	NO_SOLUTION,       // = 0,
	ALL_REAL_NUMBERS,  // = -2,
	ONE_REAL_ROOT,     // = 1,
	TWO_REAL_ROOTS,    // = 2,
	TWO_COMPLEX_ROOTS, // = -1,

	// TODO: explicit numbering allows you to iterate through roots array with solution when you display it
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


