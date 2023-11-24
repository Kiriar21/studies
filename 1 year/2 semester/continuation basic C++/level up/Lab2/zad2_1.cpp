#include <iostream>
#include <string>
using namespace std;

void zamien1(double long a, double long b);
void zamien2(double long* a, double long* b);
void zamien3(double long& a, double long& b);
void pozamianie(string tekst , double long a, double long b);
int main(){
	double long a,b;
	cout<<"Podaj dwie liczby, ktore chcesz zamienic: \n";
	cin>>a>>b;
	zamien1(a,b);
	pozamianie("wartosc",a,b);
	zamien2(&a,&b);
	pozamianie("wskaznik",a,b);
	zamien3(a,b);
	pozamianie("referencje",a,b);
	return 0;
}
void zamien1(double long a, double long b){
	double long pom;
	pom=a;
	a=b;
	b=pom;
	//cout<<"Twoje liczby po zamianie przez przekazanie wartosci to a: "<<a<<" oraz b: "<<b<<endl;
}
void zamien2(double long* a, double long* b){
	double long pom;
	pom=*a;
	*a=*b;
	*b=pom;
	//cout<<"Twoje liczby po zamianie przez przekazanie wartosci to a: "<<*a<<" oraz b: "<<*b<<endl;
}
void zamien3(double long& a, double long& b){
	double long pom;
	pom=a;
	a=b;
	b=pom;
	//cout<<"Twoje liczby po zamianie przez przekazanie wartosci to a: "<<a<<" oraz b: "<<b<<endl;
}
void pozamianie(string tekst, double long a, double long b){
	cout<<"Po zamiananie przez "<<tekst<<" twoje wartosci a: "<<a<<" oraz b: "<<b<<endl; 
}
