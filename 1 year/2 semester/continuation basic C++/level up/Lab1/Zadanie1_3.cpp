#include <iostream> 

using namespace std;

int main() {
	const unsigned n=10;
	int T[n];
	for(unsigned int i=0;i<n;i++){
		T[i] = i-5;
		cout<<T[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
