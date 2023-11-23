#include <iostream>
#include <fstream>
using namespace std;
unsigned wystapienia(istream& fin, const char* symbol){
    unsigned wyst=0;
    string tekst;
    while(!fin.eof()){
        fin>>tekst;
        size_t rozmiar=tekst.length();
        for(size_t i=0;i<rozmiar;i++){
            if(tekst[i]==symbol[0]) wyst++;
        }
    }
    return wyst;
}
void filtr(istream& fin,ostream& fout, const char* symbol, const unsigned int ile){

    string tekst;
    while(!fin.eof()){
        fin>>tekst;
        size_t rozmiar=tekst.length();
        unsigned wyst = 0;
        for(size_t i=0;i<rozmiar;i++){
            if(tekst[i]==symbol[0]) wyst++;
        }
        if(wyst==ile){
            fout<<tekst<<endl;
        }
    }
}
int main(int argc, char** argv){
    if(argc!=5){
        cout<<"Bledna ilosc parametrow. Podaj nazwaProgramu symnbol liczbaWystapien plikWejsciowy plikWyjsciowy\n";
        return -1;
    }
    ifstream fin(argv[3]);
    ofstream fout(argv[4]);
    if(!fin.good() || !fout.good()){
        cout<<"Blad podczas otwierania pliku wejsciowego/wyjsciowego.\n";
        exit(0);
    }
    cout<<"Liczba wystapien: "<<wystapienia(fin,argv[1])<<endl;
    fin.clear();
    fin.ignore();
    fin.close();
    fout.clear();
    fout.close();
    
    ifstream fin1(argv[3]);
    ofstream fout1(argv[4]);
    if (!fin1.good() || !fout1.good())
    {
        cout << "Blad podczas otwierania pliku wejsciowego/wyjsciowego.\n";
        exit(0);
    }
    filtr(fin1, fout1, argv[1], atoi(argv[2]));
    cout<<"Zapisano plik.\n";
    fin1.clear();
    fin1.ignore();
    fin1.close();
    fout1.clear();
    fout1.close();
    
    return 0;
}