#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct SStudent{
    string imie;
    string nazwisko;
    unsigned numerIndeksu;
    unsigned grupaDziekanska;
    unsigned grupaLaboratoryjna;
    unsigned liczbaNiezaliczone;
    string wykazNiezaliczone;
};

struct SLista{
    string nazwa;
    unsigned liczbaStudentow;
    SStudent* listaStudentow;
};

bool wczytaj(const string nazwa, SLista& listyStudentow){
    ifstream plikWejsciowy(nazwa);
    if(!plikWejsciowy.good()){
        cerr<<"Blad otwarcia pliku. nazwaProgramu nazwaPlikuWejsciowe nazwaPlikuWyjsciowego \n";
        plikWejsciowy.close();
        return 0;
    }
    else{
        plikWejsciowy>>listyStudentow.nazwa>>listyStudentow.liczbaStudentow;
        listyStudentow.listaStudentow = new SStudent[listyStudentow.liczbaStudentow];
        for(unsigned i=0;i<listyStudentow.liczbaStudentow;i++){
            plikWejsciowy>>listyStudentow.listaStudentow[i].imie>>listyStudentow.listaStudentow[i].nazwisko;
            plikWejsciowy>>listyStudentow.listaStudentow[i].numerIndeksu>>listyStudentow.listaStudentow[i].grupaDziekanska>>listyStudentow.listaStudentow[i].grupaLaboratoryjna;
            plikWejsciowy>>listyStudentow.listaStudentow[i].liczbaNiezaliczone;
            if(listyStudentow.listaStudentow[i].liczbaNiezaliczone>0) getline(plikWejsciowy,listyStudentow.listaStudentow[i].wykazNiezaliczone);
        }
        for(unsigned i=0;i<listyStudentow.liczbaStudentow;i++){
            cout<<i+1<<". "<<listyStudentow.listaStudentow[i].imie<<" "<<listyStudentow.listaStudentow[i].nazwisko<<"\n";
        }
        plikWejsciowy.close();
        return 1;
    }        
}
void wypisz(ostream& plikWyjsciowy, SLista& listyStudentow, const unsigned ktoryStudent){
    if(plikWyjsciowy.good()){
       plikWyjsciowy<<listyStudentow.listaStudentow[ktoryStudent-1].imie<<" "<<listyStudentow.listaStudentow[ktoryStudent-1].nazwisko<<endl;
       plikWyjsciowy<<"Numer indeksu: "<<listyStudentow.listaStudentow[ktoryStudent-1].numerIndeksu<<endl;
       plikWyjsciowy<<"Grupa dziekanska: "<<listyStudentow.listaStudentow[ktoryStudent-1].grupaDziekanska<<" , grupa laboratoryjna: "<<listyStudentow.listaStudentow[ktoryStudent-1].grupaLaboratoryjna<<endl;
       plikWyjsciowy<<"Liczba niezaliczonych przedmiotow: "<<listyStudentow.listaStudentow[ktoryStudent-1].liczbaNiezaliczone<<endl;
       if(listyStudentow.listaStudentow[ktoryStudent-1].liczbaNiezaliczone>0) plikWyjsciowy<<"Wykaz niezaliczonych przedmitow: "<<listyStudentow.listaStudentow[ktoryStudent-1].wykazNiezaliczone<<endl;
    }
    plikWyjsciowy<<endl<<endl;
}

bool wypisz(ostream& plikWyjsciowy, SLista& listyStudentow){
    for(unsigned i=1;i<listyStudentow.liczbaStudentow;i++){
    wypisz(plikWyjsciowy,listyStudentow,i);
    }
    return 1;
}

void filtr(SLista& lista, ofstream& plikWyjsciowy){
    plikWyjsciowy<<"Lista studentow ktorzy nie zdali z Podstaw Programowania:\n";
    for(unsigned i=0;i<lista.liczbaStudentow;i++){
        string dane=lista.listaStudentow[i].wykazNiezaliczone;
        string nazwa = "Podstawy_Programowania";
        size_t czyJest = dane.find(nazwa);
        if(czyJest==1){
            plikWyjsciowy<<"\n\n";
            plikWyjsciowy<<lista.listaStudentow[i].imie<<" "<<lista.listaStudentow[i].nazwisko<<endl;
        }
    }
    plikWyjsciowy<<endl<<endl;
}

double srednia(SLista& lista){
    double suma=0;
    for(unsigned i=0;i<lista.liczbaStudentow;i++){
        suma+=lista.listaStudentow[i].liczbaNiezaliczone;
    }
    double srednia=suma/lista.liczbaStudentow;
    return srednia;
}

void wyszukaj(SLista& lista){
    unsigned max=lista.listaStudentow[0].liczbaNiezaliczone;
    for(unsigned i=1;i<lista.liczbaStudentow;i++){
        if(max<lista.listaStudentow[i].liczbaNiezaliczone){
            max=lista.listaStudentow[i].liczbaNiezaliczone;
        }
    }
    cout<<"Osoba z najwieksza liczba niezaliczonych przedmiotw:\n";
    cout<<lista.listaStudentow[max].imie<<" "<<lista.listaStudentow[max].nazwisko<<endl;
    cout<<lista.listaStudentow[max].numerIndeksu<<endl;
    cout<<"Grupa dziekanska: "<<lista.listaStudentow[max].grupaDziekanska<<", grupa laboratoryjna: "<<lista.listaStudentow[max].grupaLaboratoryjna<<endl;
}

bool wg_nazwiska(SStudent rosnaco,SStudent malejaco){
    return rosnaco.nazwisko<malejaco.nazwisko;
} 

bool wg_imie(SStudent rosnaco,SStudent malejaco){
    return rosnaco.imie<malejaco.imie;
} 

bool wg_indeksu(SStudent rosnaco,SStudent malejaco){
    return rosnaco.numerIndeksu<malejaco.numerIndeksu;
} 

bool wg_grupyL(SStudent rosnaco,SStudent malejaco){
    return rosnaco.grupaLaboratoryjna<malejaco.grupaLaboratoryjna;
} 

bool wg_grupyDz(SStudent rosnaco,SStudent malejaco){
    return rosnaco.grupaDziekanska<malejaco.grupaDziekanska;
} 

bool wg_liczbyK(SStudent rosnaco,SStudent malejaco){
    return rosnaco.liczbaNiezaliczone<malejaco.liczbaNiezaliczone;
} 

void sortowanie(ostream& plikWyjsciowy, SLista& listaStudentow, const unsigned liczbaS, bool (*funkcjaOrzekajaca)(SStudent rosnoca, SStudent malejaco), string tekst){
    sort(listaStudentow.listaStudentow,listaStudentow.listaStudentow+liczbaS,funkcjaOrzekajaca);
    plikWyjsciowy<<"Sortowanie "<<tekst<<endl<<endl;
    for(unsigned i=1;i<listaStudentow.liczbaStudentow+1;i++){
    wypisz(plikWyjsciowy,listaStudentow,i);
    }
    plikWyjsciowy<<endl<<endl;
}

void usun(SLista& lista){
    if(lista.listaStudentow!=0){
        delete [] lista.listaStudentow;
    }
}

int main(int argc, char* argv[]){
    SLista lista;
    if(wczytaj(argv[1],lista)){
        const unsigned liczbaS = lista.liczbaStudentow;
        unsigned ktoryStudent=0;
        cout<<"\n\nPodaj ktorego studenta chcesz zobaczyc: \n";
        cin>>ktoryStudent;
        wypisz(cout,lista,ktoryStudent);
        cout<<"\n\n";
        ofstream plikWyjsciowy(argv[2]);
        plikWyjsciowy<<lista.nazwa<<endl<<endl;
        wypisz(plikWyjsciowy,lista);
        filtr(lista,plikWyjsciowy);
        cout<<"Srednia liczba niezaliczonych przedmiotow przez studentow: "<<srednia(lista)<<endl;
        wyszukaj(lista);
        sortowanie(plikWyjsciowy, lista, liczbaS, wg_nazwiska, "wg_nazwiska" );
        sortowanie(plikWyjsciowy, lista, liczbaS, wg_imie, "wg_imie");
        sortowanie(plikWyjsciowy, lista, liczbaS, wg_indeksu, "wg_indeksu");
        sortowanie(plikWyjsciowy, lista, liczbaS, wg_grupyL, "wg_grupyL");
        sortowanie(plikWyjsciowy, lista, liczbaS, wg_grupyDz, "wg_grupyDz");
        sortowanie(plikWyjsciowy, lista, liczbaS, wg_liczbyK, "wg_liczbyK");
        plikWyjsciowy.close();        
    }
    else cout<<"Blad uzycia programu.\n";
    return 0;
}