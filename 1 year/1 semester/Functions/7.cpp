#include <iostream>

using namespace std;
void funkcja(int *a, int *b);
int main()
{
    int a = 1;
    int b = 2;
    funkcja(&a, &b);
    cout << a << " " << b;
    return 1;
}
void funkcja(int *a, int *b)
{

    int c = *a;
    if (*a > *b)
    {
        *a = *b;
        *b = c;
    }
}
// Przyklad na ekranie:
// Dla wartosci: 10,l5
// 10 15
// Dla wartosci: 2,1
// 1 2