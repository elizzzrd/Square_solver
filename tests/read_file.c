#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "structures.h"
#include "tests.h"
#include "read_file.h"


bool read_file(Test data_for_tests[], const char * filename)
{
    FILE *data = NULL;
    if ((data = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can not open the file \"%s\"\n", filename);
        return false;
    }
    rewind(data);

    int count = 0;
    while (count < NMAX)
    {
        int symbols_read = 0;
        if ((symbols_read = fscanf(data, "%d %lf %lf %lf", 
                                    &data_for_tests[count].check_solution.type,
                                    &data_for_tests[count].test_coefs.a,
                                    &data_for_tests[count].test_coefs.b,
                                    &data_for_tests[count].test_coefs.c)) != 4)
        {
            assert(false && "Reading file error");
            return false;
        }
        symbols_read = 0;
        switch(data_for_tests[count].check_solution.type)
        {
            case NO_SOLUTION: break;
            case ALL_REAL_NUMBERS: break;
            case ONE_REAL_ROOT: 
            {
                if ((fscanf(data, "%lf", &data_for_tests[count].check_solution.x0)) != 1)
                {
                    assert(false && "Reading file error");
                    return false;
                }
                break;
            }
            case TWO_REAL_ROOTS:
            {
                if ((fscanf(data, "%lf %lf", &data_for_tests[count].check_solution.real_roots[0],
                                            &data_for_tests[count].check_solution.real_roots[1])) != 2)
                {
                    assert(false && "Reading file error");
                    return false;
                }
                break;
            }
            case TWO_COMPLEX_ROOTS:
            {
                if ((fscanf(data, "%lf %lf %lf %lf", 
                                    &data_for_tests[count].check_solution.complex_roots[0].real,
                                    &data_for_tests[count].check_solution.complex_roots[0].imag,
                                    &data_for_tests[count].check_solution.complex_roots[1].real,
                                    &data_for_tests[count].check_solution.complex_roots[1].imag)) !=4)
                {
                    assert(false && "Reading file error");
                    return false;
                }
                break;
            }
            default:
            {
                assert(false && "Unknown type of solutioin");
                break;
            }
        }
        count++;
    }
    fclose(data);
    return true;        
}

