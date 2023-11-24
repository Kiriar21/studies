#include <iostream> 

using namespace std;
void zad111(double* T, const unsigned int n);
int zad112(double* T, const unsigned int n);
int main() {
	const unsigned n=10;
	double T[n];
	zad111(T,n);
	cout<<"Wartosc maksymalnej liczby z tablicy jest zapisana na indexie o numerze: "<<zad112(T,n)<<endl;
	return 0;
}
void zad111(double* T, const unsigned int n){
	cout<<"Podaj "<<n<<" liczb zeby wpisac do tablicy i znalezc maksymalna z wartosci \n";
		for(unsigned int i=0;i<n;i++){
		cin>>T[i];
	}
}
int zad112(double* T, const unsigned int n){
	double max = T[0];
	int index=0;
	for(unsigned int j=1; j<n; j++){
		if(max < T[j]) {
			max=T[j];
			index = j;
		}
	}
	return index;
}
