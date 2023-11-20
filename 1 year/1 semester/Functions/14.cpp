#include <iostream>

using namespace std;
unsigned int zad4(const int *T, const unsigned int N);
int main()
{
    int T[10] = {1, 2, 3, 4, 5};
    cout << "Suma tych elementow to: " << zad4(T, 10);
    return 1;
}
unsigned int zad4(const int *T, const unsigned int N)
{
    unsigned int suma_p = 0;
    unsigned int suma_np = 0;
    for (unsigned int i = 0; i < N; i++)
    {
        if (T[i] % 3 == 0)
            suma_p++;
        if (T[i] % 2 != 0)
            suma_np++;
    }
    return suma_p + suma_np;
}