#include <iostream> 

using namespace std;

int main() {
	const unsigned n=10;
	int T[n];
	for(unsigned int i=0;i<n;i++){
		if(i%2==0) T[i] = i*2;
		else T[i] = i-1; 
		cout<<T[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
