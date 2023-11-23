#include <iostream>
#include <fstream>
using namespace std;
void zapisz_a(const string nazwaPliku){
    ofstream fout(nazwaPliku,ios::app);
    if (!fout.good())
    {
        cout << "Blad otwarcia pliku.\n";
        fout.clear();
        fout.close();
        exit(0);
    }
    for(int i=1;i<=10;i++){
        fout<<i<<". Hello World.\n";
    }
    fout.clear();
    fout.close();
}
void zapisz(const string nazwaPliku, const string tekst, const unsigned int i)
{
    ofstream fout(nazwaPliku, ios::app);
    if(!fout.good()){
        cout<<"Blad otwarcia pliku.\n";
        fout.clear();
        fout.close();
        exit(0);
    }
    for (unsigned int j = 0; j < i; j++)
    {
        fout << tekst<<endl;
    }
    fout.clear();
    fout.close();
}
void zapisz(ostream& fout, const string tekst, const unsigned int i){
    for(unsigned int j=0;j<i;j++){
        fout<<tekst<<endl;
    }
}
int main(int argc, char** argv){
    if(argc!=2){
        cout<<"Bledna ilosc parametrow. Podaj nazwaProgramu NazwaplikuWyjsciowego.txt\n";
        return -1;
    }
    string nazwaPliku=argv[1];
    zapisz_a(nazwaPliku);
    zapisz(nazwaPliku,"HelloW",3);
    ofstream fout(argv[1], ios::app);
    if(!fout.good()){
        cout << "Blad otwarcia pliku.\n";
        fout.clear();
        fout.close();
        exit(0);
    }
    zapisz(fout,"Hello!",3);
    fout.close();
    return 0;
}