#include <iostream>
#include <fstream>

using namespace std;
double wyliczPochodna(double y1, double y2, double z1, double z2){
    return ((z1-z2)/(y1-y2));
}
void monotonicznosc(int pomocnicza[], double x[]){
    for(unsigned int i=0; i<20; i++){
        if(pomocnicza[i]==-1) cout<<"Funkcja w punkcie "<<x[i]<<" maleje.\n";
        else cout<<"Funkcja w punkcie "<<x[i]<<" rosnie.\n";
    }
}
int main(int argc, char** argv){
        double x[20]={0,0.0526316,0.105263,0.157895,0.210526,0.263158,0.315789,0.368421,0.421053,0.473684,0.526316,0.578947,0.631579,0.684211,0.736842,0.789474,0.842105,0.894737,0.947368,1};
        double y[20]={-481.417,-482.92,-501.606,-443.647,-438.929,-626.749,-472.809,-214.559,-699.632,-795.636,40.6906,-383.716,-1335.6,-128.182,405.786,-1562.33,-1055.31,1169.76,-842.536,-2435.03};
        double pochodne[20]={};
        int pomocnicza[20]={};
        pochodne[0]=((y[1]-y[0])/(x[1]-x[0]));
        pochodne[19]=((y[19]-y[18])/(x[19]-x[18]));
        for(unsigned int i=1; i<19; i++){
            pochodne[i]=wyliczPochodna(x[i+1],x[i-1],y[i+1],y[i-1]);
        }
        for(unsigned int i=0; i<20;i++){
            cout<<"Pochodna z punktu: "<<i+1<<" wynosi : "<<pochodne[i]<<"\n";
            if(pochodne[i]<0) pomocnicza[i]=-1;
            else pomocnicza[i]=1;
        }
        monotonicznosc(pomocnicza,y);
    
    return 0;
}