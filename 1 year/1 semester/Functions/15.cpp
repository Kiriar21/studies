#include <iostream>
using namespace std;
int zad4(const int *T, const unsigned int N);
int main()
{
    int T[10] = {-2, -5, 12, 15, 7, -9};
    cout << "Suma el blab la:" << zad4(T, 10);
    return 1;
}
int zad4(const int *T, const unsigned int N)
{
    int suma = 0;
    for (unsigned int i = 0; i < N; i++)
    {
        if (T[i] % 2 != 0 && T[i] % 3 == 0)
            suma += T[i];
    }
    return suma;
}
