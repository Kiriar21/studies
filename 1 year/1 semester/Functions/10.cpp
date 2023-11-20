#include <iostream>

using namespace std;
void funkcja(const int liczba, int *t);
int main()
{
    int liczba = 0, t[10];
    cout << "Podaj liczbe. (max10)\n";
    cin >> liczba;
    funkcja(liczba, t);
    return 1;
}
void funkcja(const int liczba, int *t)
{
    int wynik = 1;
    for (int i = 1; i <= 10; i++)
    {
        t[i - 1] = i * liczba;
        cout << t[i - 1] << endl;
    }
}
// Przyklad na ekranie:
// Dla wartosci: 4
// 4 8 12 16 20 24 28 32 36 40
// Dla wartosci: 3
// 3 6 9 12 15 18 21 24 27 30
