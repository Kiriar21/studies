#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
int* liczbyWylosowane(const unsigned int n);
int* liczbyUzytkownika(const unsigned int n);
bool czyWygrana(const int* t, const int*t2, const unsigned int n, int &traf);
void totalizator(const int traf);
void wypisz(const int*t, const unsigned int n);
void usun(int *t);
bool powtorzenie(const int *t, const unsigned int n, const int liczba);
int main(int argc, char** argv){
    srand(time(NULL));
    unsigned int n=6;
    int* totek=liczbyWylosowane(n);
    int* liczbyUser=liczbyUzytkownika(n);
    int traf=0;
    if(czyWygrana(totek,liczbyUser,n,traf)) totalizator(traf);
    else cout<<"Niestety nic sie nie udalo trafic.\n";
    cout << "Wylosowane liczby: \n";
    wypisz(totek, n);
    cout << "Podane liczby: \n";
    wypisz(liczbyUser, n);
    usun(totek);
    usun(liczbyUser);

    return 0;
}
int *liczbyWylosowane(const unsigned int n){
    int *t = new int[n];
    for(unsigned int i=0;i<n;i++){
        t[i]=1+rand()%(49);
        while(powtorzenie(t,i,t[i]))    t[i] = 1 + rand() % (49);
    }
    return t;
}
int *liczbyUzytkownika(const unsigned int n){
    int *t=new int[n];
    for(unsigned int i=0;i<n;i++){
        cout<<"Podaj "<<i+1<<" liczbe:\n";
        do{
            cin >> t[i];
            if (t[i] > 49 || t[i] < 1) cout<<"Podaj liczbe z zakresu 1-49\n";
        }while(t[i]>49 || t[i]<1);
        
        
        while(powtorzenie(t,i,t[i])){
            cout<<"Powtorzono podana liczbe. Podaj inna.\n";
            cin>>t[i];
        }
    }
    return t;
}
bool czyWygrana(const int *t, const int *t2, const unsigned int n, int &traf){
    for(unsigned int i=0;i<n;i++){
        for(unsigned int j=0;j<n;j++){
            if(t[i]==t2[j]){
                traf++;
            }
        }
    }
    if(traf) return 1;
    else return 0;
}
void totalizator(const int traf){
    switch(traf){
        case 4:
            cout<<traf<<" trafien. Wygrano 10zl.\n";
        break;
        case 5:
            cout << traf << " trafien. Wygrano 100zl.\n";
            break;
        case 6:
            cout << traf << " trafien. Wygrano 1000zl.\n";
            break;
        default:
            cout<<"Niestety nic. "<<traf<<" trafien.\n";
        break;
    }
}
void usun(int *t){
    if(t){
        delete [] t;
        t=nullptr;
    }
}
void wypisz(const int *t, const unsigned int n){
    for(unsigned int i=0;i<n;i++){
        cout<<t[i]<<"\t";
    }
    cout<<endl;
}
bool powtorzenie(const int *t, const unsigned int n, const int liczba)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (liczba == t[i])     return 1;
    }
    return 0;
}