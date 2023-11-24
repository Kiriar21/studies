#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void liczbyUzytkownika(int*& t, const unsigned int n, const int a, const int b);
int* randomNumber(const unsigned int n,const  int a,const int b);
void wypisz(int* t, const unsigned int n);
void usun(int* t);
int* totalizator(const int* t1, const int* t2, const unsigned int n);
bool wynik(const int* t1, const unsigned int n, unsigned int& c);
void zakres(int& a, int &b, const unsigned int n);
void score(bool ans, const unsigned int c);

int main(){
	srand(time(NULL)); 
	int a,b,m;
	unsigned int c,n;
	do{
		cout<<"Podaj ilosc liczb losowanych (preferowana liczba z totolotka/minimum - 6)\n";
		cin>>m;
		if(m<=5) cout<<"Rozmiar musi byc wiekszy od 6!\n";
	}while(m<=5);
	n=m;
	zakres(a,b,n); //Uzytkownik podaje zakres z jakiego losujemy pseudolosowe liczby
	int* mojeLiczby = nullptr; // tworzymy i zerujemy tablice w ktora uzytkownik wpisze swoje liczby 
	int* randomNum = randomNumber(n,a,b); // tworzymy tablice w ktora wpiszemy pseudolosowe liczby 
	liczbyUzytkownika(mojeLiczby,n,a,b); 
	cout<<"Podalesz liczby: \n";
	wypisz(mojeLiczby,n);
	cout<<"W tym losowaniu zostaly wylosowane liczby: \n";
	wypisz(randomNum,n);
	int* razem=totalizator(randomNum,mojeLiczby,n);  //glowna funkcja sprawdzajaca czy trafilismy w wylosowane liczby
	bool ans=wynik(razem,n,c); // zwraca wartosc true/false czy udalo nam sie cos wygrac oraz w zmiennej c przechowuje ilosc zgadnietych liczb
	score(ans,c);  //wynik naszej gry
	usun(mojeLiczby);
	usun(randomNum);
	usun(razem);
	return 0;
}
void liczbyUzytkownika(int*& t, const unsigned int n, const int a, const int b){
	t = new int[n];
	int c=0;
	cout<<"Podaj liczby, ktore skrelasz ("<<n<<" liczb)\n";
	for(unsigned int i=0; i<n; i++)
	{
		if(i==0){
		do{
			cin>>t[i];
			if(t[i]<a || t[i]>b) cout<<"Nie mozesz wpisac liczby spoza zakresu!\n";
		}while(t[i]<a || t[i]>b);
		}
			else if(i>0){

				do{
					cin>>c;
					if(c<a || c>b) cout<<"Nie mozesz wpisac liczby spoza zakresu!\n";
				}while(c<a || c>b);
					unsigned int pom=0;
					while(pom<i){
						while(c==t[pom] || c<a || c>b ){
						if(c==t[pom] ) cout<<"Nie mozna skreslic 2 razy tej samej liczby!\n";
						else if( c<a || c>b) cout<<"Nie mozesz wpisac liczby spoza zakresu!\n";
						cin>>c;
						pom=0;
					}	pom++;
				}
				t[i]=c;
			}

	} 
}
void usun(int* t){
	if(t){ 
		delete [] t;
		t=nullptr;
	}
}
int* randomNumber(const unsigned int n,const  int a,const int b){
	int* t = new int[n];
	unsigned int i=0;
	do{
			t[i]= a + rand()% abs(b-a);
			i++;
	}while(i<n);  // losowanie randomowych liczb 	
	if(abs(b-a)>=n){  //jeżeli zakres losowanych liczb podany przez użytkownika jest wiekszy lub równy 6 to sprawdzamy powtarzanie sie liczb 
	for(unsigned int i=0; i<n-1; i++){ // z mniejszym zakresem nie mozemy wylosowac 6 roznych liczb
		for(unsigned int j=i+1; j<n; j++){
			unsigned int pom=0;
				while(t[i]==t[j]){
					if(t[i]==t[j]){
						t[j]= a + rand()% abs(b-a);
						pom++;
					}
				}
				if(pom>0){
						i=0;
						j=i+1;
				}
			}
		}
	}
	return t;
}
void wypisz(int* t, const unsigned int n){
	for(unsigned int i=0; i<n;i++) cout<<t[i]<<"\t";
	cout<<endl;
}
int* totalizator(const int* t1, const int* t2,const unsigned int n){
	int* t3 = new int[n]; //stworzenie pomocniczej tablicy
	for(unsigned int i=0; i<n; i++) t3[i]=0; // wyzerowanie pomocniczej tablicy
	for(unsigned int i=0; i<n; i++){ 
		for(unsigned int j=0; j<n; j++){ 
			if(t1[i]==t2[j]) t3[i]=t3[i]+1; 
		}
	}
	return t3;
}
bool wynik(const int* t1, const unsigned int n, unsigned int& c){
	unsigned int suma=0;
	for(unsigned int i=0; i<n; i++){
		if(t1[i]>=1){ 
			suma++;
		}
	}	
	c=suma;
	if(suma==0) return 0;
	else return 1;
}
void zakres(int& a, int &b, const unsigned int n){
	do{
		cout<<"Podaj zakres liczb do losowania: (najpierw poczatek, pozniej koniec zakresu - musi byc wiekszy od liczb skreslanych!)\n";
		cin>>a>>b;
		if(a==b || abs(b-a)<n+1) cout<<"Musisz podac wiekszy zakres!\n";
	}while(a==b || abs(b-a)<n+1);
}
void score(bool ans, const unsigned int c){
	if(ans>=1){
		cout<<"Udalo ci sie trafic: "<<c<<" liczb. ";
		switch(c){
			case 1:
				cout<<"Niestety nie udalo Ci sie wygrac.\n";
				break;
			case 2:
				cout<<"Niestety nie udalo Ci sie wygrac.\n";
				break;
			case 3:
				cout<<"Niestety nie udalo Ci sie wygrac.\n";
				break;
			case 4:
				cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<c<<" liczby!\n"<<"Wygrana: "<<c*c*100<<" euro. \n";
				break;
			case 5:
				cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<c<<" liczby!\n"<<"Wygrana: "<<c*c*1000<<" euro. \n";
				break;					
			case 6:
				cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<c<<" liczb!\n"<<"Wygrana: "<<c*c*10000<<" euro. \n";
				break;
			default:
				cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<c<<" liczb!\n"<<"Wygrana: "<<c*c*(c*10)*10000<<" euro. \n";
				break;
		}
	}
	else cout<<"NIE. Niestety nie udalo Ci sie zgadnac zadnej liczby.\n"; //przypadek przegranej && zadanie - orzekanie NIE - przegrana 
}
