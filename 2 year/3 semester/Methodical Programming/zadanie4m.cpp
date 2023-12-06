#include <iostream>

using namespace std;

int main()
{
	adres* wsk = new adres("Czestochowa", "42-200", "Dabrowskiego", 73);
	cout << *wsk << '\n';
	adres a1(*wsk);
	delete wsk;

	const adres* wsk1 = new adres("Warszawa", "00-950", "Mysliwiecka", 357);
	cout << a1 << '\n';
	cout << *wsk1 << '\n';

	adres a2;
	cout << a2 << '\n';
	a2 = a1;
	cout << a2 << '\n';

	osoba o("Jan", "Kos", 25, *wsk1);
	cout << o << '\n';
	osoba o1(o);
	cout << o1 << '\n';

	osoba o2;
	cout << o2 << '\n';
	o2 = o1;
	cout << o2 << '\n';
	delete wsk1;
	
	return 0;
}
