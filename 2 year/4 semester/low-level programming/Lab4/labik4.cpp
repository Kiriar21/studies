#include <iostream>
#include <cmath>
#include <ctime>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
void wypelnij(int* t, const int rozmiar);
void wyzeruj(int* t, const int rozmiar);
void wypisz(int* t, const int rozmiar);
extern "C" INT64 zad1(int* tab, INT64);
extern "C" INT64 zad2(int* tab, INT64);
extern "C" INT64 zad3(int* tab, INT64);
extern "C" INT64 zad4(int* tab, INT64);
extern "C" INT64 zad5(int* tab, INT64);
extern "C" INT64 zad6(int* tab, INT64);
//extern "C" INT64 zad7(int* tab, INT64);
extern "C" INT64 zad8(int* tab, int* tab1, INT64);
extern "C" INT64 zad9(int* tab, int* tab1, int* tab2, INT64);
extern "C" INT64 zad10(int* tab, INT64);
int main()
{
	srand(time(NULL));
	//rozmiary tablic
	int n = 5, m = 7;
	//tworzenie tablic
	int* tab = new int[n];
	//wyzerowanie elementow tablic
	wyzeruj(tab, n);
	//Wypelnienie tablic pseudolosowymi wartosciami
	wypelnij(tab, n);
	//Wypisanie tablic po losowaniu
	cout << "1. Tablica jednowymiarowa:\n";
	wypisz(tab, n);
	cout << "\nZad1. Tablica jednowymiarowa do kwadratu:\n";
	zad1(tab, n);
	wypisz(tab, n);
	wyzeruj(tab, n);
	wypelnij(tab, n);
	cout << "\n2. Tablica jednowymiarowa:\n";
	wypisz(tab, n);
	cout << "\nZad2. Tablica jednowymiarowa do kwadratu gdy parzyste:\n";
	zad2(tab, n);
	wypisz(tab, n);
	wyzeruj(tab, n);
	wypelnij(tab, n);
	cout << "\n3. Tablica jednowymiarowa:\n";
	wypisz(tab, n);
	cout << "\nZad3. Tablica jednowymiarowa co drugi el 0:\n";
	zad3(tab, n);
	wypisz(tab, n);
	wyzeruj(tab, n);
	wypelnij(tab, n);
	cout << "\n4. Tablica jednowymiarowa:\n";
	wypisz(tab, n);
	cout << "\nZad4. Tablica jednowymiarowa srednia\n";
	int sr = 0;
	for (int i = 0; i < n; i++) sr += tab[i];
	sr /= n;	
	int zad4_srednia = zad4(tab, n);
	cout << "Srednia wynosi: " << zad4_srednia << " a powinno: "<<sr<<endl;
	int min = tab[0];
	for (int i = 1; i < n; i++) if (min > tab[i]) min = tab[i];
	int min_zad5 = zad5(tab, n);
	wypisz(tab, n);
	cout << "\nMin wynosi: " << min_zad5 << " a powinno: " << min << endl;
	int max = tab[0];
	for (int i = 1; i < n; i++) if (max < tab[i]) max = tab[i];
	int max_zad6 = zad6(tab, n);
	wypisz(tab, n);
	cout << "\nMax wynosi: " << max_zad6 << " a powinno: " << max << endl;
	//zad7 pominiete
	int* tab1 = new int[n];
	wyzeruj(tab1, n);
	wypelnij(tab1, n);
	cout << "8. Tablica jednowymiarowa:\n";
	wypisz(tab, n);
	cout << "\n8. Tablica jednowymiarowa1:\n";
	wypisz(tab1, n);
	zad8(tab, tab1, n);
	cout << "\nzad8. tab+tab1:\n";
	wypisz(tab, n);
	int* tab2 = new int[n];
	wyzeruj(tab2, n);
	cout << "\n9. Tablice tab i tab1 :\n";
	wypisz(tab, n);
	cout << endl;
	wypisz(tab1, n);
	cout << "\nzad9. Po podzieleniu wartosci: \n";
	zad9(tab, tab1, tab2, n);
	wypisz(tab2, n);
	wyzeruj(tab, n);
	wypelnij(tab, n);
	cout << "\n10. Tablice tab:\n";
	wypisz(tab, n);
	zad10(tab, n);
	cout << "\n10. Tablice tab po funkcji:\n";
	wypisz(tab, n);	
	//Usuwanie jednowymiarowej
	delete[] tab;
}
void wypelnij(int* t, const int rozmiar) {
	for (int i = 0; i < rozmiar; i++) t[i] = rand() % 100;
}
void wyzeruj(int* t, const int rozmiar) {
	for (int i = 0; i < rozmiar; i++) t[i] = 0;
}
void wypisz(int* t, const int rozmiar) {
	for (int i = 0; i < rozmiar; i++) cout << t[i] << "\t";
}
