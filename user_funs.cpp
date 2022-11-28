#include"user_funs.h"



matrix ff(matrix x, matrix ud1, matrix ud2)
{
    matrix y;
    //y = -cos(0.1 * x()) * exp(-(pow((0.1 * x()) - (2 * _Pi)), 2)) + (0.002 * pow(0.1 * x(), 2));
    y = (-cos(0.1 * x()) * pow(2.72, -(pow(0.1 * x() - (2 * _Pi), 2)))) + (0.002 * pow((0.1 * x()), 2));
    return y;
}

double fibonacci(const int n)
{
    if(n < 0)
    {
        cout << "EEEEEEEEEEEEEEEEEEEEEEEE" << endl;
        throw "GGGGGGGGGG";
    }
	if(n == 0)
	{
        return 0;
	}
    if(n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);

    //return (1 / sqrt(5)) * (pow(1 + sqrt(5), n) - pow(((1 - sqrt(5) / 2)), n));
}

double gg(double x)
{
    double y;
    //y = -cos(0.1 * x()) * exp(-(pow((0.1 * x()) - (2 * 3.14)), 2)) + (0.002 * pow(0.1 * x(), 2));

    //exp(-(pow(0.1 * x - (2 * 3.14)), 2)))

    y = ( - cos(0.1 * x) * pow(2.72, -(pow(0.1 * x - (2 * _Pi), 2)))) + (0.002 * pow((0.1 * x), 2));

    printf("\n");
    printf("%f\n", y);

    //cout << endl;
    //cout << cos(1);
    //cout << endl;
    return y;
}



double fib_value(double k) {
    int t1 = 0;
    int t2 = 1;
    double out = 0;
    for (int i = 1; i < k; i++) {
        if (k == 1) {
            return t1;
        }
        if (k == 2) {
            return t2;
        }
        out = t1 + t2;
        t1 = t2;
        t2 = out;
    }
    return out;
}

matrix df(double t, matrix Y, matrix ud1, matrix ud2)
{
    double a = 0.98, b = 0.63, g = 9.81, PA = 0.75, TA = 90, PB = 1, DB = 0.00365665, Fin = 0.01, Tin = 10;
    matrix dY(3, 1);
    double FAout = a * b * m2d(ud2) * sqrt((2 * g * Y(0)) / PA);
    double FBout = a * b * DB * sqrt((2 * g * Y(1)) / PB);
    dY(0) = -FAout;
    dY(1) = FAout + Fin - FBout;
    dY(2) = Fin / Y(1) * (Tin - Y(2)) + FAout / Y(1) * (TA - Y(2));
    return dY;
}

matrix fr(matrix x, matrix ud1, matrix ud2)
{

    double y;
    matrix Y0 = matrix(3, new double[3]{ 5,1,10 });
    matrix* Y = solve_ode(df, 0, 1, 1000, Y0, ud1, x);
    int n = get_len(Y[0]);
    double max = Y[1](0, 2);
    for(int i = 0; i < n; i++)
    {
	    if(max < Y[1](i, 2))
	    {
            max = Y[1](i, 2);
	    }
    }
    y = abs(max - 50);
    return y;
}
