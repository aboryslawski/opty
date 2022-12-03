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
	catch (string EX_INFO)
	{
		cerr << "ERROR:\n";
		cerr << EX_INFO << endl << endl;
	}
	system("pause");
	return 0;
}

void lab1()
{

}

void lab2()
{

}

void lab3()
{

}

void lab4()
{

}

void lab5()
{

}
