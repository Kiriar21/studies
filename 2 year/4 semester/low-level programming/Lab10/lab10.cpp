#include <iostream>
using namespace std;
int main()
{
    cout << "Zad1\n";
    int n = 10;
    float* tablica = new float[n];
    for (int i = 0; i < n; i++) tablica[i] = rand()/1000;
    for (int i = 0; i < n; i++) cout << tablica[i] << "\t";
    cout << endl;
    double sumaX = 0.0, sumaXX = 0.0;
    for (int i = 0; i < n; i++) sumaX+= tablica[i];


    /*float a=5, b=4, c=2, d=2, x=2;
    float y = 0.0;
    float yas = 0.0;

    float pom = 1;
    for (int i = 1; i <= b; i++) pom *= x;
    pom *= a;
    y = pom;
    pom = 1;
    for (int i = 1; i <= c; i++) pom *= x;
    pom *= b;
    y -= pom;
    y += (c * x) + d;

    __asm {

    }





    cout << "Wynik c++: " << y << endl;
    cout << "Wynik assembler: " << yas << endl;*/
    float kurwa = 0;
    __asm {
        
       
    }
    cout << "c++" << sumaX << " assembler " << sumaXX << endl;
    delete[] tablica;
}