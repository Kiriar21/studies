#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;
void zamien(double &x, double &y){
    double pom=y;
    y=x;
    x=pom;
}
double sortowanieMediana(double y[]){
    for(unsigned int i=0;i<20;i++){
        for(unsigned int j=i+1; j<20; j++ ){
            if(y[i]>y[j]) zamien(y[i],y[j]);
        }
    }
    return (y[9]+y[10])/2.00;
}
int main(int argc, char** argv){
        double y[20]={-481.417,-482.92,-501.606,-443.647,-438.929,-626.749,-472.809,-214.559,-699.632,-795.636,40.6906,-383.716,-1335.6,-128.182,405.786,-1562.33,-1055.31,1169.76,-842.536,-2435.03};
        double srednia=0;
        for(unsigned int i=0; i<20; i++){
            srednia+=y[i];
        }
        srednia/=20;
        cout<<"Srednia: "<<srednia<<endl;
        //Mediana
        double mediana=0.00;
        mediana=sortowanieMediana(y);
        cout<<"Mediana: "<<mediana<<endl;
        //Odchylenie standardowe
        double odchylenie_wartosciPoszczegolne[20]={};
        double odchylenie_sredniaWartosci=0.00;
        for(unsigned int i=0; i<20; i++){
            odchylenie_wartosciPoszczegolne[i]=pow(y[i]-srednia,2);
            odchylenie_sredniaWartosci+=odchylenie_wartosciPoszczegolne[i];
        }
        odchylenie_sredniaWartosci/=20;
        cout<<"(Dodatkowe) Wariancja (sigma kwadrat): "<<setprecision(10)<<odchylenie_sredniaWartosci<<endl;
        odchylenie_sredniaWartosci=sqrt(odchylenie_sredniaWartosci);
        cout<<"Odchylenie standardowe: "<<odchylenie_sredniaWartosci<<endl;
        return 0;
    }