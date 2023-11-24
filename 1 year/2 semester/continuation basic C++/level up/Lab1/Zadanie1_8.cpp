#include <iostream> 

using namespace std;

int main() {
	unsigned int silnia;
	cout<<"Podaj wartosc z jakiej chcesz policzyc silnie \n";
	cin>>silnia;
	unsigned int wynik = 1;
	for( unsigned int i=1; i<=silnia; i++){
		wynik*=i;
	}
	cout<<"Wynik silni to: "<<wynik<<endl;
	return 0;
}
