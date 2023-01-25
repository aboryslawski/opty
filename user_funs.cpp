#include"user_funs.h"



matrix ff(matrix x, matrix ud1, matrix ud2)
{
    matrix y;
    //y = -cos(0.1 * x()) * exp(-(pow((0.1 * x()) - (2 * _Pi)), 2)) + (0.002 * pow(0.1 * x(), 2));
    y = (-cos(0.1 * x()) * pow(2.72, -(pow(0.1 * x() - (2 * M_PI), 2)))) + (0.002 * pow((0.1 * x()), 2));
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

    y = ( - cos(0.1 * x) * pow(2.72, -(pow(0.1 * x - (2 * M_PI), 2)))) + (0.002 * pow((0.1 * x), 2));

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

matrix ff2(matrix x1, matrix ud1, matrix ud2) {
    matrix y;
    y = pow(x1(0), 2) + pow(x1(1), 2) - cos(2.5 * M_PI * x1(0)) - cos(2.5 * M_PI * x1(1)) + 2;
    return y;
}

matrix df2(double t, matrix y, matrix ud1, matrix ud2)
{
    double mr = 1, mc = 9, l = 0.5, b = 0.5;
    double I = mr * l * l / 3.0 + mc * l * l;
    matrix dY(2, 1);
    dY(0) = y(1);
    dY(1) = (ud2(0) * (ud1(0) - y(0)) + ud2(1) * (ud1(1) - y(1)) - b * y(1)) / I;

//    cout << "t, alpha, omega: ";
//    cout << t << "; " << y(0) << "; " << y(1) << endl;

    return dY;
}

matrix fT2(matrix x, matrix ud1, matrix ud2)
{
    matrix y;
    matrix y0(2, 1), y_ref(2, new double[2]{ 3.14,0 });
    matrix* Y = solve_ode(df2, 0, 0.1, 100, y0, y_ref, x);
    y = 0;
    int n = get_len(Y[0]);
    for (int i = 0; i < n; i++) {
        y = y + 10 * pow(y_ref(0) - Y[1](i, 0), 2)
            + pow(y_ref(1) - Y[1](i, 1), 2)
            + pow(x(0) * (y_ref(0) - Y[1](i, 0)) + x(1) * (y_ref(1) - Y[1](i, 1)), 2);
    }
    y = y * 0.1;
    return y;
}

//lab 4 - funkcja testowa

matrix ff4T(matrix x, matrix ud1, matrix ud2) {
    matrix y;
    y = pow(x(0) + 2 * x(1) - 7,2) + pow(2 * x(0) + x(1) - 5, 2);
    return y;
}

matrix gf4T(matrix x, matrix ud1, matrix ud2) {
    matrix g(2, 1);
    g(0) = 10 * x(0) + 8 * x(1) - 34;
    g(1) = 8 * x(0) + 10 * x(1) - 38;
    return g;
}

matrix Hf4T(matrix x, matrix ud1, matrix ud2) {
    matrix H(2, 2);
    H(0, 0) = H(1, 1) = 10;
    H(0, 1) = H(1, 0) = 8;
    return H;
}

// lab 4 - funkcja celu
matrix ff4R(matrix x, matrix ud1, matrix ud2) {
    matrix y;
    int m = 100;
    int n = get_len(x);
    static matrix X(n, m), Y(1, m);
    static bool read = true;
    if (read) {
        ifstream S("XData.txt");
        S >> X;
        S.close();
        S.open(("Ydata.txt"));
        S >> Y;
        S.close();
        read = false;
    }
    double h;
    y = 0;
    for (int i = 0; i < m; ++i) {
        h = m2d(trans(x) * X[i]); //θ (theta)
        cout << "θ = " << h << endl;
        h = 1.0 / (1.0 + exp(-h));
        y = y - Y(0, i) * log(h) - (1 - Y(0, i)) * log(1 - h); //J(θ)
    }
    y = y / m;
    return y;
}

matrix gf4r(matrix x, matrix ud1, matrix ud2) {
    int m = 100;
    int n = get_len(x);
    matrix g(n, 1);
    static matrix X(n, m), Y(1, m);
    static bool read = true;
    if (read) {
        ifstream S("XData.txt");
        S >> X;
        S.close();
        S.open(("Ydata.txt"));
        S >> Y;
        S.close();
        read = false;
    }
    double h;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            h = m2d(trans(x) * X[i]);
            h = 1 / (1 + exp(-h));
            g(j) = g(j) + X(j, i) * (h - Y(0, i)); //pochodne cząstkowe J(θ)
        }
        g(j) = g(j) / m;
    }
    return g;
}