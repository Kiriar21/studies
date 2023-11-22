    #include <iostream>
    #include <iomanip>
    #include <cmath>
    //---------------------------------------Calkowanie Numeryczne - Metoda Trapezow-------------------------------------------------//
    using namespace std;
    double calkowanieInterpolacja(double tabX[], double x){
        double calka=0.00;
        if(x<=0.210526) calka=tabX[0]*pow(x,4)+tabX[1]*pow(x,3)+tabX[2]*pow(x,2)+tabX[3]*pow(x,1)+tabX[4]*1;
        else if(x>0.210526 && x<=0.421053) calka=tabX[5]*pow(x,4)+tabX[6]*pow(x,3)+tabX[7]*pow(x,2)+tabX[8]*pow(x,1)+tabX[9]*1;
        else if(x>0.421053 && x<=0.631579) calka=tabX[10]*pow(x,4)+tabX[11]*pow(x,3)+tabX[12]*pow(x,2)+tabX[13]*pow(x,1)+tabX[14]*1;
        else if(x>0.631579 && x<=0.842105) calka=tabX[15]*pow(x,4)+tabX[16]*pow(x,3)+tabX[17]*pow(x,2)+tabX[18]*pow(x,1)+tabX[19]*1;
        else calka=tabX[20]*pow(x,3)+tabX[21]*pow(x,2)+tabX[22]*pow(x,1)+tabX[23]*1;
        return calka;
    }
    double calkowanieAproksymacja(double tabX[], double x ){
        return tabX[0]*x+tabX[1];
    }
    int main(){
    //--------------------------------------------------Funkcja Interpolacyjna-------------------------------------------------------//
        //Macierz z wartoscami - Funkcje Interpolacyjne 
        double xFourToZerox4[24]={-1214770.681390, 490872.254639, -57052.560952, 1791.558857, -481.417000,-3313195.297398, 3564879.560243, -1366838.995262, 219748.781200, -12876,
    15890148.110068, -34287340.361557, 27456107.843447, -9668050.341102, 1262493.137603, 36956213.174132, -107123914.757894,  115857019.643662, -55409449.801239,  9887308.733120,
    5323963.155411,-15055481.634138,14142300.978777,-4413217.530051};
        //Macierz pomocnicza do sumowania wartosci calek
        double doObliczenWartosci[10001]={};
        const unsigned int n=10000;
        const double a=0.00, b=1.00;
        //Obliczanie przedzialu
        double p=(double)(b-a)/n; 
        double calkaInterpolacja=0.00;
        doObliczenWartosci[0]=0;
        //Obliczenie wartosci kazdego 'x' do metody trapezow
        for(unsigned int i=1; i<=n; i++) doObliczenWartosci[i]=doObliczenWartosci[i-1]+p;
        //Wyznaczanie calki z danego x'a podstawiajac pod funkcje interpolacyjne
        double pomx=0.00, pomx1=0.00;
        for(unsigned int i=0; i<=n-1; i++){
            pomx=calkowanieInterpolacja(xFourToZerox4,doObliczenWartosci[i]);
            pomx1=calkowanieInterpolacja(xFourToZerox4, doObliczenWartosci[i+1]);
            calkaInterpolacja+=(((pomx+pomx1)/2)*p);
        }
        cout<<"Calka z funkcji interpolacyjnej wynosi: "<<calkaInterpolacja<<"\n";
    //--------------------------------------------------Funkcja Aproksymacyjna-------------------------------------------------------//
        //Do obliczeń posłużyłem się już istniejącą macierzą z wyliczania całki z funkcji interpolacji oraz innymi zmiennymi
        double xApro[2]={-436.951,-345.743};
        pomx=0.00, pomx1=0.00;
        double calkaAproksymacja=0.00;
        for(unsigned int i=0; i<=n-1; i++){
            pomx=calkowanieAproksymacja(xApro,doObliczenWartosci[i]);
            pomx1=calkowanieAproksymacja(xApro, doObliczenWartosci[i+1]);
            calkaAproksymacja+=((pomx+pomx1)/2)*p;
        }
        cout<<"Calka z funkcji aproksymujacej wynosi: "<<calkaAproksymacja<<"\n";
        return 0;
    }