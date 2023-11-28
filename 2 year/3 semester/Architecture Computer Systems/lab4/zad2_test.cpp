#include <iostream>
#include <iomanip>
using namespace std;
// #include <omp.h>
int main()
{

    float s1 = 0.1, s2 = 0.1, s3 = 0.1, s4 = 0.1, s5 = 0.1, s6 = 0.1, s7 = 0.1, s8 = 0.1, s9 = 0.1, s10 = 0.1, s11 = 0.1, s12 = 0.1, s13 = 0.1, s14 = 0.1, s15 = 0.1, s16 = 0.1; // bufor dla sumy wszystkich elementów tablicy
    cout << "Dla 1 zmiennej:  "<<s1<<"\n";
    cout << "Dla 2 zmiennych: " << std::setprecision(30) << s1 + s2 << " \n";
    cout << "Dla 4 zmiennych: " << std::setprecision(30) << s1 + s2 + s3 + s4  << " \n";
    cout << "Dla 8 zmiennych: " << std::setprecision(30) << s1 + s2 + s3 + s4 + s5 + s7 + s8 << " \n";
    cout << "Dla F zmiennych: " << std::setprecision(30) << s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9 + s10 + s11 + s12 + s13 + s14 + s15 + s16 << " \n";

    return 0;
}