#include <iostream> 

using namespace std;

int main() {
	const unsigned n=6;
	int T[n];
	int suma=0;
	int pom=0;
	cout<<"Podaj "<<n<<" liczb zeby wpisac do tablicy i znalezc maksymalna z wartosci \n";
	for(unsigned int i=0;i<n;i++){
		cin>>T[i];
		if(T[i]%2!=0 && T[i]%3==0) {
			suma+=T[i];
			pom++;
		}
	}
	if(pom==0) pom=1;
	double sumaa=suma*1.0;
	double wynik=(sumaa/pom);
	if(suma>=0)	cout<<"Srednia arytmetyczna z tej tablicy z wartosci nieparzystych i podzielnych przez 3 to:  "<<wynik<<endl;
	else cout<<"Zadna wartosc nie spelnia warunkow \n"; 
	return 0;
}
