#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
double sredniaArytm(const double z[]){
    double srednia=0.00;
    for(unsigned int i=0; i<20; i++){
        srednia+=z[i];
    }
    return srednia/20;
}
int main(int argc, char** argv){
    ifstream plik("135869.dat");
    ofstream out("DaneWyjsciowe135869.txt");
    //Ustalenie ilosci znakow obliczen
    cout<<setprecision(20);
    //Tablica przechowująca wartosci z z danego przedzialu x + tablica z wynikami
    double z[20]={}, wynik[20][2]={};
    //Zmienna x,y ktora na razie nic nam nie daje + wartosc sredniej do pozniejszych obliczen
    double x=0.00, y=0.00, wartoscSredniejArytmetycznej=0.00;
    unsigned int j=0;
    while(!plik.eof()){
        for(unsigned int i=0; i<20; i++){
            plik>>x>>y>>z[i];               //Wczytywanie zmiennych
        }
        //Policzenie sredniej arytmetycznej z wartosci z dla danego x'a
        wartoscSredniejArytmetycznej=sredniaArytm(z);
        for(unsigned int i=0; i<20; i++){
            z[i]=pow(z[i]-wartoscSredniejArytmetycznej,2);   //Policzenie roznicy kwadratow do wzoru
        }
        //wpisanie do tablicy wynikowej wartosci odchylenia 
        wynik[j][0]=x;
        wynik[j][1]=sqrt(sredniaArytm(z));
        j++;
    }
        //Ustalenie najwiekszego wyniku odchylenia sredniego
        double max=wynik[0][1];
        int pom=0;
        for(unsigned int i=1;i<20;i++){
            if(max<wynik[i][1]){
                max=wynik[i][1];
                pom=i;
            } 
        }
        //Dane wyswietlane w konsoli (mozna wykorzystac do projektu)
        cout<<"Najwieksze srednie odchylenie dla podanych danych wzgledem wierszy (x) jest dla x="<<wynik[pom][0]<<" i wynosi: "<<wynik[pom][1]<<endl;
        plik.close();
        plik.open("135869.dat");
        double zz=0.00;
        while(!plik.eof()){
            plik>>x>>y>>zz;
            if(x==wynik[pom][0]){
                out<<x<<"\t"<<y<<"\t"<<zz<<endl;
            }
        }
        cout<<"Poprawnie zapisano plik.\n";
        plik.close();
        out.close();
return 0;
}