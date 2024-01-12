#include <iostream>
#include <cmath>
#include <ctime>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
void wypelnij(int** t, const int wiersze, const int kolumny);
void wyzeruj(int** t, const int wiersze, const int kolumny);
void wypisz(int** t, const int wiersze, const int kolumny);
extern "C" INT64 suma(int** macierz, INT64 wiersze, INT64 kolumny);
int main()
{
	srand(time(NULL));
	//rozmiary tablic
	int n = 5, m = 7;
	//tworzenie tablic
	int** macierz = new int*[n];
	for (int i = 0; i < n; i++) macierz[i] = new int[m];
	//wyzerowanie elementow tablic
	wyzeruj(macierz, n, m);
	//Wypelnienie tablic pseudolosowymi wartosciami
	wypelnij(macierz,n,m);
	//Wypisanie tablic po losowaniu
	cout << endl << "1. Tablica dwuwymiarowa\n";
	wypisz(macierz, n, m);
	cout << endl;
	int suma_m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) suma_m += macierz[i][j];
	int suma_macierzy = suma(macierz, n, m);
	cout << "Suma macierzy z assembly: " << suma_macierzy << " a powinna wyjsc: " << suma_m << endl;
	//Usuwanie dwuwymiarowej
	for (int i = 0; i < n; i++) delete[] macierz[i];
	delete[] macierz;
}
void wypelnij(int** t, const int wiersze, const int kolumny) {
	for (int i = 0; i < wiersze; i++) 
		for (int j=0; j<kolumny; j++) 
			t[i][j] = rand() % 100;
}
void wyzeruj(int** t, const int wiersze, const int kolumny) {
	for (int i = 0; i < wiersze; i++)
		for (int j = 0; j < kolumny; j++)
			t[i][j] = 0 ;
}
void wypisz(int** t, const int wiersze, const int kolumny) {
	for (int i = 0; i < wiersze; i++) {
		for (int j = 0; j < kolumny; j++) {
			cout << t[i][j] << "\t";
		}
		cout << endl;
	}	
		
}