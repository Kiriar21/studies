#include <iostream> 

using namespace std;
unsigned int zad8(unsigned int silnia);
int main() {
	unsigned int silnia;
	cout<<"Podaj wartosc z jakiej chcesz policzyc silnie \n";
	cin>>silnia;
		cout<<"Wynik silni to: "<<zad8(silnia)<<endl;
	return 0;
}
unsigned int zad8(unsigned int silnia){
	unsigned int wynik = 1;
	for( unsigned int i=1; i<=silnia; i++){
		wynik*=i;
	}
	return wynik;

}
