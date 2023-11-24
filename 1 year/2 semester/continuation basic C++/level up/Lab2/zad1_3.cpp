#include <iostream>

using namespace std;
double long fibo_rek(double long fibo);
int main(){
	double long fibo;
	cout<<"Podaj n-ty wyraz ciagu fibo aby go zobaczyc.\n";
	cin>>fibo;
	cout<<"Twoj "<<fibo<<" wyraz ciagu fibo wynosi: "<<fibo_rek(fibo)<<endl;
	return 0;
}
double long fibo_rek(double long fibo){
	if(fibo<=2) return 1;
	else return fibo_rek(fibo-1)+fibo_rek(fibo-2);
}
