#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;


int* randomNumber(const unsigned int n,const  int a,const int b);
void wypisz(int* t, const unsigned int n);
void usun(int* t);
void zakres(int& a, int &b, const unsigned int n); //skopiowane funkcje z poprzedniego zadania
int** stworz(const unsigned int wiersze, const unsigned int n);
void usun1(int** t, const unsigned int wiersze);
void wypisz1(int** t, const unsigned int wiersze, const unsigned int n);
void wpisz(int** t, const unsigned int wiersze, const unsigned int n, const int a, const int b);
int* totalizator(int*const* t1, int* t2, unsigned int wiersze, unsigned int n);
void wyniki(const int* t1, const unsigned int wiersze);

int main(){
	srand(time(NULL)); 
	int a,b,m,w;
	unsigned int n,wiersze;
	do{
		cout<<"Podaj ilosc liczb losowanych (preferowana liczba z totolotka/minimum - 6)\n";
		cin>>m;
		if(m<=5) cout<<"Rozmiar musi byc wiekszy od 6!\n";
	}while(m<=5);
	n=m;
	do{
		cout<<"Podaj ilosc kuponow, ktore chcesz skreslic\n";
		cin>>w;
		if(w<=0) cout<<"Ilosc musi byc wieksza od 0!\n";
	}while(w<=0);
	wiersze=w;
	zakres(a,b,n); 
	int* randomNum = randomNumber(n,a,b);
	int **kupony= stworz(wiersze,n);
	wpisz(kupony,wiersze,n,a,b);
	wypisz1(kupony, wiersze,n);
	cout<<"W tym losowaniu zostaly wylosowane liczby: \n";
	wypisz(randomNum,n);
	
	int* totek=totalizator(kupony,randomNum,wiersze,n);
	//wypisz(totek,wiersze);
	wyniki(totek,wiersze);


	usun(randomNum);
	usun1(kupony,wiersze);
	usun(totek);
	return 0;
}

void usun(int* t){
	if(t){ delete [] t;
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
void zakres(int& a, int &b, const unsigned int n){
	do{
		cout<<"Podaj zakres liczb do losowania: (najpierw poczatek, pozniej koniec zakresu - musi byc wiekszy od liczb skreslanych!)\n";
		cin>>a>>b;
		if(a==b || abs(b-a)<n+1) cout<<"Musisz podac wiekszy zakres!\n";
	}while(a==b || abs(b-a)<n+1);
}
int** stworz(const unsigned int wiersze, const unsigned int n){
	int** t = new int*[wiersze];
	for(unsigned int i=0; i<wiersze; i++) t[i]= new int[n];
	for(unsigned int i=0; i<wiersze; i++){
		for(unsigned int j=0; j<n; j++){
			t[i][j]=0;
		}
	}
	return t;
}
void usun1(int** t, const unsigned int wiersze){
	if(t){
		for(unsigned int i=0; i<wiersze; i++){
			delete [] t[i];
			t[i]=0;
		}
		delete [] t;
		t=0;
	}
}
void wypisz1(int** t, const unsigned int wiersze, const unsigned int n){
	for(unsigned int i=0; i<wiersze; i++){
		cout<<"Twoj kupon o numerze "<<i+1<<" zawieral liczby: ";
		for(unsigned int j=0; j<n; j++){
			cout<<t[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void wpisz(int** t, const unsigned int wiersze, const unsigned int n, const int a, const int b){
	int c;
	for(unsigned int i=0; i<wiersze; i++){
		cout<<"Podaj liczby do kuponu numer: "<<i+1<<endl;
		for(unsigned int j=0; j<n; j++){
			if(j==0)
			do{
				cin>>t[i][j];
				if(t[i][j]<a || t[i][j]>b) cout<<"Nie mozesz wpisac liczby spoza zakresu!\n";
				}while(t[i][j]<a || t[i][j]>b);

			else if(j>0){

				do{
					cin>>c;
					if(c<a || c>b) cout<<"Nie mozesz wpisac liczby spoza zakresu!\n";
				}while(c<a || c>b);

				unsigned int pom=0;
				while(pom<j){
					while(c==t[i][pom] || c<a || c>b ){
						if(c==t[i][pom]) cout<<"Nie mozna skreslic 2 razy tej samej liczby!\n";
						else if(c<a || c>b)	cout<<"Nie mozesz wpisac liczby spoza zakresu!\n";
							cin>>c;
							pom=0;
					} pom++;
				}
				t[i][j]=c;
			}
		}
	}
}
int* totalizator(int*const* t1, int* t2, unsigned int wiersze, unsigned int n){
	int* t = new int[wiersze];
	for(unsigned int i=0; i<wiersze; i++) t[i]=0;



	for(unsigned int i=0; i<wiersze; i++){
		for(unsigned int j=0; j<n; j++){
			for(unsigned int k=0; k<n; k++){
				if(t2[k]==t1[i][j]) t[i]+=1;
			}
		}
	}


	return t;
}
void wyniki(const int* t1, const unsigned int wiersze){
	for(unsigned int i=0; i<wiersze; i++){
		if(t1[i]>0){ 
		cout<<"Kupon numer : "<<i+1<<". \n";
		switch(t1[i])
		{
		case 1:
			cout<<"Trafiles "<<t1[i]<<" liczbe. Niestety nie udalo Ci sie wygrac.\n";
			break;
		case 2:
			cout<<"Trafiles "<<t1[i]<<" liczby. Niestety nie udalo Ci sie wygrac.\n";
			break;
		case 3:
			cout<<"Trafiles "<<t1[i]<<" liczby. Niestety nie udalo Ci sie wygrac.\n";
			break;
		case 4:
			cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<t1[i]<<" liczby!\n"<<"Wygrana: "<<t1[i]*t1[i]*100<<" euro. \n";
			break;
		case 5:
			cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<t1[i]<<" liczby!\n"<<"Wygrana: "<<t1[i]*t1[i]*1000<<" euro. \n";
			break;					
		case 6:
			cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<t1[i]<<" liczb!\n"<<"Wygrana: "<<t1[i]*t1[i]*10000<<" euro. \n";
			break;
		default:
			cout<<"Tak. Udalo ci sie wygrac. Trafiles "<<t1[i]<<" liczb!\n"<<"Wygrana: "<<t1[i]*t1[i]*(t1[i]*10)*10000<<" euro. \n";
			break;
		}
	}
	else cout<<"Kupon numer : "<<i+1<<". Pusto. \n";
	}
}