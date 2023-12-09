#include <iostream>
using namespace std;
class Paczka{
  private:
    string _adres;
    float _wartosc;
  public:
    Paczka(){ _adres= "null", _wartosc=0;}
    Paczka(string a, float w):_adres(a), _wartosc(w){}
    friend ostream &operator<<(ostream &cout, const Paczka &p);
    string &adres(){ return _adres;}
    float &wartosc(){ return _wartosc; }
    const string &adres() const  { return _adres; }
    const float &wartosc() const { return _wartosc; }
};
ostream &operator<<(ostream &cout, const Paczka &p){
  return cout<<p.adres()<<" "<<p.wartosc()<<endl;
}
class Osoba{
  private:
    string _imie, _nazwisko;
  public:
    Osoba(){_imie="imie", _nazwisko="nazwisko"; }
    Osoba(string i, string n):_imie(i),_nazwisko(n){}
    bool operator==(const Osoba &os1){
      if(this->_imie==os1.imie() && this->_nazwisko==os1.nazwisko()) return true;
      return false;
    }
    friend ostream &operator<<(ostream &cout, const Osoba &os1);
    string &imie(){ return _imie; }
    string &nazwisko() { return _nazwisko; }
    const string &imie() const { return _imie; }
    const string &nazwisko() const { return _nazwisko; }
};
ostream &operator<<(ostream &cout, const Osoba &os1){
    return cout << os1.imie() << " " << os1.nazwisko() << endl;
}
class Kurier: public Osoba{
    private:
      Paczka* _paczki;
      int _ilosc_paczek;
    public:
      Kurier(){ _paczki = nullptr; _ilosc_paczek=0; }
      Kurier(Paczka* poczatek, Paczka* koniec){
        _ilosc_paczek = koniec-poczatek;
        _paczki = new Paczka[_ilosc_paczek];
        int i=0;
        while(poczatek<koniec){
          _paczki[i]=*poczatek;
          i++;
          poczatek++;
        }
      }
      Kurier(const Kurier& k1){
        this->_ilosc_paczek=k1._ilosc_paczek;
        this->_paczki=new Paczka[this->_ilosc_paczek];
        for(int i=0;i<this->_ilosc_paczek;i++){
          this->_paczki[i]=k1._paczki[i];
        }
      }
      ~Kurier(){ delete [] _paczki; _paczki=nullptr; _ilosc_paczek=0; }
      Kurier operator=(const Kurier& k1){
        if(this->_paczki==k1._paczki) return *this;
        this->_ilosc_paczek = k1._ilosc_paczek;
        this->_paczki = new Paczka[this->_ilosc_paczek];
        for (int i = 0; i < this->_ilosc_paczek; i++){
          this->_paczki[i] = k1._paczki[i];
        }
        return *this;
      }
      Paczka operator[](const int i){
        if(i<0 || i>this->_ilosc_paczek-1) throw 1;
        else return this->_paczki[i];
      }
      float wartosc(){
        float wart = 0;
        for(int i=0; i<this->_ilosc_paczek; i++){
          wart=wart+_paczki[i].wartosc();
        }
        return wart;
      }
      Kurier operator+(const Paczka& p1){
        Paczka* temp = new Paczka[this->_ilosc_paczek+1];
        for(int i=0; i<this->_ilosc_paczek; i++){
          temp[i]=this->_paczki[i];
        }
        temp[this->_ilosc_paczek]=p1;
        delete [] this->_paczki;
        this->_ilosc_paczek++;
        _paczki = new Paczka[this->_ilosc_paczek];
        _paczki=temp;
        return *this;
      }

};
int main()
{
  Paczka p[] = {
    Paczka("Dabrowskiego 33", 123.00), 
    Paczka("NMP 12", 40.00),
    Paczka("Armii Krakowej 4", 30.00), 
    Paczka("Andersa 6", 51.00),
    Paczka("Kukuczki 13", 12.00), 
    Paczka("Skrzyneckiego 5", 40.00), 
  };

  Osoba o1("Jan", "Kowalski");
  cout << "---- 1 ----" << endl;
  cout << o1 << endl;
  
  {
      Osoba o2(o1);
      cout << "---- 2 ----" << endl;
      cout << o2 << endl;
      
      cout << "---- 3 ----" << endl;
      cout << boolalpha << (o1 == o2) << endl;
      
      Osoba o3;
      cout << "---- 4 ----" << endl;
      cout << o3 << endl;

      o3 = o2;
      cout << "---- 5 ----" << endl;
      cout << o3 << endl;
      
  }   

  cout << "---- 6 ----" << endl;
  cout << o1 << endl;
      
  Kurier k1(p, p+3);
  cout << "---- 7 ----" << endl;
  cout << k1.wartosc() << endl;

  Kurier k2;
  cout << "---- 8 ----" << endl;
  cout << k2.wartosc() << endl;

  {
    Kurier k3(k1);
    cout << "---- 9 ----" << endl;
    cout << k3.wartosc() << endl;

    k2 = k3;
    cout << "---- 10 ----" << endl;
    cout << k2.wartosc() << endl;

    k1 = k1 + p[4]; 
    k1 = k1 + p[5];

    cout << "---- 11 ----" << endl;
    cout << k1.wartosc() << endl;

  }

  cout << "---- 12 ----" << endl;
  cout << k2.wartosc() << endl;

  try{
    Kurier k4(p, p+3);
    cout << "---- 13 ----" << endl;
    for(int i=0; i<10; ++i){
      cout << k4[i] << ",";
    }
    cout << endl;
  }
  catch(...){
    cout << "---- 14 ----" << endl;
    cout << "Wyjatek" << endl;
  }

  return 0;
}
