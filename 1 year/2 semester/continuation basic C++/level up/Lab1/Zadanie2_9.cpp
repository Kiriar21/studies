#include <iostream> 

using namespace std;
unsigned long long zad9(unsigned int silnia);
int main() {
	unsigned int silnia;
	cout<<"Podaj wartosc z jakiej chcesz policzyc silnie \n";
	cin>>silnia;
		cout<<"Wynik silni to: "<<zad9(silnia)<<endl;
	return 0;
}
unsigned long long zad9(unsigned int silnia){
	if(silnia<2) return 1;
	else return silnia*zad9(silnia-1);
}
