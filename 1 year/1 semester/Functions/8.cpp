#include <iostream>

using namespace std;
void funkcja(int &a, int &b);
int main()
{
    int a = 5;
    int b = 10;
    funkcja(a, b);
    cout << a << " " << b;
    return 1;
}
void funkcja(int &a, int &b)
{
    int c = a;
    if (a < b)
    {
        a = b;
        b = c;
    }
}
// Przyklad na ekranie:
// Dla wartosci: 10,l5
// 15 10
// Dla wartosci: 2,1
// 2 1