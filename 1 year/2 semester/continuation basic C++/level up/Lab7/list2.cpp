#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct SAuto{
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
};
void inicjuj(SAuto& mojNowyCar, string& marka, string& model, string& kolor, unsigned int& liczbaDrzwi, unsigned int& KM, float& pojemnoscSilnika){
    mojNowyCar={marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika};
}
void inicjuj(SAuto* mojNowyCar, string& marka, string& model, string& kolor, unsigned int& liczbaDrzwi, unsigned int& KM, float& pojemnoscSilnika){
    *mojNowyCar={marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika};
}
bool spr(ifstream& fin){
    if(!fin.good()){
        cout<<"Nie udalo sie otworzyc pliku.\n";
        fin.clear();
        return false;
    }
    cout<<"Poprawnie otwarto plik. \n";
    return true;
}
bool spr(ofstream& fin){
    if(!fin.good()){
        cout<<"Nie udalo sie otworzyc pliku.\n";
        fin.clear();
        return false;
    }
    cout<<"Poprawnie otwarto plik. \n";
    return true;
}
bool spr(string nazwaPliczku){
    ifstream fin;
    fin.open(nazwaPliczku);
    if(!fin.good()){
        cout<<"Nie udalo sie otworzyc pliku.\n";
        fin.clear();
        return false;
    }
    cout<<"Poprawnie otwarto plik. \n";
    return true;
}
void zapis(SAuto& mojNowyCar){
    cout<<"Marka twojego samochodu: "<<mojNowyCar.marka<<endl;
    cout<<"Model twojego samochodu: "<<mojNowyCar.model<<endl;
    cout<<"Kolor twojego samochodu: "<<mojNowyCar.kolor<<endl;
    cout<<"Liczba drzwi w twoim samochodzie: "<<mojNowyCar.liczbaDrzwi<<endl;
    cout<<"Liczba koni mechanicznych w twoim samochodzie: "<<mojNowyCar.KM<<endl;
    cout<<"Pojemnosc silnika w twoim samochodzie: "<<mojNowyCar.pojemnoscSilnika<<endl;
    cout<<endl;
}
void zapis(SAuto* mojNowyCar){
    cout<<"Marka twojego samochodu: "<<mojNowyCar->marka<<endl;
    cout<<"Model twojego samochodu: "<<mojNowyCar->model<<endl;
    cout<<"Kolor twojego samochodu: "<<mojNowyCar->kolor<<endl;
    cout<<"Liczba drzwi w twoim samochodzie: "<<mojNowyCar->liczbaDrzwi<<endl;
    cout<<"Liczba koni mechanicznych w twoim samochodzie: "<<mojNowyCar->KM<<endl;
    cout<<"Pojemnosc silnika w twoim samochodzie: "<<mojNowyCar->pojemnoscSilnika<<endl;
    cout<<endl;
}
void zapis(SAuto& mojNowyCar, ofstream& fout){
    fout<<"Marka twojego samochodu: "<<mojNowyCar.marka<<endl;
    fout<<"Model twojego samochodu: "<<mojNowyCar.model<<endl;
    fout<<"Kolor twojego samochodu: "<<mojNowyCar.kolor<<endl;
    fout<<"Liczba drzwi w twoim samochodzie: "<<mojNowyCar.liczbaDrzwi<<endl;
    fout<<"Liczba koni mechanicznych w twoim samochodzie: "<<mojNowyCar.KM<<endl;
    fout<<"Pojemnosc silnika w twoim samochodzie: "<<mojNowyCar.pojemnoscSilnika<<endl;
    fout<<endl;
}
void zapis(SAuto* mojNowyCar, ofstream& fout){
    fout<<"Marka twojego samochodu: "<<mojNowyCar->marka<<endl;
    fout<<"Model twojego samochodu: "<<mojNowyCar->model<<endl;
    fout<<"Kolor twojego samochodu: "<<mojNowyCar->kolor<<endl;
    fout<<"Liczba drzwi w twoim samochodzie: "<<mojNowyCar->liczbaDrzwi<<endl;
    fout<<"Liczba koni mechanicznych w twoim samochodzie: "<<mojNowyCar->KM<<endl;
    fout<<"Pojemnosc silnika w twoim samochodzie: "<<mojNowyCar->pojemnoscSilnika<<endl;
    fout<<endl;
}
void zapis(SAuto& mojNowyCar, string plikWyjsciowy){
    ofstream fout;
    fout.open(plikWyjsciowy, ios::app);
    bool pom=spr(plikWyjsciowy);
    if(pom==true)
    {
        fout<<"Marka twojego samochodu: "<<mojNowyCar.marka<<endl;
        fout<<"Model twojego samochodu: "<<mojNowyCar.model<<endl;
        fout<<"Kolor twojego samochodu: "<<mojNowyCar.kolor<<endl;
        fout<<"Liczba drzwi w twoim samochodzie: "<<mojNowyCar.liczbaDrzwi<<endl;
        fout<<"Liczba koni mechanicznych w twoim samochodzie: "<<mojNowyCar.KM<<endl;
        fout<<"Pojemnosc silnika w twoim samochodzie: "<<mojNowyCar.pojemnoscSilnika<<endl;
        fout<<endl;
    }
}
void zapis(SAuto* mojNowyCar, string plikWyjsciowy){
    ofstream fout;
    fout.open(plikWyjsciowy, ios::app);
    bool pom=spr(plikWyjsciowy);
    if(pom==true)
    {
    fout<<"Marka twojego samochodu: "<<mojNowyCar->marka<<endl;
    fout<<"Model twojego samochodu: "<<mojNowyCar->model<<endl;
    fout<<"Kolor twojego samochodu: "<<mojNowyCar->kolor<<endl;
    fout<<"Liczba drzwi w twoim samochodzie: "<<mojNowyCar->liczbaDrzwi<<endl;
    fout<<"Liczba koni mechanicznych w twoim samochodzie: "<<mojNowyCar->KM<<endl;
    fout<<"Pojemnosc silnika w twoim samochodzie: "<<mojNowyCar->pojemnoscSilnika<<endl;
    fout<<endl;
    }
}
void pobierz(SAuto& mojNowyCar){
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
    cout<<"Marka twojego samochodu: "<<endl;
    cin>>marka;
    cout<<"Model twojego samochodu: "<<endl;
    cin>>model;
    cout<<"Kolor twojego samochodu: "<<endl;
    cin>>kolor;
    cout<<"Liczba drzwi w twoim samochodzie: "<<endl;
    cin>>liczbaDrzwi;
    cout<<"Liczba koni mechanicznych w twoim samochodzie: "<<endl;
    cin>>KM;
    cout<<"Pojemnosc silnika w twoim samochodzie: "<<endl;
    cin>>pojemnoscSilnika;
    inicjuj(mojNowyCar, marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika);
}
void pobierz(SAuto* mojNowyCar){
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
    cout<<"Marka twojego samochodu: "<<endl;
    cin>>marka;
    cout<<"Model twojego samochodu: "<<endl;
    cin>>model;
    cout<<"Kolor twojego samochodu: "<<endl;
    cin>>kolor;
    cout<<"Liczba drzwi w twoim samochodzie: "<<endl;
    cin>>liczbaDrzwi;
    cout<<"Liczba koni mechanicznych w twoim samochodzie: "<<endl;
    cin>>KM;
    cout<<"Pojemnosc silnika w twoim samochodzie: "<<endl;
    cin>>pojemnoscSilnika;
    inicjuj(mojNowyCar, marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika);
}
void pobierz(SAuto& mojNowyCar, ifstream& fin){
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
    fin>>marka;
    fin>>model;
    fin>>kolor;
    fin>>liczbaDrzwi;
    fin>>KM;
    fin>>pojemnoscSilnika;
    inicjuj(mojNowyCar, marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika);
}
void pobierz(SAuto* mojNowyCar, ifstream& fin){
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
    fin>>marka;
    fin>>model;
    fin>>kolor;
    fin>>liczbaDrzwi;
    fin>>KM;
    fin>>pojemnoscSilnika;
    inicjuj(mojNowyCar, marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika);
}
void pobierz(SAuto& mojNowyCar, string nazwaPliczku){
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
    ifstream fin;
    fin.open(nazwaPliczku);
    bool pom=spr(fin);
    if(pom==true)
    {
        fin>>marka;
        fin>>model;
        fin>>kolor;
        fin>>liczbaDrzwi;
        fin>>KM;
        fin>>pojemnoscSilnika;
        inicjuj(mojNowyCar, marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika);
    }    
}
void pobierz(SAuto* mojNowyCar, string nazwaPliczku){
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
    ifstream fin;
    fin.open(nazwaPliczku);
    bool pom=spr(fin);
    if(pom==true)
    {
    fin>>marka;
    fin>>model;
    fin>>kolor;
    fin>>liczbaDrzwi;
    fin>>KM;
    fin>>pojemnoscSilnika;
    inicjuj(mojNowyCar, marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika);
    }
}
int main(int argc, char* argv[]){
    if(argc != 3){
        cerr<<"Bledna ilosc argumentow. Poprawnie wpisz : nazwaProgramu.exe nazwaPlikuDoWczytania.txt nazwaPlikuDoZapisania.txt";
        return -1;
    }
    SAuto mojNowyCar;
    pobierz(mojNowyCar);
    zapis(mojNowyCar);
    pobierz(&mojNowyCar);
    zapis(&mojNowyCar);
    ifstream fin;
    fin.open(argv[1]);
    ofstream fout;
    fout.open(argv[2], ios::app);
    bool pom1=spr(fout);
    bool pom=spr(fin);
    if(pom==true && pom1==true){
        pobierz(mojNowyCar,fin); 
        zapis(mojNowyCar,fout);
        pobierz(&mojNowyCar,fin);
        zapis(&mojNowyCar,fout);
        fin.close();
        fout.close();
    } 
    string plikWejsciowy = "in.txt";
    string plikWyjsciowy = "out.txt";
    pobierz(mojNowyCar,plikWejsciowy); 
    zapis(mojNowyCar,plikWyjsciowy);
    pobierz(&mojNowyCar,plikWejsciowy);
    zapis(&mojNowyCar,plikWyjsciowy);
    return 0;
}