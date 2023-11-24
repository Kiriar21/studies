#include <iostream> 

using namespace std;
void zad4(int* T, const unsigned n);
int main() {
	const unsigned n=10;
	int T[n];
	zad4(T,n);
	cout<<endl;
	return 0;
}
void zad4(int* T, const unsigned n){
	for(unsigned int i=0;i<n;i++){
		if(i<2) T[i]=1;
		else T[i] = T[i-2]+T[i-1];
		cout<<T[i]<<"\t";
	}	
}
