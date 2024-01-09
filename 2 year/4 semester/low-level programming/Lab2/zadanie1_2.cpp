#include <iostream>
#include <windows.h>
using namespace std;

extern "C" INT64 zad1(INT64);
extern "C" INT64 zad2(INT64, INT64, INT64, INT64);
//extern "C" INT64 zad3(INT64, INT64);

int main()
{
	INT64 a = 2;
	INT64 b = 2;
	INT64 c = 2;
	INT64 x = 2;
	INT64 w;

	w = zad1(a);
	cout << "Wynik: " << w << endl;

	w = zad2(a, b,c,x);
	cout << "Wynik: " << w << endl;

	/*w = zad3(a, b);
	cout << "Wynik: " << w << endl;*/

	system("PAUSE");
	return 0;
}
