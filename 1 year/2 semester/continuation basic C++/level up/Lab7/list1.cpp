#include <iostream>
#include <string>
using namespace std;

struct SAuto{
    string marka, model, kolor;
    unsigned int liczbaDrzwi, KM;
    float pojemnoscSilnika;
};

SAuto inicjuj(){
    SAuto mojNowyCar;
    string marka="AUDI", model="RS7", kolor="Black";
    unsigned int liczbaDrzwi=5, KM=760;
    float pojemnoscSilnika=5.0;
    // mojNowyCar.marka=marka;
    // mojNowyCar.model=model;
    // mojNowyCar.kolor=kolor;
    // mojNowyCar.liczbaDrzwi=liczbaDrzwi;
    // mojNowyCar.KM=KM;
    // mojNowyCar.pojemnoscSilnika=pojemnoscSilnika;
    mojNowyCar={marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika};
    return mojNowyCar;
}
void inicjuj(SAuto& mojNowyCar){
    string marka="Opel", model="Astra", kolor="Blue";
    unsigned int liczbaDrzwi=3, KM=126;
    float pojemnoscSilnika=1.6;
    // mojNowyCar.marka=marka;
    // mojNowyCar.model=model;
    // mojNowyCar.kolor=kolor;
    // mojNowyCar.liczbaDrzwi=liczbaDrzwi;
    // mojNowyCar.KM=KM;
    // mojNowyCar.pojemnoscSilnika=pojemnoscSilnika;
    mojNowyCar={marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika};
}
void inicjuj(SAuto* mojNowyCar){
    string marka="BMW", model="X6", kolor="White";
    unsigned int liczbaDrzwi=3, KM=450;
    float pojemnoscSilnika=4.5;
    // mojNowyCar->marka=marka;
    // mojNowyCar->model=model;
    // mojNowyCar->kolor=kolor;
    // mojNowyCar->liczbaDrzwi=liczbaDrzwi;
    // mojNowyCar->KM=KM;
    // mojNowyCar->pojemnoscSilnika=pojemnoscSilnika;
    *mojNowyCar={marka, model, kolor, liczbaDrzwi, KM, pojemnoscSilnika};
}
void wyswietl(SAuto& mojNowyCar){
    cout<<"Marka twojego samochodu: "<<mojNowyCar.marka<<endl;
    cout<<"Model twojego samochodu: "<<mojNowyCar.model<<endl;
    cout<<"Kolor twojego samochodu: "<<mojNowyCar.kolor<<endl;
    cout<<"Liczba drzwi w twoim samochodzie: "<<mojNowyCar.liczbaDrzwi<<endl;
    cout<<"Liczba koni mechanicznych w twoim samochodzie: "<<mojNowyCar.KM<<endl;
    cout<<"Pojemnosc silnika w twoim samochodzie: "<<mojNowyCar.pojemnoscSilnika<<endl;
    cout<<endl;
}
int main(){
    SAuto mojNowyCar;
    mojNowyCar = inicjuj();
    wyswietl(mojNowyCar);
    inicjuj(mojNowyCar);
    wyswietl(mojNowyCar);
    inicjuj(&mojNowyCar);
    wyswietl(mojNowyCar);
    return 0;
}