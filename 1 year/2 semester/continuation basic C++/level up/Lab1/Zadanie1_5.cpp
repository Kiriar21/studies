#include <iostream> 

using namespace std;

int main() {
	const unsigned n=3;
	int T[n];
	unsigned int suma = 0;
	for(unsigned int i=0;i<n;i++){
		if(i<2) T[i]=1;
		else T[i] = T[i-2]+T[i-1];
		suma+=T[i];
	}
	cout<<"Suma wszystkich wyrazow tego ciagu to: "<<suma<<endl;
	return 0;
}
