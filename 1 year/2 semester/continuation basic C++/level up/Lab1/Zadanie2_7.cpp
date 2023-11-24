#include <iostream> 

using namespace std;
void zad7(int* T, const unsigned int n);
int main() {
	const unsigned n=10;
	int T[n];
	zad7(T,n);
	cout<<endl;
	return 0;
}
void zad7(int* T, const unsigned int n){
	for(unsigned int i=0;i<n;i++){
		if(i%2==0) T[i] = i*2;
		else T[i] = i-1; 
		cout<<T[i]<<"\t";
	}
}
