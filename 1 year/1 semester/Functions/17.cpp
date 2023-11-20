#include <iostream>
using namespace std;
void fun(unsigned long long a, const int N);
int main()
{
    const int N = 10;
    unsigned long long a;
    cout << "Podaj pierwsza liczbe: \n";
    cin >> a;
    fun(a, N);
    return 1;
}
void fun(unsigned long long a, const int N)
{
    for (unsigned int i = 0; i <= N; i++)
    {
        cout << i + 1 << ". Numer to: " << a << "\n";
        a *= a;
    }
}
