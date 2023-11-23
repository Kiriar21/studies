#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct SStundet{
    string imie,nazwisko;
    int nr_ideksu,grupa_dz,grupa_lab,liczbaNiezaliczonych;
    string* niezaliczone;
};
struct SLista{
    string nazwa;
    unsigned ilosc;
    SStundet* studenci;
};
SLista wczytaj(ifstream& fin){
    SLista lista;
    fin>>lista.nazwa>>lista.ilosc;
    if(lista.ilosc>0){
        lista.studenci = new SStundet[lista.ilosc];
        for(unsigned i=0;i<lista.ilosc;i++){
            fin >> lista.studenci[i].imie >> lista.studenci[i].nazwisko >> lista.studenci[i].nr_ideksu >> lista.studenci[i].grupa_dz >> lista.studenci[i].grupa_lab >> lista.studenci[i].liczbaNiezaliczonych;
            if(lista.studenci[i].liczbaNiezaliczonych>0){
                lista.studenci[i].niezaliczone = new string[lista.studenci[i].liczbaNiezaliczonych];
                for(int j=0;j<lista.studenci[i].liczbaNiezaliczonych;j++){
                    fin>>lista.studenci[i].niezaliczone[j];
                }
            }
        }
    }
    return lista;
}
void wypisz(SStundet& st,ostream& jak){
    jak<<st.imie<<" "<<st.nazwisko<<"\n";
    jak<<"Nr indeksu: "<<st.nr_ideksu<<" Gr Dz: "<<st.grupa_dz<<" Gr Lab: "<<st.grupa_lab<<endl;
    jak<<"Ilosc niezaliczonych przedmiotow: "<<st.liczbaNiezaliczonych<<endl;
    if(st.liczbaNiezaliczonych>0){
        for(int i=0;i<st.liczbaNiezaliczonych;i++){
            jak<<st.niezaliczone[i]<<"\t";
        }
        jak<<endl;
    }
}
void wypisz(SLista* lista, ostream& jak){
    for(unsigned i=0;i<lista->ilosc;i++){
        wypisz(lista->studenci[i],jak);
    }
}
void filtr(ofstream& fout, SLista& lista, string slowoFiltr="Podstawy_Programowania"){
    for(unsigned i=0;i<lista.ilosc;i++){
        if(lista.studenci[i].liczbaNiezaliczonych>0){
            for(int j=0;j<lista.studenci[i].liczbaNiezaliczonych;j++){ 
                if(lista.studenci[i].niezaliczone[j]==slowoFiltr) break;
                fout << lista.studenci[i].imie << " " << lista.studenci[i].nazwisko << endl;
            }
        }
        else{
            fout<<lista.studenci[i].imie<<" "<<lista.studenci[i].nazwisko<<endl;
        }
    }
}
double srednia(SLista& lista){
    double sr=0;
    for(unsigned i=0;i<lista.ilosc;i++){
        sr+=lista.studenci[i].liczbaNiezaliczonych;
    }
    return sr/(double)lista.ilosc;
}
void wyszukaj(SLista& lista){
    int maxNiezal=lista.studenci[0].liczbaNiezaliczonych,index=0;
    for (unsigned i = 1; i < lista.ilosc; i++)
    {
        if(maxNiezal<lista.studenci[i].liczbaNiezaliczonych){
            maxNiezal=lista.studenci[i].liczbaNiezaliczonych;
            index=i;   
        }
    }
    cout<<"Najwiecej niezaliczonych przedmiow w ilosci: "<<maxNiezal<<" ma osoba o imieniu:"<<lista.studenci[index].imie<<" "<<lista.studenci[index].nazwisko<<endl;
}
bool wg_nazwiska(SStundet malejaco, SStundet rosnaco){
    return malejaco.nazwisko>rosnaco.nazwisko;
}
bool wg_imienia(SStundet malejaco, SStundet rosnaco){
    return malejaco.imie>rosnaco.imie;
}
bool wg_indeksu(SStundet malejaco, SStundet rosnaco){
    return malejaco.nr_ideksu>rosnaco.nr_ideksu;
}
bool wg_grupyL(SStundet malejaco, SStundet rosnaco){
    return malejaco.grupa_lab>rosnaco.grupa_lab;
}
bool wg_grupyD(SStundet malejaco, SStundet rosnaco){
    return malejaco.grupa_dz>rosnaco.grupa_dz;
}
bool wg_liczbyK(SStundet malejaco, SStundet rosnaco){
    return malejaco.liczbaNiezaliczonych>rosnaco.liczbaNiezaliczonych;
}
void sortuj(ostream& jak, SLista& lista, bool (*funkcjaOrzekajaca)(SStundet malejaco, SStundet rosnaco), string jakPosort){
    sort(lista.studenci, lista.studenci + lista.ilosc, funkcjaOrzekajaca);
    jak<<"Sortowanie: "<<jakPosort<<endl;
    for(unsigned i=0;i<lista.ilosc;i++){
        wypisz(lista.studenci[i],jak);
    }
    jak<<endl;
}
void usun(SLista& lista){
    if(lista.studenci!=nullptr){
        for(unsigned i=0;i<lista.ilosc;i++){
            if(lista.studenci[i].liczbaNiezaliczonych>0){
                delete [] lista.studenci[i].niezaliczone;
                lista.studenci[i].niezaliczone=nullptr;
            }
        }
        delete [] lista.studenci;
        lista.studenci=nullptr;
    }
}

int main(int argc,char** argv){
    if (argc != 3)
    {
        cerr << "nazwa fin fout\n";
        return -1;
    }
    ifstream fin(argv[1]);
    if (!fin.good())
    {
        cout << "Blad wejsciowego.\n";
        fin.clear();
        fin.ignore();
        fin.close();
        return -1;
    }
    SLista lista=wczytaj(fin);
    fin.clear();
    fin.ignore();
    fin.close();
    ofstream fout(argv[2], ios::app);
    if (!fout.good())
    {
        cout << "Blad wyjsciowego.\n";
        fout.clear();
        fout.close();
        return -1;
    }
    wypisz(&lista,cout);
    filtr(fout,lista);
    cout<<"Srednia niezaliczonych przedmiotow: "<<srednia(lista)<<endl;
    wyszukaj(lista);
    sortuj(fout,lista,wg_nazwiska,"wg_nazwiska");
    sortuj(fout,lista,wg_imienia,"wg_imienia");
    sortuj(fout,lista,wg_indeksu,"wg_indeksu");
    sortuj(fout,lista,wg_grupyL,"wg_grupyL");
    sortuj(fout,lista,wg_grupyD,"wg_grupyD");
    sortuj(fout,lista,wg_liczbyK,"wg_liczbyK");
    fout.clear();
    fout.close();
    usun(lista);
    return 0;
}