//! @file

#pragma once
#include "tests.h"
#include "stdbool.h"
#define NMAX 12 //!< Quantity of unit tests


/**
 * @brief Read passed file and write data to list for testdata
 * 
 * 
 * @param data_for_test list for unit test data, this list should be initialized before using function
 * @param filename name of file with test data
 * @return true if reading was successful, else -> false
 */
bool read_file(Test data_for_tests[], const char *filename);