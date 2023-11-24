#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
void wypisz(const int* t, const unsigned int n);
int* utworz1(const unsigned int n);
void utworz2(int*& t, const unsigned int n);
void utworz3(int* t, const unsigned int n);
void usun(int* t);
void wypelnij(int* t, const unsigned n);
void wypelnij1(int* t, const unsigned n);
void wypelnij2(int* t, const unsigned n, const int a, const int b);
int* suma1(const int* t1, const int* t2, const unsigned int n);
void suma2(const int* t1, const int* t2, int*& t3, const unsigned int n);
void suma3(const int* t1, const int* t2, int* t3, const unsigned int n);
int* kasuj(int* t, const unsigned int n, const unsigned int e);
void dodaj(int* t, const unsigned int e);
int main(){
	srand(time(NULL));
	unsigned int n,a,b,e;
	cout<<"Podawaj wartosci n, a, b oraz element tablicy \n";
	cin>>n>>a>>b>>e;
	int *t = utworz1(n);
	wypelnij(t,n);
	wypisz(t,n);
	
	int *t1 = nullptr;
	utworz2(t1,n);
	wypisz(t1,n);
	
	int* t2 = nullptr;
	utworz2(t2,n);
	wypelnij2(t2, n, a, b);
	wypisz(t2,n);
	
	int* t3 = nullptr;
	utworz2(t3,n);
	wypelnij1(t3, n);
	wypisz(t3,n);
	
	int* t4= nullptr;
	utworz2(t4,n);
	wypelnij1(t4, n);
	dodaj(t4,e);
	wypisz(t4,n);
	
	int *t5 = suma1(t3,t4,n);
	wypisz(t5,n);
	
	int *sum = nullptr;
	suma2(t3,t4,sum,n);
	wypisz(sum,n);
	
	int *t7 = nullptr;
	utworz2(t7,n);
	suma3(t3,t4,t7,n);
	wypisz(t7,n);
	
	int *t8 = kasuj(t7,n,e);
	wypisz(t8,n-1);
	
	usun(t);
	usun(t1);
	usun(t2);
	usun(t3);
	usun(t4);
	usun(t5);
	usun(sum);
	usun(t7);
	usun(t8);
	
	return 0;
}
void wypisz(const int* t, const unsigned int n){
	for(unsigned int i=0; i<n; i++) cout<<t[i]<<"\t";
	cout<<endl;
}
int* utworz1(const unsigned int n){
	int* t = new int[n];
	for(unsigned int i=0; i<n; i++) t[i]=0;
	return t;
}
void utworz2(int*& t, const unsigned int n){
	t = new int[n];
	for(unsigned int i=0; i<n; i++) t[i]=0;
}
void utworz3(int* t, const unsigned int n){
	for(unsigned int i=0; i<n; i++) t[i]=0;
}
void usun(int* t){
	if(t){
		delete [] t;
		t=nullptr;
	}
}
void wypelnij(int* t, const unsigned n){
	for(unsigned int i=0; i<n; i++){
		if(i<n/2) t[i] = 0;
		else t[i] = i+1;
	}
}
void wypelnij1(int* t, const unsigned n){
	for(unsigned int i=0; i<n; i++) t[i] = rand() %100;
}
void wypelnij2(int* t, const unsigned n, const int a, const int b){
	for(unsigned int i=0; i<n; i++){
		for(unsigned int i=0; i<n; i++) t[i] = a + rand() % abs(b-a);
	}
}
int* suma1(const int* t1, const int* t2, const unsigned int n){
	int* t = new int[n];
	for(unsigned int i=0; i<n; i++) t[i]=t1[i]+t2[i];
	return t;
}
void suma2(const int* t1, const int* t2, int*& t3, const unsigned int n){
	t3 = new int[n];
	for(unsigned int i=0; i<n; i++) t3[i]=t1[i]+t2[i];
}
void suma3(const int* t1, const int* t2, int* t3, const unsigned int n){
	for(unsigned int i=0; i<n; i++) t3[i]=t1[i]+t2[i];
}
int* kasuj(int* t, const unsigned int n, const unsigned int e){
	int* k = new int[n-1];
	for(unsigned int i=0; i<n-1; i++){
		if(i<e-1) k[i] = t[i];
		else if(i>=e-1) k[i] = t[i+1]; 
	}
	return k;
}
void dodaj(int* t, const unsigned int e){
	t[0]=e;
}
