#include <iostream> 

using namespace std;

int main() {
	const unsigned n=10;
	double T[n];
	cout<<"Podaj "<<n<<" liczb zeby wpisac do tablicy i znalezc maksymalna z wartosci \n";
	for(unsigned int i=0;i<n;i++){
		cin>>T[i];
	}
	double max = T[0];
	int index=0;
	for(unsigned int j=1; j<n; j++){
		if(max < T[j]) {
			max=T[j];
			index = j;
		}
	}
	cout<<"Wartosc maksymalnej liczby z tablicy jest zapisana na indexie o numerze: "<<index<<endl;
	return 0;
}
