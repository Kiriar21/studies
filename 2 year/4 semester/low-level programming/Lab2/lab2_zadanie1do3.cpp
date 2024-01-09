#include <iostream>
#include <windows.h>
using namespace std;

extern "C" INT64 objetosc(INT64);
extern "C" INT64 funkcjaKwadratowa(INT64, INT64, INT64, INT64);

int main()
{
    INT64 a = 2;
    INT64 objetosc_wynik = objetosc(a);
    cout << "Wynik objetosci dla wartosci a=" << a 
        << " wynosi=" << objetosc_wynik << endl;
    INT64 aa = 5, bb = 10, cc = 4, xx=2;
    INT64 funkcjaKwadratowa_wynik = funkcjaKwadratowa(aa, bb, cc,xx);
    cout << "Wynik funkcji kwadratowej wynosi=" << funkcjaKwadratowa_wynik<< endl;
    cout << "x wynosi " << xx << endl;
}
