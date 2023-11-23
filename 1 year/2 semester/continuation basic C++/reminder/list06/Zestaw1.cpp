#include <iostream>
using namespace std;
struct SAuto{
    string marka, model, kolor;
    unsigned l_drzwi, moc;
    float poj_silnik;
};
SAuto inicjuj(string marka = "A", string model = "A", string kolor= "A", unsigned l_drzwi=5, unsigned moc=120,float poj_silnik=1.0){
    SAuto element={marka,model,kolor,l_drzwi,moc,poj_silnik};
    return element;
}
void inicjuj(SAuto &car, string marka = "B", string model = "B", string kolor = "B", unsigned l_drzwi = 5, unsigned moc = 120, float poj_silnik = 1.0){
    car.marka=marka;
    car.model=model;
    car.kolor=kolor;
    car.l_drzwi=l_drzwi;
    car.moc=moc;
    car.poj_silnik=poj_silnik;
}
void inicjuj(SAuto *car, string marka = "C", string model = "C", string kolor = "C", unsigned l_drzwi = 5, unsigned moc = 120, float poj_silnik = 1.0){
    car->marka=marka;
    car->model=model;
    car->kolor=kolor;
    car->l_drzwi=l_drzwi;
    car->moc=moc;
    car->poj_silnik=poj_silnik;
}
void wyswietl(SAuto& car){
    cout<<"Marka: "<<car.marka<<" Model: "<<car.model<<" Kolor: "<<car.kolor<<endl;
    cout<<"Liczba drzwi: "<<car.l_drzwi<<" Moc: "<<car.moc<<" Pojemnosc silnika: "<<car.poj_silnik<<endl<<endl;
}
int main(int argc, char** argv){
    return 0;
}