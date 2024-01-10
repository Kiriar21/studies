#include <iostream>
#include <windows.h>
using namespace std;
extern "C" INT64 zad1(INT64, INT64);
extern "C" INT64 zad2(INT64, INT64);
extern "C" INT64 zad3(INT64, INT64);
extern "C" INT64 zad4(INT64, INT64);
extern "C" INT64 zad5(INT64, INT64);
extern "C" INT64 zad6(INT64, INT64);
extern "C" INT64 zad7(INT64);
extern "C" INT64 zad8(INT64);
extern "C" INT64 zad9(INT64, INT64, INT64);
extern "C" INT64 zad10(INT64);


int main()
{
	//zadanie 1
	int x = 0,a=3,b=4;
	if (a < b) x = b - a;
	cout << "Z c++ x wynosi: "<< x << endl;
	x = zad1(a, b);	
	cout << "Z assembly x wynosi: "<< x << endl;
	//zadanie 2
	x = 0;
	if (a < b) x = b - a;
	else x = a - b;
	cout << "Z c++ x wynosi: " << x << endl;
	x = zad2(a, b);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie 3
	x = 0;
	if (a < b) x = (b * b) - a;
	cout << "Z c++ x wynosi: " << x << endl;
	x = zad3(a, b);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie 4
	x = 0;
	if (a < b) x = (a*a)+b;
	else x = (a * a) - b;
	cout << "Z c++ x wynosi: " << x << endl;
	x = zad4(a, b);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie 5
	int op = 7;
	x = 10;
	switch (op)
	{
	case 3: x += 7;
		break;
	case 5: x = x * (x - 7);
		break;
	case 7: x *= x;
		break;
	default: x = 0;
		break;
	}
	cout << "Z c++ x wynosi: " << x << endl;
	x = 10;
	x = zad5(x,op);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie 6
	op = 2, x = 5;
	switch (op)
	{
	case 0: x += 7;
		break;
	case 1: x = x * (x + 3);
		break;
	case 2: x = x * x + 2 * x;
		break;
	case 3: x = x * x - 12;
		break;
	default: x = 0;
		break;
	}
	cout << "Z c++ x wynosi: " << x << endl;
	x = 5;
	x = zad6(x, op);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie7
	x = 0;
	op = 10;
	for (int i = 0; i < op; i++) x += 2 * i;
	cout << "Z c++ x wynosi: " << x << endl;
	x = zad7(op);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie8
	x = 1;
	for (int i = 1; i <= op; i++) {
		x *= i;
	}
	cout << "Z c++ x wynosi: " << x << endl;
	x = zad8(op);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie9
	x = 0, a = 5;
	int r = 6, max = 30;
	int wynik = a;
	int w = a + r;
	while (w < max) {
		wynik += w;
		w += r;
	}
	cout << "Z c++ x wynosi: " << wynik << endl;
	
	x = zad9(a,r,max);
	cout << "Z assembly x wynosi: " << x << endl;
	//zadanie 10
	op = 5;
	x = 1;
	int i = 1;
	while (i <= op) {
		x *= i;
		i++;
	}
	cout << "Z c++ x wynosi: " << x << endl;
	x = zad10(op);
	cout << "Z assembly x wynosi: " << x << endl;
}
