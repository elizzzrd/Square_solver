#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "structures.h"
#include "tests.h"
#include "read_file.h"



bool read_file(Test data_for_tests[])
{
    FILE *data;
    //int ch;
    if ((data = fopen("tests/data.txt", "r")) == NULL)
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
                                    &data_for_tests[count].type,
                                    &data_for_tests[count].test_coefs.a,
                                    &data_for_tests[count].test_coefs.b,
                                    &data_for_tests[count].test_coefs.c)) != 4)
        {
            assert(false && "Reading file error");
            return false;
        }

        symbols_read = 0;
        //printf("Checking input data!!!! (%d)\n", count);
        if (data_for_tests[count].type == 0 || data_for_tests[count].type == 1)
        {
            ;
        }
        else if (data_for_tests[count].type == 2)
        {
            fscanf(data, "%lf",&data_for_tests[count].x0);
        }
        else if (data_for_tests[count].type == 3)
        {
            fscanf(data, "%lf %lf", &data_for_tests[count].real_roots[0],
                                    &data_for_tests[count].real_roots[1]);
        }
        else if (data_for_tests[count].type == 4)
        {
            fscanf(data, "%lf %lf %lf %lf", 
                                    &data_for_tests[count].complex_roots[0].real,
                                    &data_for_tests[count].complex_roots[0].imag,
                                    &data_for_tests[count].complex_roots[1].real,
                                    &data_for_tests[count].complex_roots[1].imag);                          
        }
        count++;
    }
    fclose(data);
    return true;        
}



