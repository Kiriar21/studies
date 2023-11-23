#include <iostream>
#include <fstream>
using namespace std;
struct SAuto
{
    string marka, model, kolor;
    unsigned l_drzwi, moc;
    float poj_silnik;
};
SAuto inicjuj(string marka = "A", string model = "A", string kolor = "A", unsigned l_drzwi = 5, unsigned moc = 120, float poj_silnik = 1.0)
{
    SAuto element = {marka, model, kolor, l_drzwi, moc, poj_silnik};
    return element;
}
void inicjuj(SAuto &car, string marka = "B", string model = "B", string kolor = "B", unsigned l_drzwi = 5, unsigned moc = 120, float poj_silnik = 1.0)
{
    car.marka = marka;
    car.model = model;
    car.kolor = kolor;
    car.l_drzwi = l_drzwi;
    car.moc = moc;
    car.poj_silnik = poj_silnik;
}
void inicjuj(SAuto *car, string marka = "C", string model = "C", string kolor = "C", unsigned l_drzwi = 5, unsigned moc = 120, float poj_silnik = 1.0)
{
    car->marka = marka;
    car->model = model;
    car->kolor = kolor;
    car->l_drzwi = l_drzwi;
    car->moc = moc;
    car->poj_silnik = poj_silnik;
}
void wyswietl(SAuto &car)
{
    cout << "Marka: " << car.marka << " Model: " << car.model << " Kolor: " << car.kolor << endl;
    cout << "Liczba drzwi: " << car.l_drzwi << " Moc: " << car.moc << " Pojemnosc silnika: " << car.poj_silnik << endl
         << endl;
}
void pobierz(SAuto& car){
    string marka,model,kolor;
    unsigned l_drzwi,moc;
    float poj_silnik;
    cout<<"Podaj marke samochodu: ";
    cin>>marka;
    cout << "Podaj model samochodu: ";
    cin >> model;
    cout << "Podaj kolor samochodu: ";
    cin >> kolor;
    cout << "Podaj liczbe drzwi w samochodzie: ";
    cin >> l_drzwi;
    cout << "Podaj moc samochodu: ";
    cin >> moc;
    cout << "Podaj pojemnosc silnika samochodu: ";
    cin >> poj_silnik;
    inicjuj(car,marka,model,kolor,l_drzwi,moc,poj_silnik);
}
void pobierz(SAuto* car){
    string marka,model,kolor;
    unsigned l_drzwi,moc;
    float poj_silnik;
    cout<<"Podaj marke samochodu: ";
    cin>>marka;
    cout << "Podaj model samochodu: ";
    cin >> model;
    cout << "Podaj kolor samochodu: ";
    cin >> kolor;
    cout << "Podaj liczbe drzwi w samochodzie: ";
    cin >> l_drzwi;
    cout << "Podaj moc samochodu: ";
    cin >> moc;
    cout << "Podaj pojemnosc silnika samochodu: ";
    cin >> poj_silnik;
    inicjuj(car,marka,model,kolor,l_drzwi,moc,poj_silnik);
}
void pobierz(string nazwaPliku, SAuto& car){
    ifstream fin(nazwaPliku);
    if(!fin.good()){
        cout<<"Nieudalo sie otworzyc pliku.\n";
        fin.clear();
        fin.ignore();
        fin.close();
        exit(0);
    }
    string marka, model, kolor;
    unsigned l_drzwi, moc;
    float poj_silnik;
    fin>>marka>>model>>kolor>>l_drzwi>>moc>>poj_silnik;
    inicjuj(car,marka,model,kolor,l_drzwi,moc,poj_silnik);
    fin.clear();
    fin.ignore();
    fin.close();
}
void pobierz(string nazwaPliku, SAuto* car){
    ifstream fin(nazwaPliku);
    if(!fin.good()){
        cout<<"Nieudalo sie otworzyc pliku.\n";
        fin.clear();
        fin.ignore();
        fin.close();
        exit(0);
    }
    string marka, model, kolor;
    unsigned l_drzwi, moc;
    float poj_silnik;
    fin>>marka>>model>>kolor>>l_drzwi>>moc>>poj_silnik;
    inicjuj(car,marka,model,kolor,l_drzwi,moc,poj_silnik);
    fin.clear();
    fin.ignore();
    fin.close();
}
void pobierz(ifstream& plik, SAuto& car){;
    string marka, model, kolor;
    unsigned l_drzwi, moc;
    float poj_silnik;
    plik>>marka>>model>>kolor>>l_drzwi>>moc>>poj_silnik;
    inicjuj(car,marka,model,kolor,l_drzwi,moc,poj_silnik);
}
void pobierz(ifstream& plik, SAuto* car){;
    string marka, model, kolor;
    unsigned l_drzwi, moc;
    float poj_silnik;
    plik>>marka>>model>>kolor>>l_drzwi>>moc>>poj_silnik;
    inicjuj(car,marka,model,kolor,l_drzwi,moc,poj_silnik);

}
void zapisz(SAuto& car){
    cout << "Marka: " << car.marka << " Model: " << car.model << " Kolor: " << car.kolor << endl;
    cout<<"Liczba drzwi:"<<car.l_drzwi<<" Moc: "<<car.moc<<" Pojemnosc silnika: "<<car.poj_silnik <<endl<< endl;
}
void zapisz(SAuto* car){
    cout << "Marka: " << car->marka << " Model: " << car->model << " Kolor: " << car->kolor << endl;
    cout<<"Liczba drzwi:"<<car->l_drzwi<<" Moc: "<<car->moc<<" Pojemnosc silnika: "<<car->poj_silnik <<endl<< endl;
}
void zapisz(string nazwaPliku,SAuto& car){
    ofstream fout(nazwaPliku);
    if(!fout.good()){
        cout<<"Nie udalo sie otworzyc pliku wyjsciowego.\n";
        fout.clear();
        fout.close();
        exit(0);
    }
    fout << "Marka: " << car.marka << " Model: " << car.model << " Kolor: " << car.kolor << endl;
    fout<<"Liczba drzwi:"<<car.l_drzwi<<" Moc: "<<car.moc<<" Pojemnosc silnika: "<<car.poj_silnik <<endl<< endl;
    fout.clear();
    fout.close();
}
void zapisz(string nazwaPliku,SAuto* car){
    ofstream fout(nazwaPliku);
    if(!fout.good()){
        cout<<"Nie udalo sie otworzyc pliku wyjsciowego.\n";
        fout.clear();
        fout.close();
        exit(0);
    }
    fout << "Marka: " << car->marka << " Model: " << car->model << " Kolor: " << car->kolor << endl;
    fout<<"Liczba drzwi:"<<car->l_drzwi<<" Moc: "<<car->moc<<" Pojemnosc silnika: "<<car->poj_silnik <<endl<< endl;
    fout.clear();
    fout.close();
}
void zapisz(ofstream& fout,SAuto& car){
    fout << "Marka: " << car.marka << " Model: " << car.model << " Kolor: " << car.kolor << endl;
    fout << "Liczba drzwi:" << car.l_drzwi << " Moc: " << car.moc << " Pojemnosc silnika: " << car.poj_silnik << endl<< endl;
}
void zapisz(ofstream& fout,SAuto* car){
    fout << "Marka: " << car->marka << " Model: " << car->model << " Kolor: " << car->kolor << endl;
    fout << "Liczba drzwi:" << car->l_drzwi << " Moc: " << car->moc << " Pojemnosc silnika: " << car->poj_silnik << endl<< endl;
}
int main(int argc, char **argv)
{
    if(argc!=3){
        cerr<<"Bledna ilosc parametrow. Podaj nazwaProgramu plikWejsciowy.txt plikWyjsciowy.txt \n";
        return -1;
    }
    return 0;
}