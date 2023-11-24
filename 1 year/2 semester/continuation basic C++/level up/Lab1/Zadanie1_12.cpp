#include <iostream> 

using namespace std;

int main() {
	const unsigned n=6;
	int T[n];
	for(unsigned int i=0;i<n;i++){
		if(i%2==0) T[i]=2;
		else T[i]=0;
		cout<<T[i]<<"\t";
	}	
	cout<<endl;
	return 0;
}
