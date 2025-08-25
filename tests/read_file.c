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
    FILE *data;
    //int ch;
    if ((data = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Can not open the file \"%s\"\n", "data.txt");
        exit(EXIT_FAILURE);
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
        //printf("Checking input data!!!! (%d)\n", count);
        if (data_for_tests[count].check_solution.type == 0 || data_for_tests[count].check_solution.type == 1)
        {
            ;
        }
        else if (data_for_tests[count].check_solution.type == 2)
        {
            fscanf(data, "%lf",&data_for_tests[count].check_solution.x0);
        }
        else if (data_for_tests[count].check_solution.type == 3)
        {
            fscanf(data, "%lf %lf", &data_for_tests[count].check_solution.real_roots[0],
                                    &data_for_tests[count].check_solution.real_roots[1]);
        }
        else if (data_for_tests[count].check_solution.type == 4)
        {
            fscanf(data, "%lf %lf %lf %lf", 
                                    &data_for_tests[count].check_solution.complex_roots[0].real,
                                    &data_for_tests[count].check_solution.complex_roots[0].imag,
                                    &data_for_tests[count].check_solution.complex_roots[1].real,
                                    &data_for_tests[count].check_solution.complex_roots[1].imag);                          
        }
        count++;
    }
    fclose(data);
    return true;        
}



