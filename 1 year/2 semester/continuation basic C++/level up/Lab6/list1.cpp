#include <iostream>
#include <fstream>

using namespace std;
int suma(int a, int b);
int roznica(int a, int b);
int iloczyn(int a, int b);
int iloraz(int a, int b);
bool sprawdz(int (*funkcja)(int a, int b), int a, int b){
	if((*funkcja)(a,b)>=0) return 1;
	else return 0;
}

int main(){
	ofstream file("wyniki.txt");
	
	if(file.good()){
		cout<<"Poprawne otwarcie pliku"<<endl;
		}
	else{
		cerr<<"Błąd otwarcia pliku wejsciowego"<<endl;
		return -10;
	}
	
	int a, b;
	cout << "Podaj dwie liczby calkowite: " << endl;
	cin >> a >> b;
	file << "Liczby podane to: "<< a << " i " << b <<endl;
	if(sprawdz(suma, a, b))
	file << "Suma jest wieksza lub rowna 0" << endl;
	else
	file << "Suma jest mniejsza od 0" << endl;
	if(sprawdz(roznica, a, b))
	file << "Roznica jest wieksza lub rowna 0" << endl;
	else
	file << "Roznica jest mniejsza od 0" << endl;
	if(sprawdz(iloczyn, a, b))
	file << "Iloczyn jest wieksza lub rowna 0" << endl;
	else
	file << "Iloczyn jest mniejszy od 0" << endl;
	if(sprawdz(iloraz, a, b))
	file << "Iloraz jest wieksza lub rowna 0" << endl;
	else
	file << "Iloraz jest mniejszy od 0" << endl;
	
		
	file.close();
	
	return 0;
}
int suma(int a,int b){
	return a+b;
}
int roznica(int a, int b){
	return a-b;
}
int iloczyn(int a, int b){
	return a*b;
}
int iloraz(int a, int b){
	if(b!=0) return a/b;
	else return 0;
}
