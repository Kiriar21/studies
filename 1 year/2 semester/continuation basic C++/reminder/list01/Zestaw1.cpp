#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
// Task 1 - declaration function displaing tables
void wypisz(const int *t, const unsigned int n);
// Task 2 - declaration function creating table with dynamic memory
int *utworz1(const unsigned int n);
void utworz2(int *&t, const unsigned int n);
// Task 2 - declaration function filling table without dynamic memory
void utworz3(int *t, const unsigned int n);
// Task 3 - declaration deleting function table with dynamic memory
void usun(int *t);
// Task 4 - declaration
void quest4(int *t, const unsigned int n);
// Task 5 - declaration
void quest5(int *t, const unsigned int n);
// Task 6 - declaration
void quest6(int *t, const unsigned int n);
// Task 7 - sum tables
int *suma1(const int *t1, const int *t2, const unsigned int n);
void suma2(const int *t1, const int *t2, int *&t3, const unsigned int n);
void suma3(const int *t1, const int *t2, int *t3, const unsigned int n);
// Task 8
int *quest8(int *t, const unsigned int n);
// Task 9
void quest9(int *t, const unsigned int n);
int main(int argc, char **argv)
{
    srand(time(NULL));
    int *t = utworz1(10);
    int *t1 = utworz1(10);
    int *t2 = utworz1(10);
    quest5(t, 10);
    quest5(t1, 10);
    quest5(t2, 10);
    int *suma = suma1(t1, t2, 10);
    wypisz(suma, 10);
    int *sumaa = nullptr;
    suma2(t, t2, sumaa, 10);
    wypisz(sumaa, 10);
    int *sumaaa = new int[10];
    suma3(t, t1, sumaaa, 10);
    wypisz(sumaaa, 10);
    quest9(t, 10);
    wypisz(t, 10);
    int *t3 = quest8(t, 10);
    wypisz(t3, 9);

    usun(t);
    usun(t1);
    usun(t2);
    usun(t3);
    usun(suma);
    usun(sumaa);
    usun(sumaaa);
    return 0;
}
// Task 1 - definition
void wypisz(const int *t, const unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        cout << t[i] << "\t";
    }
    cout << endl;
}
// Task 2 - definitions
int *utworz1(const unsigned int n)
{
    int *t = new int[n];
    for (unsigned int i = 0; i < n; i++)
    {
        t[i] = 0;
    }
    return t;
}
void utworz2(int *&t, const unsigned int n)
{
    t = new int[n];
    for (unsigned int i = 0; i < n; i++)
    {
        t[i] = 0;
    }
}
void utworz3(int *t, const unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        t[i] = 0;
    }
}
// Task 3 - definition
void usun(int *t)
{
    // if(t!=0) //if(t!=nullptr)
    if (t)
    {
        delete[] t;
        t = nullptr;
    }
}
// Task 4 - definition
void quest4(int *t, const unsigned int n)
{
    for (unsigned int i = 0; i < n / 2; i++)
        t[i] = 0;
    for (unsigned int i = n / 2; i < n; i++)
        t[i] = i + 1;
}
// Task 5 - definition
void quest5(int *t, const unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        t[i] = rand() % abs(100);
}
// Task 6 - definition
void quest6(int *t, const unsigned int n)
{
    int poczatek, koniec;
    cout << "Podaj poczatek zakresu losowania liczb:\n";
    cin >> poczatek;
    cout << "Podaj koniec zakresu losowania liczb:\n";
    do
    {
        cin >> koniec;
        if (koniec <= poczatek)
            cout << "Podano koniec zakresu mniejszy/rowny poczatek. Podaj wieksza "
                    "wartosc.\n";
    } while (koniec <= poczatek);
    for (unsigned int i = 0; i < n; i++)
        t[i] = poczatek + rand() % abs(koniec - poczatek);
}
// Task 7 - definitions
int *suma1(const int *t1, const int *t2, const unsigned int n)
{
    int *t = new int[n];
    for (unsigned int i = 0; i < n; i++)
        t[i] = t1[i] + t2[i];
    return t;
}
void suma2(const int *t1, const int *t2, int *&t3, const unsigned int n)
{
    t3 = new int[n];
    for (unsigned int i = 0; i < n; i++)
        t3[i] = t1[i] + t2[i];
}
void suma3(const int *t1, const int *t2, int *t3, const unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        t3[i] = t1[i] + t2[i];
}
// Task 8 - definition
int *quest8(int *t, const unsigned int n)
{
    int *t1 = new int[n - 1];
    unsigned int elem;
    cout << "Podaj ktory element chcesz usunac: \n";
    do
    {
        cin >> elem;
        if (elem < 1 || elem >= n)
            cout << "Bledny element.\n";
    } while (elem < 1 || elem >= n);
    for (unsigned int i = 0; i < n - 1; i++)
    {
        if (i < elem - 1)
        {
            t1[i] = t[i];
        }
        else if (i >= elem - 1)
        {
            t1[i] = t[i + 1];
        }
    }
    return t1;
}
// Task 9 - definition
void quest9(int *t, const unsigned int n)
{
    int elem = -1;
    cout
        << "Podaj jaki  element chcesz wstawic do tablicy na pierwsze miejsce?\n";
    cin >> elem;
    t[0] = elem;
    cout << "Dodawanie elementu zakonczone.\n";
}