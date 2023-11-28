#include <iostream>
#include <iomanip>
#include <omp.h>
int main()
{
    const int n = 1024;          // rozmiar tablicy
    double *tab = new double[n]; // tworzenie obietu w pamięci dla tablicy dynamicznej
    for (int i = 0; i < n; ++i)
        tab[i] = 0.0625;    // wypełnianie tablicy
    double time;            // zmienne dla pomiaru czasu
    double s[16]={};
    time = omp_get_wtime(); // pomiar czasu - start
    // poniższy fragment należy zmienić zgodnie z koncepcją z nagrania
    for (int t = 0; t < n * n; ++t)
    {
        for (int i = 0; i < n; i+=16)
        {
            for(int j = 0; j < 16; ++j){
                s[j]+=tab[i+j];
            } 
           
        }
    }
    for (int j = 1; j < 16; ++j){
        s[0]+=s[j];
    }
    time = omp_get_wtime() - time; // pomiar czasu - stop
    std::cout << std::fixed;
    std::cout << "1. suma = " << std::setprecision(30) << s[0] << " ";
    std::cout << "czas wykonania = " << std::setprecision(3) << time << std::endl;
    delete[] tab; // kasowanie tablicy
    return 0;
}