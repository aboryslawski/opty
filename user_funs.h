#pragma once

#include"ode_solver.h"


matrix ff(matrix x, matrix ud1, matrix ud2);

double fibonacci(int n);

double gg(double x);

double fib_value(double k);

matrix fr(matrix x, matrix ud1, matrix ud2);
matrix df(double t, matrix Y, matrix ud1, matrix ud2);