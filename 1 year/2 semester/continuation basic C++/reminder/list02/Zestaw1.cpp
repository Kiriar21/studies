#include <iostream>
using namespace std;
char *wstaw(const char *zrodlo, char symbol)
{
    int index = 0;
    while (zrodlo[index] != '\0')
    {
        index++;
    }
    char *tablicaZnakow = new char[index + 1];
    for (int i = 0; i < index; i++)
    {
        if ((i + 1) % 3 == 0)
            tablicaZnakow[i] = symbol;
        else
            tablicaZnakow[i] = zrodlo[i];
    }
    tablicaZnakow[index] = '\0';
    return tablicaZnakow;
}
void wstaw(char *cel, const char *zrodlo, char symbol)
{
    int index = 0;
    while (zrodlo[index] != '\0')
    {
        index++;
    }
    cel = new char[index + 1];
    for (int i = 0; i < index; i++)
    {
        if ((i + 1) % 3 == 0)
            cel[i] = symbol;
        else
            cel[i] = zrodlo[i];
    }
    cel[index] = '\0';
}
void wstaw1(char *&cel, const char *zrodlo, char symbol)
{
    int index = 0;
    while (zrodlo[index] != '\0')
    {
        index++;
    }
    cout << "index: " << index << endl;
    cel = new char[index + 1];
    for (int i = 0; i < index; i++)
    {
        if ((i + 1) % 3 == 0)
            cel[i] = symbol;
        else
            cel[i] = zrodlo[i];
    }
    cel[index] = '\0';
}
int szukaj(const char *zrodlo, const char symbol)
{
    int index = 0, counter = 0;
    while (zrodlo[index] != '\0')
    {
        if (zrodlo[index] == symbol)
            counter++;
        index++;
    }
    return counter;
}
char *kopiuj(const char *zrodlo)
{
    int index = 0;
    while (zrodlo[index] != '\0')
    {
        index++;
    }
    char *tab = new char[index + 1];
    for (int i = 0; i < index; i++)
    {
        zrodlo[i] >= 'a' && zrodlo[i] <= 'z' ? tab[i] = 'A' + zrodlo[i] - 'a'
                                             : tab[i] = zrodlo[i];
    }
    tab[index] = '\0';
    return tab;
}
void usun(char *str)
{
    if (str)
    {
        delete[] str;
        str = nullptr;
    }
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cerr << "Blad. Podaj nazwaProgramu ciagZnakow symbol\n";
        return -1;
    }
    char *a = wstaw(argv[1], argv[2][0]);
    char *b, *c;
    b = nullptr;
    c = nullptr;
    //...
    wstaw(b, argv[1], argv[2][0]);
    wstaw1(c, argv[1], argv[2][0]);
    //...
    cout << "A: " << a << endl;
    cout << "C: " << c << endl;
    cout << szukaj(a, 's') << endl;
    //...
    usun(a);
    a = kopiuj(argv[1]);
    cout << a << endl;
    //..
    usun(a);
    usun(b);
    usun(c);

    return 0;
}