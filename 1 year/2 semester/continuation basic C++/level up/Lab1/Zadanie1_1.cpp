#include <iostream> 

using namespace std;

int main() {
	unsigned int n;
	unsigned int i=0;
	cout<<"Podaj liczbe wyswietlen:\n";
	cin>>n;
	cout<<"Petla for:\n";
	for(; i<n; i++){
		cout<<"Artur M \n";
	}
	cout<<"Petla while:\n";
	while(i>0){
		cout<<"Artur M \n";
		i--;
	} 
	cout<<"Petla do while:\n";
	do{
		cout<<"Artur M \n";
		i++;
	}while(i<n);
	return 0;
}
