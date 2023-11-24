#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int** utworz1(const unsigned int n, const unsigned int m);
void utworz2(int**& t, const unsigned int n, const unsigned int m);
void utworz3(int** t, const unsigned int n, const unsigned int m);
void wynik(int** t, const unsigned int n, const unsigned int m);
void usun(int** t, const unsigned int n, const unsigned int m);
void wypelnij(int** t, const unsigned int n, const unsigned int m);
void rozmiar(unsigned int& n, unsigned int& m);
void suma(int *const* t1, int*const* t2, int** t3, const unsigned int n, const unsigned int m, const unsigned int pom1, const unsigned int pom2);
void roznica(int *const* t1, int*const* t2, int** t3, const unsigned int n, const unsigned int m, const unsigned int pom1, const unsigned int pom2);
void iloczyn(int *const* t1, int*const* t2, int** t3, const unsigned int n, const unsigned int m, const unsigned int pom1, const unsigned int pom2);
int** transponowanie(int *const* t1, const unsigned int m, const unsigned int n);
void tabliczkaMnozenia();

int main(){
	srand(time(NULL));
	unsigned int n,m;
	
	int pom1,pom2;
	
	rozmiar(n,m);
	int **t = utworz1(n,m);
	wypelnij(t,n,m);
	wynik(t,n,m);
	pom1=n;
	pom2=m;
	
	rozmiar(n,m);
	int **t1 = nullptr;
	utworz2(t1,n,m);
	wypelnij(t1,n,m);
	wynik(t1,n,m);
	
	
	int** t2 = nullptr;
	utworz2(t2,n,m);
	suma(t,t1,t2,n,m,pom1,pom2);
	
	int** t3 = nullptr;
	utworz2(t3,n,m);
	roznica(t,t1,t3,n,m,pom1,pom2);
	
	int** t4 = nullptr;
	utworz2(t4,n,pom2);
	iloczyn(t,t1,t4,n,m,pom1,pom2);
	
	int** t5 = transponowanie(t,pom2,pom1);
	cout<<"Po transponowaniu pierwsza macierz: \n";
	wynik(t5,pom2,pom1);
	
	int** t6 = transponowanie(t1,m,n);
	cout<<"Po transponowaniu druga macierz: \n";
	wynik(t6,m,n);
	
	tabliczkaMnozenia();
	
	usun(t,pom1,pom2);
	usun(t1,n,m);
	usun(t2,n,m);
	usun(t3,n,m);
	usun(t4,n,pom2);
	usun(t5,pom2,pom1);
	usun(t6,m,n); 

	/*int** t10 = new int*[6]; przyklad uzycia funkcji utworz 3
	for(int i=0; i<6; i++)
	{
		t10[i] = new int[6];
	}
	utworz3(t10,6,6); 
	wynik(t10,6,6);
	usun(t10,6,6); // 
	*/
	return 0;
}
int** utworz1(const unsigned int n, const unsigned int m){
	int** t = new int*[n];
	for(unsigned int i=0; i<n; i++) t[i] = new int[m];
	for(unsigned int i=0; i<n; i++){
		for(unsigned int j=0; j<m; j++){
			t[i][j]=0;
		}
	}
	return t;
}
void utworz2(int**& t, const unsigned int n, const unsigned int m){
	t = new int*[n];
	for(unsigned int i=0; i<n; i++) t[i] = new int[m];
	for(unsigned int i=0; i<n; i++){
		for(unsigned int j=0; j<m; j++){
			t[i][j]=0;
		}
	}	
}
void utworz3(int** t, const unsigned int n, const unsigned int m){
	for(unsigned int i=0; i<n; i++){
		for(unsigned int j=0; j<m; j++){
			t[i][j]=0;
		}
	}
}
void wynik(int** t, const unsigned int n, const unsigned int m){
	for(unsigned int i=0; i<n; i++){
		for(unsigned int j=0; j<m; j++){
			cout<<t[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void usun(int** t, const unsigned int n, const unsigned int m){
	if(t){
		for(unsigned int j=0; j<n; j++){
			delete [] t[j];
			t[j]=0;
			}	
		delete [] t;
		t=0;
	}
}
void wypelnij(int** t, const unsigned int n, const unsigned int m){
	int a,b;
	do{
		cout<<"Podaj zakres z jakiego maja sie losowac liczby \n";
		cin>>a>>b;
		if(a==b) cout<<"Zakres musi byc wiekszy\n";
	}while(a==b);
	
	for(unsigned int i=0; i<n; i++){
		for(unsigned int j=0; j<m; j++){
			t[i][j]= a + rand() % abs(b-a);
		}
	}
	
}
void rozmiar(unsigned int& n, unsigned int& m){
	do{
		cout<<"Podaj rozmiar macierzy dwuwymiarowej: \n";
		cin>>n>>m;
		if(n<=0 || m<=0) cout<<"Macierz musi miec dodatnie wartosci rozmiaru\n";
	}while(n<=0 || m<=0);
}
void suma(int *const* t1, int*const* t2, int** t3, const unsigned int n, const unsigned int m, const unsigned int pom1, const unsigned int pom2){
	if(n==pom1 && m==pom2){
		for(unsigned int i=0; i<n; i++){
			for(unsigned int j=0; j<m; j++){
				t3[i][j]=t1[i][j]+t2[i][j];
			}
		}
		cout<<"Wynik dodawania macierzy to: \n";
		wynik(t3,n,m);
	}
	else cout<<"Nie mozna dodac macierzy, poniewaz maja rozne rozmiary\n";
}
void roznica(int *const* t1, int*const* t2, int** t3, const unsigned int n, const unsigned int m, const unsigned int pom1, const unsigned int pom2){
	if(n==pom1 && m==pom2){
		for(unsigned int i=0; i<n; i++){
			for(unsigned int j=0; j<m; j++){
				t3[i][j]=t1[i][j]-t2[i][j];
			}
		}
		cout<<"Wynik odejmowania macierzy to: \n";
		wynik(t3,n,m);
	}
	else cout<<"Nie mozna odjac macierzy, poniewaz maja rozne rozmiary\n";
}
void iloczyn(int *const* t1, int*const* t2, int** t3, const unsigned int n, const unsigned int m, const unsigned int pom1, const unsigned int pom2){
	if(pom1==m){
		for(unsigned int i=0; i<n; i++){
			for(unsigned int j=0; j<pom2; j++){
				int suma=0;
				for(unsigned int k=0; k<pom2; k++){
					suma+=t1[i][k]*t2[k][j];
				}
				t3[i][j]=suma;
			}
		}
		cout<<"Wynik mnozenia macierzy to: \n";
		wynik(t3,n,pom2);
	}
	else cout<<"Nie mozna mnozyc macierzy, poniewaz maja zle rozmiary\n";
}
int** transponowanie(int *const* t1, const unsigned int m, const unsigned int n){
	int** t= new int*[m];
	for(unsigned int i=0; i<m; i++) t[i] = new int[n];
	for(unsigned int i=0; i<n; i++){
		for(unsigned int j=0; j<m; j++){
			t[j][i] = t1[i][j];
		}
	}	
	return t;
}
void tabliczkaMnozenia(){
	int a,b;
	unsigned int c,d; 
	do{
		cout<<"Podaj rozmiar tabliczki mnozenia jaka chcesz wyswietlic (np. 10 10)\n";
		cin>>a>>b;
		if(a<=0 && b<=0) cout<<"Bledny rozmiar tabliczki mnozenia.\n";
	}while(a<=0 && b<=0);
	c=a;
	d=b;
	for(unsigned int i=1; i<=c; i++){
		for(unsigned int j=1; j<=d; j++){
			cout<<i*j<<"\t";
		}
		cout<<endl;
	}
}
