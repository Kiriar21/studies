#include <iostream>
using namespace std;
float zad5(unsigned int *a, unsigned int &b, const int *T, const int n);
int main()
{
    unsigned int a = 0, b = 0;
    int T[10] = {-4, 1, 5, 2, -3, -1};
    float s = zad5(&a, b, T, 10);
    cout << "A: " << a << " B: " << b << " S: " << s;
    return 1;
}
float zad5(unsigned int *a, unsigned int &b, const int *T, const int n)
{
    float suma = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        if (T[i] % 2 == 0 || T[i] >= 0)
        {
            (*a)++;
            suma += T[i];
        }
        if (T[i] % 2 != 0 && T[i] >= 0)
            b += T[i];
    }
    return (suma / *a);
}
