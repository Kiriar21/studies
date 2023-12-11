#include <iostream>

using namespace std;

int main()
{
	operacja o[] = {
		operacja("w lewo", 12), operacja("obrot", 8),
		operacja("w gore", 32), operacja("obrot", 10),
		operacja("w prawo", 5), operacja("w dol, 25),
		operacja("obrot", 32), operacja("w gore", 21),
		operacja("obrot", 11), operacja("w prawo", 6)
	};
	
	robot* linia[] = {
		new podajnik(0), new robot1R(1, o, o+3),
		new podajnik(2), new robot2R(3, o+2, o+5, o+3, o+6),
		new podajnik(4), new robot2R(5, o, o+4, o+2, o+6),
		new podajnik(6), new robot1R(7, o+7, o+10),
		new podajnik(8)
	};
	
	wykonaj(linia, linia+9);
	
	return 0;
}
