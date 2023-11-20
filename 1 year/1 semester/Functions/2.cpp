#include <iostream>

using namespace std;
double funkcja(const double temperatura_Fahrenheita);
int main()
{
    double temp = 0;
    cout << "Podaj swoja temperature w fh\n";
    cin >> temp;
    cout << "Temperatura w stopniach Celcjusza po przeliczeniu to: " << funkcja(140.1) << " C.";
    return 1;
}
double funkcja(const double temperatura_Fahrenheita)
{
    return (((temperatura_Fahrenheita - 32) * 5) / 9);
}

// Przyklad na ekranie:
// Dla wartosci: 270
// Temperatura w stopniach Celcjusza po przeliczeniu to: 132.222 C.
// Dla wartosci: 140.1
// Temperatura w stopniach Celcjusza po przeliczeniu to: 60.0556 C.