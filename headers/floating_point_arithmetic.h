//! @file

#pragma once
#include <stdbool.h>

static const double EPSILON = 1e-12; //!> A constant to compare with 0

/**
 * @brief Check whether the num is approximately 0
 * 
 * 
 * @param num double number to check
 * @return true if num near to 0, else -> false
 */
bool is_zero(double num);


/**
 * @brief Check whether the num is positive
 * 
 * 
 * @param num double number to check
 * @return true if num is positive, else -> false
 */
bool is_positive(double num);


/**
 * @brief Clamp number to 0 if it near to 0
 * 
 * @param num double number to clamp
 */
void clamp_to_zero(double * number);


/**
 * @brief Checking for equality of double two numbers
 * 
 * 
 * @param number1 double number to compare
 * @param number2 double number to compare
 * @return true if nums are equal, else -> false
 */
bool double_comparison(double number1, double number2);


/**
 * @brief Converting string to double number
 * 
 * 
 * @param str string to convert
 * @param double_number the variable where the resulting value is written to
 * @return true if a string was passed with double number and convertion was successfull, else -> false
 */
bool convert_to_float(const char *str, double * double_number);