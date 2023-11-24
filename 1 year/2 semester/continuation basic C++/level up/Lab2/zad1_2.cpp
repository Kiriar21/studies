#include <iostream>

using namespace std;
double long silnia_ite(double long silnia);
int main(){
	double long silnia;
	cout<<"Podaj liczbe z ktorej chcesz obliczyc silnie\n";
	cin>>silnia;
	cout<<"Twoja silnia z liczby "<<silnia<<" wynosi: "<<silnia_ite(silnia)<<endl;
	return 0;
}
double long silnia_ite(double long silnia){
	double long wynik=1;
	if(silnia<=1) return 1;
	else {
		for(int i=2; i<=silnia; i++){
			wynik*=i;
		}
		return wynik;
	}
}
