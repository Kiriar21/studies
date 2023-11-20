#include <iostream>
using namespace std;
int *Add(const int &, const int &, const int &, bool);

int *(*fun)create_add(int *Add(const int &, const int &, const int &, bool), const int &, bool)(const int &);
int *(*(create_add(int *(*Add)(const int &, const int &, const int &, bool), const int &, bool)))(const int &num);

bool filtruj_liczbe(const int &);

int *(Uzyj_filtru(bool (*)(const int &), int *([]), int *, int *));

int main()
{
	int n = 5;
	int *wsk = &n;
	cout << "adress: " << wsk << "\n"
		 << "Value before the change " << *wsk;
	*wsk = 10;
	cout << endl
		 << "Value after change " << *wsk;
	cout << endl
		 << "Wartosc zmiennej n: " << n;
	cout << endl
		 << "Addresse pointer is: " << &wsk;
	cout << endl
		 << "pointer:" << wsk;
	int s = 5;
	const int &d = s;
	cout << "&d: " << &d << "d:" << d << endl;
}

void show(int *tab, int n) // pointer
void show(int tab[])       // reference
