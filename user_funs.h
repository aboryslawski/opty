#pragma once

#include"ode_solver.h"


matrix ff(matrix x, matrix ud1, matrix ud2);

double fibonacci(int n);

double gg(double x);

double fib_value(double k);

matrix fr(matrix x, matrix ud1, matrix ud2);
matrix df(double t, matrix Y, matrix ud1, matrix ud2);

// lab2 testowa funkcja celu
matrix ff2(matrix x1, matrix ud1, matrix ud2);

// lab2 problem rzeczywisty
matrix df2(double t, matrix y, matrix ud1, matrix ud2);
matrix fT2(matrix x, matrix ud1, matrix ud2);

//lab 4 testowa funkcja celu
matrix ff4T(matrix x, matrix ud1, matrix ud2);
matrix gf4T(matrix x, matrix ud1, matrix ud2);
matrix Hf4T(matrix x, matrix ud1, matrix ud2);

//lab 4 problem rzeczywisty
matrix ff4R(matrix x, matrix ud1, matrix ud2);
matrix gf4r(matrix x, matrix ud1, matrix ud2);