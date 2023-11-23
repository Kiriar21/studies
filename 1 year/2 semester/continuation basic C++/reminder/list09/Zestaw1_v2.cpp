#include <iostream>
#include <fstream>
using namespace std;
struct SMieszkanie{
    unsigned numerMieszkania,liczbaPokoi;
    double powierzchnia, wysokosc;
};
struct SPietro{
    unsigned numerPietra, liczbaMieszkan;
    SMieszkanie* tablicaMieszkania;
};
struct SKlatka{
    unsigned numerKlatki, liczbaPieter;
    SPietro* tablicaPieter;
};
struct SBlok{
    unsigned numerBloku;
    string nazwaUlicy;
    unsigned liczbaKlatek;
    SKlatka* tablicaKlatek;
};
void wczytaj(string nazwaPlikuWejsciowego, SBlok& blok){
    ifstream fin(nazwaPlikuWejsciowego);
    if(!fin.good()){
        cout<<"Niestety nie udalo sie otworzyc pliku wejsciowego.\n";
        fin.clear();
        fin.ignore();
        fin.close();
        exit(0);
    }
    fin>>blok.nazwaUlicy>>blok.numerBloku>>blok.liczbaKlatek;
    if(blok.liczbaKlatek>0){
        blok.tablicaKlatek = new SKlatka[blok.liczbaKlatek];
        for(unsigned i=0;i<blok.liczbaKlatek;i++){
            fin>>blok.tablicaKlatek[i].numerKlatki>>blok.tablicaKlatek[i].liczbaPieter;
            if(blok.tablicaKlatek[i].liczbaPieter>0){
                blok.tablicaKlatek[i].tablicaPieter = new SPietro[blok.tablicaKlatek[i].liczbaPieter];
                 for(unsigned j=0;j<blok.tablicaKlatek[i].liczbaPieter;j++){
                    fin >> blok.tablicaKlatek[i].tablicaPieter[j].numerPietra;
                    fin >> blok.tablicaKlatek[i].tablicaPieter[j].liczbaMieszkan;
                    if (blok.tablicaKlatek[i].tablicaPieter[j].liczbaMieszkan>0){
                        blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania = new SMieszkanie[blok.tablicaKlatek[i].tablicaPieter[j].liczbaMieszkan];
                        for(unsigned k=0;k<blok.tablicaKlatek[i].tablicaPieter[j].liczbaMieszkan;k++){
                            fin>>blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].numerMieszkania;
                            fin>>blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].powierzchnia;
                            fin>>blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].wysokosc;
                            fin>>blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].liczbaPokoi;
                        }
                    }
                }
            }
        }
    }
    fin.clear();
    fin.ignore();
    fin.close();
}
void zapisz(ostream& plikWyjsciowy, SBlok& blok){
    plikWyjsciowy<<"Ulica: "<<blok.nazwaUlicy<<" Numer: "<<blok.numerBloku<<endl;
    plikWyjsciowy<<"Liczba klatek: "<<blok.liczbaKlatek<<endl;
    for(unsigned i=0;i<blok.liczbaKlatek;i++){
        plikWyjsciowy<<"-----------------------------------------------------------------------------------------------------------------\n";
        plikWyjsciowy<<endl<<i+1<<" Klatka: "<<endl<<endl;
        plikWyjsciowy<<"Numer klatki: "<<blok.tablicaKlatek[i].numerKlatki<<" Liczba pieter na klatce: "<<blok.tablicaKlatek[i].liczbaPieter<<endl;
        for(unsigned j=0;j<blok.tablicaKlatek[i].liczbaPieter;j++){
            plikWyjsciowy << "-----------------------------------------------------------------------------------------------------------------\n";
            plikWyjsciowy<<endl<<i+1<<" Pietro: "<<endl<<endl;
            plikWyjsciowy<<"Numer pietra: "<<blok.tablicaKlatek[i].tablicaPieter[j].numerPietra<<" Liczba mieszkan: "<<blok.tablicaKlatek[i].tablicaPieter[j].liczbaMieszkan;
            for(unsigned k=0;k<blok.tablicaKlatek[i].tablicaPieter[j].liczbaMieszkan;k++){
                plikWyjsciowy<<endl<<k+1<<" Mieszkanie: "<<endl<<endl;
                plikWyjsciowy << "Numer mieszkania: " << blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].numerMieszkania << " z liczba pokoi: " << blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].liczbaPokoi<<endl;
                plikWyjsciowy << " Powierzchnia tego mieszkania to: " << blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].powierzchnia << " o wysokosci: " << blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].wysokosc<<endl;
            }
            plikWyjsciowy << "-----------------------------------------------------------------------------------------------------------------\n";
        }
        plikWyjsciowy << "-----------------------------------------------------------------------------------------------------------------\n";
    }
}
double wysokosc_pietra(SPietro& pietro){
    double wysokosc=0;
    for(unsigned i=0;i<pietro.liczbaMieszkan;i++){
        if(pietro.tablicaMieszkania[i].wysokosc>wysokosc){
            wysokosc=pietro.tablicaMieszkania[i].wysokosc;
        }
    }
    return wysokosc;
}
double wysokosc_klatki(SKlatka& klatka){
    double wysokosc=0;
    for(unsigned i=0;i<klatka.liczbaPieter;i++){
        wysokosc+=wysokosc_pietra(klatka.tablicaPieter[i]);
    }
    return wysokosc;
}
double wysokosc_bloku(SBlok& blok){
    double wysokosc=0;
    for(unsigned i=0;i<blok.liczbaKlatek;i++){
        double wysPietra = wysokosc_klatki(blok.tablicaKlatek[i]);
        if (wysokosc <wysPietra){
            wysokosc=wysPietra;
        }
    }
    return wysokosc;
}
double loft(SBlok& blok){
    double loft=0;
    for(unsigned i=0;i<blok.liczbaKlatek;i++){
        for(unsigned j=0;j<blok.tablicaKlatek[i].liczbaPieter;j++){
            for(unsigned k=0;k<blok.tablicaKlatek[i].tablicaPieter[j].liczbaMieszkan;k++){
                if(loft<blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].wysokosc){
                    loft = blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania[k].wysokosc;
                }
            }
        }
    }
    return loft;
}
void usun(SBlok& blok){
    if(blok.tablicaKlatek!=nullptr){
        for (unsigned i = 0; i < blok.liczbaKlatek; i++){
            if(blok.tablicaKlatek[i].tablicaPieter!=nullptr){
                for(unsigned j=0;j<blok.tablicaKlatek[i].liczbaPieter;j++){
                    delete [] blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania;
                    blok.tablicaKlatek[i].tablicaPieter[j].tablicaMieszkania=nullptr;
                }
            }
            delete[] blok.tablicaKlatek[i].tablicaPieter;
            blok.tablicaKlatek[i].tablicaPieter = nullptr;
        }
        delete[] blok.tablicaKlatek;
        blok.tablicaKlatek = nullptr;
    }
        
    
}
int main(int argc, char** argv){
    if(argc!=3){
        cerr<<"Bledna ilosc parametrow. Podaj nazwaProgramu plikWejsciowy.txt plikWyjsciowy.txt\n";
        return -1;
    }
    SBlok blok;
    wczytaj(argv[1],blok);
    ofstream plikWyjsciowy(argv[2]);
    if(!plikWyjsciowy.good()){
        cout<<"Blad otwarcia pliku wyjsciowego.\n";
        plikWyjsciowy.clear();
        plikWyjsciowy.close();
        return -1;
    }
    zapisz(cout,blok);
    zapisz(plikWyjsciowy,blok);
    cout<<"Wysokosc bloku to: "<<wysokosc_bloku(blok)<<endl;
    cout<<"Najwyzsze mieszkanie(loft) ma wysokosc: "<<loft(blok)<<endl;
    usun(blok);
    plikWyjsciowy.clear();
    plikWyjsciowy.close();
    return 0;
}