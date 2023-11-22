#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
//---------------------------Metoda Najmniejszych Kwadratow----------------------------------------//
int main(int argc, char** argv){
    //Dane
        double x[20]={0,0.0526316,0.105263,0.157895,0.210526,0.263158,0.315789,0.368421,0.421053,0.473684,0.526316,0.578947,0.631579,0.684211,0.736842,0.789474,0.842105,0.894737,0.947368,1};
        double y[20]={-481.417,-482.92,-501.606,-443.647,-438.929,-626.749,-472.809,-214.559,-699.632,-795.636,40.6906,-383.716,-1335.6,-128.182,405.786,-1562.33,-1055.31,1169.76,-842.536,-2435.03};
        double suma_x=0.00, suma_y=0.00, iloczynXY=0.00, sumaKwadratowX=0.00; 
        for(unsigned int i=0; i<20; i++){
            suma_x+=x[i]; //Suma X
            suma_y+=y[i]; //Suma y
            iloczynXY+=(x[i]*y[i]);
            sumaKwadratowX+=x[i]*x[i];
        }
        double a = ((20*iloczynXY)-(suma_x*suma_y))/(20*sumaKwadratowX-(suma_x*suma_x));
        double b = (0.05)*(suma_y-(a*suma_x));
        cout<<"Wzor funkcji aproksymujacej: W(x)= "<<a<<"x ";
        if(b>0.00) cout<<"+ "<<b<<endl;
        else cout<<b<<endl;
        return 0;
}