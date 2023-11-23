#include <iostream>
#include <fstream>

using namespace std;

struct SOsoba{
    string imie;
    unsigned rok;
    string znak;
    unsigned liczba;
};

SOsoba* wczytaj(ifstream& fin, size_t& ilosc){
    fin>>ilosc;
    SOsoba* osoby = new SOsoba[ilosc];
    for(unsigned int i=0;i<ilosc;i++){
        fin>>osoby[i].imie>>osoby[i].rok>>osoby[i].znak>>osoby[i].liczba;
    }
    return osoby;
}
void usun(SOsoba* osoby){
    if(osoby!=nullptr){
        delete [] osoby;
        osoby = nullptr;
    }
}
void wypisz(ostream& jak,SOsoba& os){
    jak<<"Imie: "<<os.imie<<" rok urodzenia: "<<os.rok<<" znak zodiaku: "<<os.znak<<" szczesliwa liczba: "<<os.liczba<<endl;
}
void wypisz(ostream& jak,SOsoba* os, const size_t ilosc){
    for(size_t i=0;i<ilosc;i++){
        wypisz(jak,os[i]);
    }
}
SOsoba szukaj(const string znak, SOsoba* os, const size_t ilosc){
    SOsoba osoba={"brak",0,"brak",0};
    for (size_t i = 0; i < ilosc; i++)
    {
        if(os[i].znak==znak){
            osoba=os[i];
            break;
        }
    }
    return osoba;
}
void podzial(ostream& jak, ostream& jak1, SOsoba* os, const size_t ilosc){
    jak<<"Kobiety: "<<endl;
    jak1<<"Kobiety: "<<endl;
    for(size_t i=0;i<ilosc;i++){
        int dl=os[i].imie.length();
        if(os[i].imie[dl-1]=='a'){
            wypisz(jak,os[i]);
            wypisz(jak1,os[i]);
        }
    }
    jak << "\n\nMezczyzni: " << endl;
    jak1 << "\n\nMezczyzni: " << endl;
    for (size_t i = 0; i < ilosc; i++)
    {
        int dl = os[i].imie.length();
        if (os[i].imie[dl - 1] != 'a')
        {
            wypisz(jak, os[i]);
            wypisz(jak1, os[i]);
        }
    }
}
void podzial(SOsoba* osoby, const size_t ilosc){
    cout<<"Osoby ze szczesliwym numerem parzystym:\n";
    for (size_t i = 0; i < ilosc; i++)
    {
        if(osoby[i].liczba%2==0){
            wypisz(cout,osoby[i]);
        }
    }
}
int main(int argc, char **argv)
{
    if(argc!=4){
        cerr<<"Podaj nazwaPliku plikWejsciowy plikWyjsciowy znakZodiaku\n";
        return -1;
    }
    size_t ilosc=0;
    ifstream fin(argv[1]);
    if(!fin.good()){
        cout<<"Blad otwarcia pliku wejsciowego.\n";
        fin.clear();
        fin.ignore();
        fin.close();
        return -1;
    }
    SOsoba* osoby = wczytaj(fin,ilosc);
    fin.clear();
    fin.ignore();
    fin.close();

    ofstream fout(argv[2],ios::app);
    if(!fout.good()){
        cout << "Blad otwarcia pliku wyjsciowego.\n";
        fout.clear();
        fout.close();
        return -1;
    }
    wypisz(cout,osoby,ilosc);

    SOsoba zeZnakiem=szukaj(argv[3],osoby,ilosc);
    cout<<"Osoba znaleziona ze znakiem: "<<argv[3]<<endl;
    wypisz(cout,zeZnakiem);
    cout<<endl;
    podzial(cout,fout,osoby,ilosc);
    podzial(osoby,ilosc);
    fout.clear();
    fout.close();
    usun(osoby);
    return 0;
}