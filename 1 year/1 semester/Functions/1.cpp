#include <iostream>

using namespace std;
unsigned int funkcja(unsigned const int szerokosc, unsigned const int dlugosc);
int main()
{
    cout << "Powierzchnia budowlana wynosi: " << funkcja(10, 20) << " m2.\n";

    return 1;
}

unsigned int funkcja(unsigned const int szerokosc, unsigned const int dlugosc)
{
    return szerokosc * dlugosc;
}

// Przyklad na ekranie:
// Dla wartosci: 10,20
// Powierzchnia budowlana wynosi: 200 m2.
// Dla wartosci: 5,10
// Powierzchnia budowlana wynosi: 50 m2.