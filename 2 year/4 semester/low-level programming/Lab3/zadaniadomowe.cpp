#include <iostream>
#include <windows.h>
using namespace std;
extern "C" INT64 zad1(INT64, INT64, INT64);
extern "C" INT64 zad2(INT64, INT64);
extern "C" INT64 zad3(INT64, INT64, INT64);
extern "C" INT64 zad4(INT64, INT64);
extern "C" INT64 zad5(INT64, INT64);
extern "C" INT64 zad6(INT64, INT64);
extern "C" INT64 zad7_1(INT64, INT64);
extern "C" INT64 zad7_2(INT64, INT64);
extern "C" INT64 zad8(INT64, INT64);
int main()
{
    //zadanie1
    int a=51, b=10, w=1;
    if (a >= b) w += 10;
    cout << "Zad1. wynik c++ -> " << w << endl;
    w = 1;
    w = zad1(a, b, w);
    cout << "Zad1. wynik assembly -> " << w << endl;
    //zadanie2
    a = 10, b = 11, w = 1;
    if (a != b) w = a * b;
    else w = 0;
    cout << "Zad2. wynik c++ -> " << w << endl;
    w = 1;
    w = zad2(a, b);
    cout << "Zad2. wynik assembly -> " << w << endl;
    //zadanie3
    a = 0, b = 119, w = 1;
    if (a != 0) w = b / a;
    else {
        if (b != 0) w = a / b;
    }
    cout << "Zad3. wynik c++ -> " << w << endl;
    w = 1;
    w = zad3(a, b, w);
    cout << "Zad3. wynik assembly -> " << w << endl;
    //zadanie4
    w =33;
    int c = 0;
    switch (c) {
    case 0: w *= c;
        break;
    case 1: w += c;
        break;
    case 2: w -= c;
        break;
    case 3: w = w * w * w;
        break;
    default:
        w = w + 1;
        break;
    }
    cout << "Zad4. wynik c++ -> " << w << endl;
    w = 33;
    w = zad4(c,w);
    cout << "Zad4. wynik assembly -> " << w << endl;
    //zadanie5
    c = 10;
    w = 0;
    for (int i = 0; i < c; i++) w += i;
    cout << "Zad5. wynik c++ -> " << w << endl;
    w = 0;
    w = zad5(c, w);
    cout << "Zad5. wynik assembly -> " << w << endl;
    //zadanie6
    w = 0;
    c = 5;
    a = 0;
    while (a < 5) {
        w += c;
        a++;
    }
    cout << "Zad6. wynik c++ -> " << w << endl;
    w = 0;
    w = zad6(c, w);
    cout << "Zad6. wynik assembly -> " << w << endl;
    //zadanie7_1
    w = 0;
    w = zad7_1(c, w);
    cout << "Zad7_1. wynik assembly -> " << w << endl;
    //zadanie7_2
    w = 0;
    w = zad7_2(c, w);
    cout << "Zad7_2. wynik assembly -> " << w << endl;
    //zadanie8
    w = 1;
    a = 8;
    for (int i =1; i <= a; i++) w *= i;
    cout << "Zad8. wynik c++ -> " << w << endl;
    w = 1;
    w = zad8(a, w);
    cout << "Zad8. wynik assembly -> " << w << endl;
 

    return 0;
}
