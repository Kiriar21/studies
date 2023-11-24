#include <iostream> 

using namespace std;
unsigned int zad5(int *T, const unsigned int n);
int main() {
	const unsigned n=10;
	int T[n];
	cout<<"Suma wszystkich wyrazow tego ciagu to: "<<zad5(T,n)<<endl;
	return 0;
}
unsigned int zad5(int *T, const unsigned int n){
	unsigned int suma = 0;
	for(unsigned int i=0;i<n;i++){
		if(i<2) T[i]=1;
		else T[i] = T[i-2]+T[i-1];
		suma+=T[i];
	}
	return suma;
} 
