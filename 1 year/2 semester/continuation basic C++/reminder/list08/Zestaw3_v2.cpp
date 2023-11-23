#include <iostream>
#include <fstream>
using namespace std;
struct SSok{
    double wysokosc, promien_podstawy;
    string marka;
};
struct SKarton{
    SSok* soki;
    unsigned ile_sokow;
    int kod;
};
SSok* wczytaj(istream& wejsciowy, unsigned& rozmiar){
    wejsciowy>>rozmiar;
    SSok* soki;
    if(rozmiar>0){
        soki = new SSok[rozmiar];
        for(unsigned i=0;i<rozmiar;i++){
            wejsciowy>>soki[i].wysokosc>>soki[i].promien_podstawy>>soki[i].marka;
        }
    }
    return soki;
}
void pakuj_karton(SKarton& karton, SSok* soki1,const unsigned rozmiar){
    static int kodKartonu=1;
    karton.ile_sokow=rozmiar;
    karton.kod=kodKartonu;
    kodKartonu++;
    karton.soki=soki1;
}
void wypisz(SKarton& karton, ostream& wyjscie){
    wyjscie<<"Kod kartonu: "<<karton.kod<<"\n";
    wyjscie<<"Soki w kartonie: "<<karton.ile_sokow<<endl;
    for(unsigned i=0;i<karton.ile_sokow;i++){
        wyjscie<<"Nazwa soku: "<<karton.soki[i].marka<<"\n";
        wyjscie<<"Wysokosc soku: "<<karton.soki[i].wysokosc<<", Promien podstawy: "<<karton.soki[i].promien_podstawy<<endl;
    }    
}
double zwroc_objetosc(SSok& sok){
    return 3.14*(sok.promien_podstawy*sok.promien_podstawy)*sok.wysokosc;
}
void zapisz(ostream& wyjscie, SKarton& karton){
    wyjscie<<karton.ile_sokow<<endl;
    for(unsigned i=0;i<karton.ile_sokow;i++){
        wyjscie << karton.soki[i].wysokosc << " " << karton.soki[i].promien_podstawy << " " << karton.soki[i].marka << "\n";
    }
}
double daj_wysokosc(SKarton& karton){
    double h=0;
    for(unsigned i = 0; i < karton.ile_sokow; i++){
        if(h<karton.soki[i].wysokosc){
            h=karton.soki[i].wysokosc;
        }
    }
    return h;
}
double daj_objetosc(SKarton& karton){
    double obj=0;
    for(unsigned i=0;i<karton.ile_sokow;i++){
        obj+=zwroc_objetosc(karton.soki[i]);
    }
    return obj;
}
void usun(SSok* soki){
    if(soki!=nullptr){
        delete [] soki;
        soki = nullptr;
    }
}
int main(int argc, char** argv){
    if(argc!=3){
        cerr<<"Bledna ilosc parametrow. Podaj nazwaProgramy wejscie.txt wyjscie.txt\n";
        return -1;
    }
    unsigned rozmiar=0;
    ifstream wejsciowy(argv[1]);
    if(!wejsciowy.good()){
        cout<<"Blad otwarcia pliku wejsciowego.\n";
        wejsciowy.clear();
        wejsciowy.ignore();
        wejsciowy.close();
        return -1;
    }
    SSok* soki=wczytaj(wejsciowy,rozmiar);
    wejsciowy.clear();
    wejsciowy.ignore();
    wejsciowy.close();
    SKarton karton;
    pakuj_karton(karton,soki,rozmiar);
    wypisz(karton,cout);
    ofstream wyjscie(argv[2]);
    if(!wyjscie.good()){
        cout << "Blad otwarcia pliku wyjsciowego.\n";
        wejsciowy.clear();
        wejsciowy.close();
        return -1;
    }
    zapisz(wyjscie,karton);
    cout<<"\n\n\n";
    cout << "Wysokosc kartonu: " << daj_wysokosc(karton)<<endl ;
    cout << "\n\n\n";
    cout << "Objetosc kartonu: " << daj_objetosc(karton)<<endl ;
    cout << "\n\n\n";
    wejsciowy.clear();  
    wejsciowy.close();
    usun(soki);
    return 0;
}