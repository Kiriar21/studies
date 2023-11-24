#include <iostream> 

using namespace std;
void zad3(int* T, const unsigned n);
int main() {
	const unsigned n=10;
	int T[n];
	zad3(T,n);
	cout<<endl;
	return 0;
}
void zad3(int* T, const unsigned n){
	for(unsigned int i=0;i<n;i++){
		T[i] = i-5;
		cout<<T[i]<<"\t";
	}
}
