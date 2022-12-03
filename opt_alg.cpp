#include"opt_alg.h"
double* expansion(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		//double* p = new double[2]{ 0,0 };
		////Tu wpisz kod funkcji
		//int i = 0;
		//solution X0 = solution(x0);
		//solution X1 = solution(x0 + d);
		//solution x_i_plus_one = solution();

		//if (m2d(X0.fit_fun(ff, ud1, ud2)) == m2d(X1.fit_fun(ff, ud1, ud2)))
		//{
		//	return new double[] { m2d(X0.x), m2d(X1.x) };
		//}
		//if (m2d(X0.fit_fun(ff, ud1, ud2)) > m2d(X1.fit_fun(ff, ud1, ud2)))
		//{
		//	d = -d;
		//	X1 = solution(x0 + d);
		//	if (m2d(X1.fit_fun(ff, ud1, ud2)) >= m2d(X0.fit_fun(ff, ud1, ud2)))
		//	{
		//		return new double[] {m2d(X1.x), m2d(solution(x0 - d).x)};
		//	}
		//}

		//do
		//{
		//	if (X1.f_calls > Nmax)
		//	{
		//		cout << endl;
		//		cout << "an exception was thrown" << endl;
		//		throw "fcalls greater than nmax (expansion function)";
		//	}
		//	i++;
		//	x_i_plus_one = solution(x0 + pow(alpha, i) * d);

		//} while (m2d(solution(i).fit_fun(ff, ud1, ud2)) <= m2d(x_i_plus_one.fit_fun(ff, ud1, ud2)));

		//solution x_minus_one = solution(i - 1);
		//if (d > 0)
		//{
		//	return new double[] {m2d(x_minus_one.fit_fun(ff, ud1, ud2)), m2d(x_i_plus_one.fit_fun(ff, ud1, ud2))};
		//}
		//return new double[] {m2d(x_i_plus_one.fit_fun(ff, ud1, ud2)), m2d(x_minus_one.fit_fun(ff, ud1, ud2))};

		//return p;

		int i = 0;
		auto x_0 = solution(x0);
		auto x_1 = solution(x0 + d);
		x_0.fit_fun(ff, ud1, ud2);
		x_1.fit_fun(ff, ud1, ud2);


		if(x_0.x == x_1.x)
		{
			return new double[2]{ m2d(x_0.x), m2d(x_1.x)};
		}

		if (m2d(x_1.fit_fun(ff, ud1, ud2)) > m2d(x_0.fit_fun(ff, ud1, ud2))) //nie trzeba tutaj fit_fun
		{
			d = -d;
			//x_1 = solution(x0 + d);
			x_1.x = x_0.x + d;
			if(m2d(x_1.fit_fun(ff, ud1, ud2)) >= m2d(x_0.fit_fun(ff, ud1, ud2))) // tu nie trzeba wolac fit_fun na iks_zero
			{
				return new double[] {m2d(x_1.x), m2d(x_0.x) - d};
			}
		}

		solution x_2;
		while(true)
		{
			if (x_0.f_calls > Nmax)
			{
				cout << "eeeeeeee" << endl;
				throw "ffffffffffff";
			}

			i = i + 1;
			x_2 = x0 + pow(alpha, i) * d;
			x_2.fit_fun(ff, ud1, ud2);
			if(x_2.y >= x_1.y)
			{
				break;
			}

			x_0 = x_1;
			x_1 = x_2;
		}

		if(d > 0)
		{
			return new double[] {m2d(x_0.x), m2d(x_2.x)};
		}

		return new double[] {m2d(x_2.x), m2d(x_0.x)};
		// iks i minus jeden to jest iks zero


	}
	catch (string ex_info)
	{
		throw ("double* expansion(...):\n" + ex_info);
	}
}


solution fib(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, matrix ud1, matrix ud2)
{
	try
	{

		int n = static_cast<int>(ceil(log2(sqrt(5) * (b - a) / epsilon) / log2((1 + sqrt(5)) / 2)));

		int* F = new int[n] {1, 1};
		for (int i = 2; i < n; ++i)
			F[i] = F[i - 2] + F[i - 1];
		solution A(a), B(b), C, D;
		C.x = B.x - 1.0 * F[n - 2] / F[n - 1] * (B.x - A.x);

		D.x = A.x + B.x - C.x;
		C.fit_fun(ff, ud1, ud2);
		D.fit_fun(ff, ud1, ud2);
		for (int i = 0; i <= n - 3; ++i)
		{
			if (C.y < D.y)
				B = D;
			else
				A = C;

			C.x = B.x - 1.0 * F[n - i - 2] / F[n - i - 1] * (B.x - A.x);
			D.x = A.x + B.x - C.x;
			C.fit_fun(ff, ud1, ud2);
			D.fit_fun(ff, ud1, ud2);
		}
		return C;
	}
	catch (string ex_info)
	{
		throw ("solution fib(...):\n" + ex_info);
	}
}

solution lag(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, double gamma, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution lag(...):\n" + ex_info);
	}
}

solution HJ(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution HJ(...):\n" + ex_info);
	}
}

solution HJ_trial(matrix(*ff)(matrix, matrix, matrix), solution XB, double s, matrix ud1, matrix ud2)
{
	try
	{
		//Tu wpisz kod funkcji

		return XB;
	}
	catch (string ex_info)
	{
		throw ("solution HJ_trial(...):\n" + ex_info);
	}
}

solution Rosen(matrix(*ff)(matrix, matrix, matrix), matrix x0, matrix s0, double alpha, double beta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Rosen(...):\n" + ex_info);
	}
}

solution pen(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution pen(...):\n" + ex_info);
	}
}

solution sym_NM(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution sym_NM(...):\n" + ex_info);
	}
}

solution SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution SD(...):\n" + ex_info);
	}
}

solution CG(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution CG(...):\n" + ex_info);
	}
}

solution Newton(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix),
	matrix(*Hf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Newton(...):\n" + ex_info);
	}
}

solution golden(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution golden(...):\n" + ex_info);
	}
}

solution EA(matrix(*ff)(matrix, matrix, matrix), int N, matrix limits, int mi, int lambda, matrix sigma0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		//Tu wpisz kod funkcji

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution EA(...):\n" + ex_info);
	}
}
