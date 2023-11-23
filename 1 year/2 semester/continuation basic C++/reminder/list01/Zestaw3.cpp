#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;
//Task 1
void wypisz(int** t, const unsigned int n, const unsigned int m);
//Task 2
int **utworz1(const unsigned int n, const unsigned int m);
void utworz2(int **&t, const unsigned int n, const unsigned int m);
void utworz3(int *t, const unsigned int n, const unsigned int m);
//Task 3
void usun(int **t, const unsigned int n);
//Task 4
int **wypelnij();
//Task 5
int **suma(const int**t, const int **t1, const unsigned int n, const unsigned int m);
//Task 6
int **roznica(const int **t, const int **t1, const unsigned int n, const unsigned int m);
//Task 7
int **iloczyn(const int **t, const int **t1, const unsigned int n, const unsigned int m);
// Task 8
int **transponowanie(int **t, const unsigned int n, const unsigned int m);
// Task 9
void tabliczka(const unsigned int n, const unsigned int m);
int main(int argc, char **argv)
{
    srand(time(NULL));
    return 0;
}
//Task 1
void wypisz(int** t, const unsigned int n, const unsigned int m){
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            cout<<t[i][j]<<'\t';
        }
        cout<<'\n';
    }
}
//Task 2
int **utworz1(const unsigned int n, const unsigned int m){
    int** t = new int*[n];
    for(unsigned int i=0;i<n;i++){
        t[i]=new int[m];
    }
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            t[i][j]=0;
        }
    }
    return t;
}
void utworz2(int **&t, const unsigned int n, const unsigned int m){
    t = new int *[n];
    for (unsigned int i = 0; i < n; i++)
    {
        t[i] = new int[m];
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned j = 0; j < m; j++)
        {
            t[i][j] = 0;
        }
    }
}
void utworz3(int **t, const unsigned int n, const unsigned int m){
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            t[i][j] = 0;
        }
    }
}
//Task 3
void usun(int **t, const unsigned int n){
    if(t){
        for(unsigned int i=0;i<n;i++){
            delete [] t[i];
            t[i]=nullptr;
        }
        delete [] t;
        t=nullptr;
    }
}
//Task 4
int **wypelnij(){
    int poczatek,koniec;
    unsigned int n,m;
    cout<<"Podaj ilosc wierszy:\n";
    cin>>n;
    cout<<"Podaj ilosc kolumn:\n";
    cin>>m;
    int **t=new int*[n];
    for(unsigned int i=0;i<n;i++){
        t[i]=new int[m];
    }
    cout<<"Podaj poczatek zakresu:\n";
    cin>>poczatek;
    cout<<"Podaj koniec zakresu:\n";
    cin>>koniec;
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            t[i][j] = poczatek + rand()%abs(poczatek-koniec);
        }
    }
    return t;
}
//Task 5
int **suma(int**t, int **t1, const unsigned int n, const unsigned int m){
    int **suma=new int*[n];
    for (unsigned int i = 0; i < n; i++)
    {
        suma[i] = new int[m];
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            suma[i][j] = t[i][j]+t1[i][j];
        }
    }
    return suma;
}
//Task 6
int **roznica(int **t, int **t1, const unsigned int n, const unsigned int m){
    int **roznica = new int *[n];
    for (unsigned int i = 0; i < n; i++)
    {
        roznica[i] = new int[m];
    }
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
        {
            roznica[i][j] = t[i][j] - t1[i][j];
        }
    }
    return roznica;
}
//Task 7
int **iloczyn(int **t, int **t1, const unsigned int n, const unsigned int m){
    int **iloczyn = new int *[n];
    for (unsigned int i = 0; i < n; i++)
    {
        iloczyn[i] = new int[m];
    }
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<m;j++){
            int suma=0;
            for(unsigned k=0;k<m;j++){
                suma+=t[i][k]*t1[k][j];
            }
            iloczyn[i][j]=suma;
        }
    }
    return iloczyn;
}
// Task 8
int **transponowanie(int **t, const unsigned int n, const unsigned int m){
    int **transponowana = new int*[m];
    for(unsigned int i=0;i<m;i++){
        transponowana[i]=new int[n];
    }
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<m;j++){
            transponowana[j][i]=t[i][j];
        }
    }
    return transponowana;
}
// Task 9
void tabliczka(const unsigned int n, const unsigned int m){
    for(unsigned int i=1;i<=n;i++){
        for(unsigned int j=1;j<=m;j++){
            cout<<i*j<<'\t';
        }
        cout<<'\n';
    }
}