#include <iostream>

using namespace std;
void funkcja(unsigned const liczba);
int main()
{
    funkcja(11);
    return 1;
}
void funkcja(unsigned const liczba)
{
    unsigned pom = 11;
    while (liczba >= pom)
    {
        cout << pom << "\n";
        pom += 11;
    }
}
// Przyklad na ekranie:
// Dla wartosci: 33
// 11 22 33
// Dla wartosci: 34
// 11 22 33
// Dla wartosci: 7
// -