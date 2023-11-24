#include <iostream> 

using namespace std;
void zad101(double* T, const unsigned int n);
double zad102(double* T, const unsigned n);
int main() {
	const unsigned n=10;
	double T[n];
	cout<<"Podaj "<<n<<" liczb zeby wpisac do tablicy i znalezc maksymalna z wartosci \n";
	zad101(T,n);
	cout<<"Wartosc maksymalna z tablicy to: "<<zad102(T,n)<<endl;
	return 0;
}
void zad101(double* T, const unsigned int n){
	for(unsigned int i=0;i<n;i++){
		cin>>T[i];
	}
}
double zad102(double* T, const unsigned n){
	double max = T[0];
	for(unsigned int j=1; j<n; j++){
		if(max < T[j]) max=T[j];
	}
	return max;
}
