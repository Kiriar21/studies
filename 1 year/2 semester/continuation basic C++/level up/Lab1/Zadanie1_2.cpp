#include <iostream> 

using namespace std;

int main() {
	int a,b,c;
	cout<<"Podaj 3 wartosci \n";
	cin>>a>>b>>c;
	if(a>=b && a>=c) cout<<"Najwieksza liczba to: "<<a<<endl;
	else if(b>=c) cout<<"Najwieksza liczba to: "<<b<<endl;
	else cout<<"Najwieksza liczba to: "<<c<<endl;
	return 0;
}
