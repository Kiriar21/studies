#include <iostream> 

using namespace std;
void zad13(int* T, const unsigned int n);
int main() {
	const unsigned n=66;
	int T[n];
	zad13(T,n);
	cout<<endl;
	return 0;
}
void zad13(int* T, const unsigned int n){
	for(unsigned int i=0;i<n;i++){
		if(i%2==0) T[i]=2;
		else T[i]=0;
		cout<<T[i]<<"\t";
	}	
}
