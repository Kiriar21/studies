#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;



bool CzyByla1d(int* t, int liczba, int ktora)
{
	if (ktora <= 0)
		return false;
	for (int i = 0; i < ktora; i++)
	{
		if (t[i] == liczba)
			return true;
	}
	return false;
}

void losuj(int* t, const unsigned int n, const int a, const int b)
{
	if (a < b)
		for (unsigned int i = 0; i < n;)
		{
			t[i] = a + rand() % abs(b - a + 1);
			if (CzyByla1d(t, t[i], i) == false)
				i++;
		}

	else
		for (unsigned int i = 0; i < n;)
		{
			t[i] = b + rand() % abs(a - b + 1);
			if (CzyByla1d(t, t[i], i) == false)
				i++;
		}


}


 void totalizator(unsigned int traf, const int i)
{
	cout << "[" << i + 1 << "] Kupon - ";
	if (traf>2)
		cout << "Gratulacje trafiles " << traf << " razy, ciesz sie wygrana" << endl;
	else
		cout << "Przykro mi trafiles tylko " << traf << " razy i nic nie wygrales" << endl;
}

bool CzyWygrana(int* t, int* tm, const int n, unsigned int& traf)
{
	traf = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (t[i] == tm[j])
				traf++;
	if (traf > 2)
		return true;
	else
		return false;
}


int main(int argc, char *argv [])
{
	srand(time(NULL));

	int ktory = 0;
	ifstream plik;
	ofstream zapis;
	int moje[10];
	plik.open(argv[1]);
	zapis.open(argv[2]);
	if (plik.good() && zapis.good())
	{
		int ilosc = 0;
		plik >> ilosc;
		//cout << ilosc << endl;
		string gierka;
		int a = 1, b = 10;
		int losy[10] = { 0 };
		for (int i = 0; i < ilosc; i++)
		{
			unsigned int trafy = 0;
			plik >> gierka;           //Sprawdzenie jaka to gra z pliku wejsciowego
			//cout << gierka << endl;
			if (gierka == "maly_lotek_5")
			{
				a = 1;                 //dolny zakres
				b = 35;					//gorny zakres
				zapis << gierka << endl;	//zapisanie do pliku wyjsciowego nazwy gry
				losuj(losy, 10, a, b);		//losowanie liczb ktore wygrywaja
				zapis << "Wylosowane_Liczby: "; //zapis do pliku wylosowancych liczb oraz wczytanie liczb podanych przez uzytkownika w pliku wejsciowym
				for (int j = 0; j < 5; j++)
				{
					plik >> moje[j];
					zapis << losy[j] << ' ';
				}

				zapis << endl << "Moje_Liczby: ";	//Zapisanie do pliku liczb uzytkownika
				for (int j = 0; j < 5; j++)
				{
					zapis << moje[j] << ' ';
				}
				zapis << endl;

				CzyWygrana(losy, moje, 5, trafy); //Sprawdzenie ilosci trafien oraz zapisanie do pliku
				zapis << "Ilosc_trafien: " << trafy << endl << "Trafione_Liczby: ";

				for (int k = 0; k < 5; k++) //Liczby ktore zostaly trafione
					for (int j = 0; j < 5; j++)
						if (losy[k] == moje[j])
							zapis << losy[k] << ' ';
				zapis << endl << endl;


			}
			else if (gierka == "duzy_lotek_6")
			{
				a = 1;
				b = 49;
				zapis << gierka << endl;
				losuj(losy, 10, a, b);
				zapis << "Wylosowane_Liczby: ";
				for (int j = 0; j < 6; j++)
				{
					plik >> moje[j];
					zapis << losy[j] << ' ';
				}

				zapis << endl << "Moje_Liczby: ";
				for (int j = 0; j < 6; j++)
				{
					zapis << moje[j] << ' ';
				}
				zapis << endl;
				CzyWygrana(losy, moje, 6, trafy);
				zapis << "Ilosc_trafien: " << trafy << endl << "Trafione_Liczby: ";

				for (int k = 0; k < 6; k++)
					for (int j = 0; j < 6; j++)
						if (losy[k] == moje[j])
							zapis << losy[k] << ' ';
				zapis << endl << endl;
			}
			else if (gierka == "multilotek_10")
			{
				a = 1;
				b = 80;
				zapis << gierka << endl;
				losuj(losy, 10, a, b);
				zapis << "Wylosowane_Liczby: ";
				for (int j = 0; j < 10; j++)
				{
					plik >> moje[j];
					zapis << losy[j] << ' ';
				}

				zapis << endl << "Moje_Liczby: ";
				for (int j = 0; j < 10; j++)
				{
					zapis << moje[j] << ' ';
				}
				zapis << endl;
				CzyWygrana(losy, moje, 10, trafy);
				zapis << "Ilosc_trafien: " << trafy << endl << "Trafione_Liczby: ";

				for (int k = 0; k < 10; k++)
					for (int j = 0; j < 10; j++)
						if (losy[k] == moje[j])
							zapis << losy[k] << ' ';
				zapis << endl << endl;
			}
			else
			{
				cerr << "Zla nazwa gry w pliku"<<endl;
				return 2137;
			}

			totalizator(trafy, ktory);
			ktory++;


		}
		cout << "Wszystko przebieglo pomyslnie plik wyjsciowy zostal wygenerowany"<<endl;
	}
	else
	cerr << "Blad otwarcia pliku do odczytu lub zapisu"<<endl;

	plik.close();
	zapis.close();

	

	return 0;
}