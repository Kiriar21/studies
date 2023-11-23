#include <iostream>
#include <fstream>
using namespace std;
struct SObiektyw{
    string rodzaj_obiektywu;
    float przeslona;
    unsigned ogniskowa;
};
struct SAparat{
    string nazwa_aparatu;
    unsigned ilosc;
    SObiektyw* obiektywy;
};
bool wczytaj(const string fin1,SAparat& aparat){
    ifstream fin(fin1);
    if(!fin.good()){
        cout << "Blad otwarcia pliku wejsciowego.\n";
        fin.clear();
        fin.ignore();
        fin.close();
    }
    fin>>aparat.nazwa_aparatu>>aparat.ilosc;
    if(aparat.ilosc>0){
        aparat.obiektywy = new SObiektyw[aparat.ilosc];
        for(unsigned i=0;i<aparat.ilosc;i++){
            fin>>aparat.obiektywy[i].rodzaj_obiektywu>>aparat.obiektywy[i].przeslona>>aparat.obiektywy[i].ogniskowa;
        }
        fin.clear();
        fin.ignore();
        fin.close();
        return true;
    }
    return false;
}
void wypisz(ostream& jak,SAparat ap){
    jak<<ap.nazwa_aparatu<<endl;
    jak<<ap.ilosc<<endl;
    for(unsigned i=0;i<ap.ilosc;i++){
        jak<<ap.obiektywy[i].rodzaj_obiektywu<<endl;
        jak<<ap.obiektywy[i].przeslona<<" : "<<ap.obiektywy[i].ogniskowa<<endl;
    }
}
int zlicz(SAparat& ap){
    int ilosc=0;
    for(unsigned i=0;i<ap.ilosc;i++){
        if(ap.obiektywy[i].ogniskowa>50) ilosc++;
    }
    return ilosc;
}
void usun(SAparat& aparat){
    if(aparat.obiektywy!=nullptr){
        delete [] aparat.obiektywy;
        aparat.obiektywy=nullptr;
    }
}
int main(int argc,char** argv){
    if(argc!=3){
        cerr<<"nazwa fin fout\n";
        return -1;
    }
    SAparat aparat;
    if (wczytaj(argv[1], aparat))
    {
        wypisz(cout, aparat);
        cout << zlicz(aparat);
        ofstream plik(argv[2]);
        if (!plik)
            cerr << "Zapis zakonczony bledem";
        else
            wypisz(plik, aparat);
        plik.clear();
        plik.close();
        usun(aparat);
    }

    return 0;
}