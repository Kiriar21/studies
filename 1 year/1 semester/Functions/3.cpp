#include <iostream>

using namespace std;
int zamien(int a, int b);
int main()
{
    int a = 10;
    int b = 5;
    int pom = a;
    a = zamien(a, b);
    b = zamien(b, pom);
    cout << a << " " << b;
    return 1;
}
int zamien(int a, int b)
{
    return a = b;
}
// Przyklad na ekranie:
// Dla wartosci: 10,l5
// 15 10
// Dla wartosci: 1 2
// 2 1