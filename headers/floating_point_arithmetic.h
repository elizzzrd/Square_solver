#pragma once
#include <stdbool.h>

static const double EPSILON = 1e-12;


bool is_zero(double num);
bool is_positive(double num);
void clamp_to_zero(double * number);
bool double_comparison(double number1, double number2);
bool convert_to_float(const char *str, double * double_number);