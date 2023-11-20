#include <iostream>
#include <cmath>
using namespace std;
double funkcja(double *a, double *b);
int main()
{
    double a = 64, b = 36;
    cout << "Wartosc sumy pierwiastkow: " << funkcja(&a, &b);
    return 1;
}
double funkcja(double *a, double *b)
{
    return (sqrt(*a) + sqrt(*b));
}
// Przyklad na ekranie:
// Dla wartosci: 64 36
// 14
// Dla wartosci: 25 25
// 10
// Dla wartosci: 1 1
// 2