#include <iostream>

using namespace std;
void funkcja(const int rok);
int main()
{
    funkcja(1000);
    return 1;
}
void funkcja(const int rok)
{
    if (rok % 4 == 0 && (rok % 100 != 0 || rok % 400 == 0))
    {
        cout << "Rok jest przestepny.";
    }
    else
    {
        cout << "Rok nie przestepny.";
    }
}
// Przyklad na ekranie:
// Dla wartosci: 1000
// Rok nie przestepny.
// Dla wartosci: 2000
// Rok jest przestepny.
