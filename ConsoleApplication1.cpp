/*********************************************
Kod stanowi uzupe³nienie materia³ów do æwiczeñ
w ramach przedmiotu metody optymalizacji.
Kod udostêpniony na licencji CC BY-SA 3.0
Autor: dr in¿. £ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia Górniczo-Hutnicza
*********************************************/

#include"opt_alg.h"
#include "user_funs.h"


void lab1();
void lab2();
void lab3();
void lab4();
void lab5();

int main()
{

	try
	{
        lab2();
	}

	catch (string EX_INFO)
	{
		cerr << "ERROR:\n";
		cerr << EX_INFO << endl << endl;
	}
	return 0;

//    try
//    {
//        lab3();
//    }
//
//    catch (string EX_INFO)
//    {
//        cerr << "ERROR:\n";
//        cerr << EX_INFO << endl << endl;
//    }
//    return 0;
}

void lab1()
{
//auto y = expansion(ff, 100, 1, 1.1, 1000);
    //cout << y[0] << endl;
    //cout << y[1] << endl;
    //cout << endl << endl;

    //auto b = fib(fr, y[0], y[1], 0.00010);
    //cout << b.x << endl;
    //cout << b.y << endl;
    //cout << endl << endl;

    //solution opt = fib(fr, 1e-4, 1e-2, 1e-10);
    //cout << opt.x << endl;
    //cout << opt.y << endl;
    //cout << opt.f_calls << endl;
    //cout << opt.flag << endl;

    // --------------------------------------------------------

    cout << "punkt startowy;" << "p[0] z ekspansji;" << "p[1] z ekspansji;" << "f_calls dla ekspansji;" << "alpha;" << "wynik opt X z fiba;" << "wynik opt Y z fiba;" << "f_calls dla fiba" << endl;
    double alpha = 0.6;
    for (int i = 0; i < 3; i++) {
        alpha += 0.5;
        for (int j = 0; j < 100; j++) {
            double punkt_startowy = 200 * rand_mat(1, 1)() - 100;
            double* p = expansion(ff, punkt_startowy, 1, alpha, 1000);

            cout << punkt_startowy << ";" << p[0] << ";" << p[1] << ";" << solution::f_calls << ";" << alpha << ";";

            solution::clear_calls();
            solution opt = fib(ff, p[0], p[1], 1e-5);
            cout << m2d(opt.x) << ";" << m2d(opt.y) << ";" << solution::f_calls << endl;
            solution::clear_calls();
        }
    }
    string s;
    cin >> s;
}

void lab2()
{

    // funkcja testowa ramie robota
    double s = 0.1;
    double alphaH = 0.5;
    double elipson = 1e-3;
    int maxFCalls = 1000;
    solution wynik;
    matrix x0;

//    x0 = 2 * rand_mat(2, 1) - 1;
//    cout << x0 << endl << endl;
//    wynik = HJ(ff2, x0, s, alphaH, elipson, maxFCalls);
//    cout << wynik << endl << endl;
//    solution::clear_calls();
//
//    //Ramie robota
//    s = 2;
//    x0 = 10 * rand_mat(2, 1);
//    cout << x0 << endl << endl;
//    wynik = HJ(fT2, x0, s, alphaH, elipson, maxFCalls);
//    cout << wynik << endl << endl;
//    solution::clear_calls();


    // funkcja testowa po 100 opt dla 3 roznych kroków s (s+=0.4)

//    cout << "x1;x2;wynik\n";
//    for (int i = 0; i<3; i++) {
//        for (int j = 0; j < 100; j++) {
//            x0 =  2.0 * rand_mat(2, 1) - 1.0;
//            cout << x0;
//            wynik = HJ(ff2, x0, s, alphaH, elipson, maxFCalls);
//            cout << wynik << solution::f_calls << endl;
//            solution::clear_calls();
//        }
//        s += 0.4;
//    }


    // optymalizacja problemu rzeczywistego
    s = 2.6;
    x0 = 10.0 * rand_mat(2, 1);
    cout << "x0: " << x0 << endl;
    wynik = HJ(fT2, x0, s, alphaH, elipson, maxFCalls);
    cout << wynik << endl;
    solution::clear_calls();

//    double *k = ;
//    matrix x = matrix(2, new double[2]{ 2.75252, 2.99243 });
//    wynik = x;
//    wynik.fit_fun(fT2);


}

void lab3()
{
    double epsilon = 1e-3;
    int maxFCalls = 1000;
    solution wynik;
    matrix x0;
    double h0;

    //======testowa funkcja celu======
    //===długość kroku: 0.05 ===
    h0 = 0.05;
    //wyniki dla metody najszybszego spadku
    for (int i = 0; i < 100; i++) {
        x0 = 20 * rand_mat(2, 1) - 10;
        wynik = SD(ff4T, gf4T, x0, h0, epsilon, maxFCalls);
        cout << wynik << endl << endl;
        solution::clear_calls();
    }


    //wyniki dla metody gradientów sprzężonych
    for (int i = 0; i < 100; i++) {
        x0 = 20 * rand_mat(2, 1) - 10;
        wynik = CG(ff4T, gf4T, x0, h0, epsilon, maxFCalls);
        cout << wynik << endl << endl;
        solution::clear_calls();
    }

    //wyniki dla metody Newtona
    for (int i = 0; i < 100; i++) {
        x0 = 20 * rand_mat(2, 1) - 10;
        wynik = Newton(ff4T, gf4T, Hf4T, x0, h0, epsilon, maxFCalls);
        cout << wynik << endl << endl;
        solution::clear_calls();
    }

    //===długość kroku: 0.12 ===
    //wyniki dla metody najszybszego spadku
    for (int i = 0; i < 100; i++) {
        x0 = 20 * rand_mat(2, 1) - 10;
        wynik = SD(ff4T, gf4T, x0, h0, epsilon, maxFCalls);
        cout << wynik << endl << endl;
        solution::clear_calls();
    }


    //wyniki dla metody gradientów sprzężonych
    for (int i = 0; i < 100; i++) {
        x0 = 20 * rand_mat(2, 1) - 10;
        wynik = CG(ff4T, gf4T, x0, h0, epsilon, maxFCalls);
        cout << wynik << endl << endl;
        solution::clear_calls();
    }

    //wyniki dla metody Newtona
    for (int i = 0; i < 100; i++) {
        x0 = 20 * rand_mat(2, 1) - 10;
        wynik = Newton(ff4T, gf4T, Hf4T, x0, h0, epsilon, maxFCalls);
        cout << wynik << endl << endl;
        solution::clear_calls();
    }

}

void lab4()
{

}

void lab5()
{

}
