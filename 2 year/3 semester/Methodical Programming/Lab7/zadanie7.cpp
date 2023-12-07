#include <iostream>
#include <fstream>
using namespace std;

class Osoba{
  private:
    string _imie, _nazwisko;
    long long _pesel;
  public:
  //Konstruktor domyslny
    Osoba(){ _imie="Grzegorz", _nazwisko="Brzeczyszykiewicz", _pesel=10000000000; }
  // Konstruktor parametryczny
    Osoba(string i, string n, long long p): _imie(i), _nazwisko(n), _pesel(p){}
  // Metody Dostępowe
    string &imie() { return _imie;}
    string &nazwisko() { return _nazwisko;}
    long long &pesel() { return _pesel;}
    const string &imie() const { return _imie; }
    const string &nazwisko() const { return _nazwisko; }
    const long long &pesel() const { return _pesel; }
    //Operator == -> przeciązenie tego operatora == 
    bool operator==(const Osoba o1){
      if(this->_pesel == o1.pesel()){
        return true;
      } 
      return false;
    }
    friend ostream &operator<<(ostream &cout, const Osoba &o1);
    friend istream &operator>>(istream &cin, Osoba &o1);
};
//Przeciazenie operatora << dla klasy Osoba
ostream& operator<<(ostream& cout, const Osoba& o1){
   return cout<<o1.imie()<<" "<<o1.nazwisko()<<" "<<o1.pesel()<<endl;
}

// Przeciazenie operatora >> dla klasy Osoba
istream &operator>>(istream &cin, Osoba &o1){
   return cin>>o1.imie()>>o1.nazwisko()>>o1.pesel();
}

class BazaDanych{
  private:
    Osoba* _ludzie;
    int _rozmiar_tablicy;
  public:
  // Konstruktor domyślny
    BazaDanych(){
      _ludzie = nullptr;
      _rozmiar_tablicy = 0;
    }
    // Konstruktor parametryczny
    BazaDanych(const BazaDanych& druga_baza ){
      this->_rozmiar_tablicy=druga_baza._rozmiar_tablicy;
      this->_ludzie = new Osoba[this->_rozmiar_tablicy];
      for(int i=0; i<this->_rozmiar_tablicy; i++){
        this->_ludzie[i]=druga_baza._ludzie[i];
      }
    }
    // Metoda dostepowa
    int &liczbaOsob() {
      return _rozmiar_tablicy;
    }
    const int &liczbaOsob  ()const
    {
      return _rozmiar_tablicy;
    }
    // Operator przypisania kopiujacego
    BazaDanych operator=(const BazaDanych &druga_baza){
      this->_rozmiar_tablicy = druga_baza._rozmiar_tablicy;
      this->_ludzie = new Osoba[this->_rozmiar_tablicy];
      for (int i = 0; i < this->_rozmiar_tablicy; i++)
      {
        this->_ludzie[i] = druga_baza._ludzie[i];
      }
      return *this;
    }
    // Destruktor
    ~BazaDanych(){
       delete [] this->_ludzie; _rozmiar_tablicy=0; _ludzie=nullptr;
    }
    // Operator indeksowania pozwalający na dostęp do tablicy osób
    Osoba operator[](int index){
      return this->_ludzie[index];
    }
    // Operator + dodawania nowej osoby do bazy danych
    BazaDanych operator+(const Osoba o1){
      //1. _ludzie - musimy dodac nasza osobe o1
      //2. _rozmiar_tablicy - musimy go zwiekszyc o 1
      
      // Pomocnicza tablica do zapamiętania osób
      Osoba* pomocnicza = new Osoba[_rozmiar_tablicy];
      // Przepisujemy ludzi do pomocniczej tablicy 
      for(int i=0; i<this->_rozmiar_tablicy; i++){
        pomocnicza[i] = this->_ludzie[i];
      }
      // Zwiekszamy liczbe osob o 1 - zadanie 2 ukonczone
      this->_rozmiar_tablicy += 1;
      //Usuwamy aktualną tablice z this
      delete [] this->_ludzie;
      // Przypisanie o jeden wiecej miejsca w tablicy dynamicznej
      this->_ludzie = new Osoba[_rozmiar_tablicy];
      // Przepisanie ludzi z pomocniczej tablicy do glownej
      for (int i = 0; i < this->_rozmiar_tablicy-1; i++){
        this->_ludzie[i] = pomocnicza[i];
      }
      //Na koniec tablicy dopisujemy osobe z argumentu
      this->_ludzie[this->_rozmiar_tablicy-1] = o1;
      // Zwracamy tablice z ludzmi 
      return *this;
    }

    // Operator - usuwanie  osoby z bazy danych
    BazaDanych operator-(const Osoba o1)
    {
      // 1. _ludzie - musimy usunac osobe o1 O ILE JEST W BAZIE HEHE
      // 2. _rozmiar_tablicy - musimy go zmniejszyc o 1 

      // Przejście po całej tablicy 
      for(int i=0;i<this->_rozmiar_tablicy; i++){
        // Jeżeli w bazie danych jest osoba podana w argumencie to wykonujemy usuwanie 
        if(this->_ludzie[i]==o1){
          // Pomocnicza tabela z jednym miejscem mniej
           Osoba* pomocnicza1 = new Osoba[this->_rozmiar_tablicy-1];
           //Przepisanie ludzi tych którzy są przed wymaganym rekordem
           for(int j=0; j<i; j++) pomocnicza1[j]=this->_ludzie[j];
           //Dodanie pozostalych ludzi znalezionych po usunietej osobie
           for(int k=i+1; k<this->_rozmiar_tablicy; k++) pomocnicza1[k-1]=this->_ludzie[k];
           delete [] this->_ludzie;
           _rozmiar_tablicy--;
           this->_ludzie = new Osoba[this->_rozmiar_tablicy];
           this->_ludzie=pomocnicza1;
        }
      }
      // Zwracamy podmienioną tablice 
      return *this;
    }

    // Operator + dodawania bazy danych 
    BazaDanych operator+(const BazaDanych bd1){
      //Potrzeba nam duzej tablicy zeby przechowac dane z glownej bazy i argumetnowej bazy
      Osoba* pomocnicza2 = new Osoba[this->_rozmiar_tablicy + bd1._rozmiar_tablicy];
      // Pierwsza petla - do tablicy pomocniczej wpisujemy z this rekordy
      for(int i=0;i<this->_rozmiar_tablicy; i++){
        pomocnicza2[i] = this->_ludzie[i];
      }
      for (int j = this->_rozmiar_tablicy; j < this->_rozmiar_tablicy + bd1._rozmiar_tablicy; j++){
        pomocnicza2[j] = bd1._ludzie[j-this->_rozmiar_tablicy];
      }
      delete [] this->_ludzie;
      this->_rozmiar_tablicy = this->_rozmiar_tablicy + bd1._rozmiar_tablicy;
      this->_ludzie = pomocnicza2;
      return *this;
    }
    friend ostream &operator<<(ostream &cout, const BazaDanych &o1);
};
// Przeciazenie operatora << dla klasy BazaDanych
ostream &operator<<(ostream &cout, const BazaDanych &o1)
{
    if(o1.liczbaOsob()>0){
      for(int i=0; i<o1.liczbaOsob(); i++){
        cout<<o1._ludzie[i];
      }
    }
    else{
      cout<<"Nie ma nikogo w bazie.\n";
    }
    return cout;
}

int main()
{
  Osoba o1;
  cout << "---- 1 ----" << endl;
  cout << o1 << endl;

  Osoba o2("Jan", "Kowalski", 11111111111);
  cout << "---- 2 ----" << endl;
  cout << o2 << endl;
      
  cout << "---- 3 ----" << endl;
  cout << boolalpha << (o1 == o2) << endl;

  BazaDanych db1;
  cout << "---- 4 ----" << endl;
  cout << db1;
  
  db1 = db1 + o1;
  cout << "---- 5 ----" << endl;
  cout << db1;
  
  ifstream plik_we("zadanie7.txt");
  if(!plik_we)
  {
    cout << "---- 6 ----" << endl;
    return 1;
  }
  
  while(plik_we >> o2)
  {
      db1 = db1 + o2;
  }
  cout << "---- 7 ----" << endl;
  cout << db1;
  
  {
      BazaDanych db2(db1);
      cout << "---- 8 ----" << endl;
      cout << db2;
  }
  cout << "---- 9 ----" << endl;
  cout << db1;
  
  BazaDanych db3;
  db3 = db1 + db1
  cout << "---- 10 ----" << endl;
  cout << db3;
  
  for(int i=0; i<db3.liczbaOsob(); ++i)
  {
      cout << db3[i] << endl; 
  }
  cout << "---- 11 ----" << endl;  
  
  db1 = db1 - o1;
  cout << "---- 12 ----" << endl;
  cout << db1;
  
  cout << "---- 13 ----" << endl;
  cout << db3;
  cout << "---- 14 ----" << endl;
  
  return 0;
}