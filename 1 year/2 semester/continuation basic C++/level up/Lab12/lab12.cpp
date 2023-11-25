#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct SMieszkanie{
	unsigned numer;
	float powierchnie;
	float wysokosc;
	unsigned liczba_pokoi;
};

struct SPietro{
	unsigned numer;
	float liczba_mieszkan;
	SMieszkanie* mieszkanie;
};

struct SKlatka{
	unsigned numer;
	float liczba_pieter;
	SPietro* pietro;
};

struct SBlok{
	unsigned numer;
	string ulica;
	unsigned liczba_klatek;
	SKlatka* klatka;
};

void wczytaj(SBlok& blok, ifstream& in){
	in >> blok.ulica;
	in >> blok.numer;
	in >> blok.liczba_klatek;
	blok.klatka = new SKlatka[blok.liczba_klatek];
	for (unsigned i = 0; i < blok.liczba_klatek; i++){
		in >> blok.klatka[i].numer;
		in >> blok.klatka[i].liczba_pieter;
		blok.klatka[i].pietro = new SPietro[blok.klatka[i].liczba_pieter];
		for (unsigned j = 0; j < blok.klatka[i].liczba_pieter; j++){
			in >> blok.klatka[i].pietro[j].numer;
			in >> blok.klatka[i].pietro[j].liczba_mieszkan;
			blok.klatka[i].pietro[j].mieszkanie = new SMieszkanie[blok.klatka[i].pietro[j].liczba_mieszkan];
			for (unsigned k = 0; k < blok.klatka[i].pietro[j].liczba_mieszkan; k++){
				in >> blok.klatka[i].pietro[j].mieszkanie[k].numer;
				in >> blok.klatka[i].pietro[j].mieszkanie[k].powierchnie;
				in >> blok.klatka[i].pietro[j].mieszkanie[k].wysokosc;
				in >> blok.klatka[i].pietro[j].mieszkanie[k].liczba_pokoi;
			}
		}
	}
}

void wypiszMieszkanie(const SMieszkanie& mieszkanie, ostream& out){
	out << " Numer mieszkania: " << mieszkanie.numer << endl;
	out << " Powierzchnia: " << mieszkanie.powierchnie << endl;
	out << " Wysokosc: " << mieszkanie.wysokosc << endl;
	out << " Liczba pokoi: " << mieszkanie.liczba_pokoi;
}

void wypiszPietro(const SPietro& pietro, ostream& out){
	for (unsigned i = 0; i < pietro.liczba_mieszkan; i++){
		out << " Mieszkanie numer: " << (i + 1) << endl << endl;
		wypiszMieszkanie(pietro.mieszkanie[i], out);
	}
}

void wypiszKlatka(const SKlatka& klatka, ostream& out){
	for (unsigned i = 0; i < klatka.liczba_pieter; i++){
		out << " Pietro numer: " << (i + 1) << endl << endl;
		wypiszPietro(klatka.pietro[i], out);
	}
}

void wypisz(const SBlok& blok, ostream& out){
	for (unsigned i = 0; i < blok.liczba_klatek; i++){
		out << "Klatka numer: " << (i + 1) << endl << endl;
		wypiszKlatka(blok.klatka[i], out);
	}
}

void usun(SBlok& blok){
	for (unsigned i = 0; i < blok.liczba_klatek; i++){
		for (unsigned j = 0; j < blok.klatka[i].liczba_pieter; j++){
			delete[] blok.klatka[i].pietro[j].mieszkanie;
		}
		delete[] blok.klatka[i].pietro;
	}
	delete[] blok.klatka;
}
			
int main(int argc, char** argv){
	if (argc != 3){
		cerr << "Error!" << endl;
		return -1;
	}
	SBlok blok;
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	wczytaj(blok, in);
	wypisz(blok, out);
	out.close();
	usun(blok);
}

