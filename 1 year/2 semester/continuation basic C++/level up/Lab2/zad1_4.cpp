#include <iostream>

using namespace std;
double long fibo_ite(double long fibo);
int main(){
	double long fibo;
	cout<<"Podaj n-ty wyraz ciagu fibo aby go zobaczyc.\n";
	cin>>fibo;
	cout<<"Twoj "<<fibo<<" wyraz ciagu fibo wynosi: "<<fibo_ite(fibo)<<endl;
	return 0;
}
double long fibo_ite(double long fibo){
	double long a=1,b=1,c;
	if(fibo<=2) return 1;
	else{
		for(unsigned long long i=3; i<=fibo; i++){
			c=a+b;
			a=b;
			b=c;
		}
		return c;
	}
}
