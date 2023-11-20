#include <iostream>

using namespace std;
void funkcja(int &a, int &b);
int main()
{
    int a = 10;
    int b = 5;
    funkcja(a, b);
    cout << a << " " << b;
    return 1;
}
void funkcja(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
// Przyklad na ekranie:
// Dla wartosci: 10,l5
// 15 10
// Dla wartosci: 1 2
// 2 1