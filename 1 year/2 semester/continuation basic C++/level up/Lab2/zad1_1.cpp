#include <iostream>

using namespace std;
double long silnia_rek(double long silnia);
int main(){
	double long silnia;
	cout<<"Podaj liczbe z ktorej chcesz obliczyc silnie\n";
	cin>>silnia;
	cout<<"Twoja silnia z liczby "<<silnia<<" wynosi: "<<silnia_rek(silnia)<<endl;
	return 0;
}
double long silnia_rek(double long silnia){
	if(silnia<=1) return 1;
	else return silnia*silnia_rek(silnia-1);
}
