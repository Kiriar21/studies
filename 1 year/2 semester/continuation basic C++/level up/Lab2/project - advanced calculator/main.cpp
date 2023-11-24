#include <iostream>
#include <cmath> //Do uzycia jedynie sqrt()

using namespace std;

bool kalkulator();
void menu();
void wynik(const double long wyn);
void zad(const unsigned int wynik);
double long podajLiczbeA();
double long podajLiczbeB();
double long podajLiczbeC();
const double long zad1(const double long a, const double long b);
const double long zad2(const double long a, const double long b);
const double long zad3(const double long a, const double long b);
const double long zad4(const double long a, const double long b);
const double long zad5(const double long a);
const double long zad6(const double long a);
const double long zad7(const double long a, const double long aa, const double long aaa);
const double long zad8(const double long a, const double long b, const double long c);
const double long zad9(const double long a, const double long b, const double long c);

int main(){
	while(kalkulator());
	return 0;
}

bool kalkulator(){
	menu();
	unsigned int wybor;
	double long p,q,pom7,pom71,x;
	cin>>wybor;
	switch (wybor){
		case 1:
			zad(wybor);
			p=podajLiczbeA();
			q=podajLiczbeB();
			wynik(zad1(p,q));
			return 1;
		case 2:
			zad(wybor);
			p=podajLiczbeA();
			q=podajLiczbeB();
			wynik(zad2(p,q));
			return 1;
		case 3:
			zad(wybor);
			p=podajLiczbeA();
			q=podajLiczbeB();
			wynik(zad3(p,q));
			return 1;
		case 4:
			zad(wybor);
			p=podajLiczbeA();
			q=podajLiczbeB();
			if(q!=0) wynik(zad4(p,q));
			else cout<<"Nie mozna dzielic przez 0\n\n\n";
			return 1;
		case 5:
			zad(wybor);
			p=podajLiczbeA();
			wynik(zad5(p));
			return 1;
		case 6:
			zad(wybor);
			p=podajLiczbeA();
			wynik(zad6(p));
			return 1;
		case 7:
			zad(wybor);
			p=podajLiczbeA();
			pom7=zad5(p);
			pom71=zad6(p);
			wynik(zad7(p,pom7,pom71));
			return 1;
		case 8:
			zad(wybor);
			p=podajLiczbeA();
			q=podajLiczbeB();
			x=podajLiczbeC();
			if(p>0 && q>0 && x>0) wynik(zad8(p,q,x));	
			else cout<<"Boki trojkata nie moga byc mniejsze od 0!!!\n";
			return 1;
		case 9:
			zad(wybor);
			p=podajLiczbeA();
			q=podajLiczbeB();
			x=podajLiczbeC();
			if(p>0 && q>0 && x>0 && p+q>x && p+x>q && q+x>p) wynik(zad9(p,q,x));
			else if(p<=0 || q<=0 || x<=0) cout<<"Boki trojkata nie moga byc mniejsze od 0!!!\n";
			else if(p+q<=x || p+x<=q || q+x<=p) cout<<"Suma dlugosci bokow nie zgadza sie - nie mozna zbudowac trojkata\n";
			else cout<<"Blad. Sproboj ponownie wpisac wartosci.\n";
			return 1;
		case 10:
			system("clear");
			return 1;
		case 11:
			system("cls");
			return 1;	
		case 12:
			zad(wybor);
			return 0;
		default:
			cout<<"Wpisz liczbe z podanej listy\n";
			return 1;
	}
	return 0;
}
void menu(){
	cout<<"\nWybierz opcje kalkulatora: (wpisz liczbe stojaca przy danym zadaniu matematycznym)\n\n";
	cout<<"1. Dodawanie.\n";	
	cout<<"2. Odejmowanie.\n";
	cout<<"3. Mnozenie.\n";
	cout<<"4. Dzielenie.\n";
	cout<<"5. Kwadrat liczby.\n";
	cout<<"6. Szescian liczby.\n";
	cout<<"7. Wartosc funkcji dla x.\n";
	cout<<"8. Obwod trojkata.\n";
	cout<<"9. Pole trojkata. (wzor Herona)\n";
	cout<<"10. Wyczysc konsole (TYLKO LINUX).\n";
	cout<<"11. Wyczysc konsole (TYLKO WINDOWS).\n";
	cout<<"12. Wyjscie z programu.\n\n";
}
void wynik(double long wyn){
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
		cout<<"Wynik to: "<<wyn<<endl;
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
}
void zad(const unsigned int wynik){
	switch (wynik){
		case 1:
			cout<<"Podaj dwie liczby ktore chcesz dodac:\n";
			break;
		case 2:
			cout<<"Podaj dwie liczby ktore chcesz odjac:\n";
			break;
		case 3:
			cout<<"Podaj dwie liczby ktore chcesz wymnozyc:\n";
			break;
		case 4:
			cout<<"Podaj dwie liczby ktore chcesz podzielic:\n";
			break;
		case 5:
			cout<<"Podaj liczbe ktora chcesz podnies do kwadratu:\n";
			break;
		case 6:
			cout<<"Podaj liczbe ktora chcesz podnies do szescianu:\n";
			break;
		case 7:
			cout<<"Podaj wartosc x dla ktorego chcesz obliczyc funkcje:\n";
			break;
		case 8:
			cout<<"Podaj trzy dlugosci bokow trojkata do obliczenia obwodu:\n";
			break;
		case 9:
			cout<<"Podaj trzy dlugosci bokow trojkata do policzenia pola:\n";
			break;
		case 12:
			cout<<"Do zobaczenia ponownie!\n\n";
			break;		
		default:
			cout<<"Wpisz liczbe z podanej listy\n";
			break;
	}
}
double long podajLiczbeA(){
	double long a;
	cin>>a;
	return a;
}
double long podajLiczbeB(){
	double long b;
	cin>>b;
	return b;
}
double long podajLiczbeC(){
	double long c;
	cin>>c;
	return c;
}
const double long zad1(const double long a, const double long b){
	return a+b;
}
const double long zad2(const double long a, const double long b){
	return a-b;
}
const double long zad3(const double long a, const double long b){
	return a*b;
}
const double long zad4(const double long a, const double long b){
	return a/b;
}
const double long zad5(const double long a){
	return a*a;
}
const double long zad6(const double long a){
	return a*a*a;
}
const double long zad7(const double long a, const double long aa, const double long aaa){
	return ((10*aaa)+(2.5*aa))*((a/2)-(1/aa));
}
const double long zad8(const double long a, const double long b, const double long c){
	return a+b+c;
}
const double long zad9(const double long a, const double long b, const double long c){
	return sqrt((a+b+c)*(a+b-c)*(a-b+c)*(b+c-a))/4;
}
