#include <iostream>
#include <string>

using namespace std;

void kopiuj(const string src, char*& dest);
string wstaw(const string src, const char s, size_t p);
string wstaw(const string src, const string s, size_t p);
string wytnij(const string src, size_t p);
int szukaj(const string src, const char s);
int szukaj(const string src, const char* s);
int porownaj(const string s1, const string s2);

int main(int argc, char* argv[]){
    if(argc != 5){
        cerr << "Bledna ilosc argumentow. Powinno sie wpisac: nazwaPliku GlownyTekst Symbol/CiagZnakow MiejsceZnaku TekstDoPorownania" << endl;
        return 1;
    }
    string src = argv[1],dest;
    dest=src;
    cout << "Skopiowany napis: ";
    cout << dest << endl;
    dest = wstaw(argv[1],argv[2],atoi(argv[3]));
    cout << "Napis po wstawieniu: ";
    cout << dest << endl;
    dest = wytnij(argv[1],atoi(argv[3]));
    cout << "Tekst po wycieciu: ";
    cout << dest << endl;
    cout << "Pozycja wyszukana:  ";
    cout<<szukaj(argv[1],argv[2]) << endl;
    cout << "Czy dlugosci sa takie same: 0 - takie same, 1 - glowny tekst jest krotszy, -1 - glowny tekst jest dluzszy : ";
    cout<< porownaj(argv[1],argv[4]) << endl;
    
    return 0;
}

void kopiuj(const string src, char*& dest){     
  dest = new char[src.size()+1];
  size_t p = src.copy(dest,src.size());
  dest[p] = '\0';
}
string wstaw(const string src, const char s, size_t p){
  string dest;
  size_t i = 0;
  for(; i < p; i++){
    dest += src[i];
    }
  dest += s;
  for(; i < src.length(); i++){
    dest += src[i];
    }
  return dest;
}
string wstaw(const string src, const string s, size_t p){
  string dest;
  size_t i = 0;
  for(; i < p; i++){
    dest += src[i];
    }
  dest += s;
  for(; i < src.length(); i++){
    dest += src[i];
    }
  return dest;
}
string wytnij(const string src, size_t p){
  string dest;
  dest = src;
  dest.erase(0,p);
  return dest;
}
int szukaj(const string src, const char s){
  size_t dlugosc=src.length();
  size_t i=0;
  for(; i < dlugosc; i++){
    if(src[i] == s){
      return i+1;
    }
  }
  cout<<"Brak pozycji.";
  return 0;
}
int szukaj(const string src, const char* s){
  size_t dlugosc=src.length();
  size_t i=0;
  for(; i < dlugosc; i++){
    if(src[i] == s[0]){
      return i+1;
    }
  }
  cout<<"Brak pozycji.";
  return 0;
}
int porownaj(const string s1, const string s2){
  size_t dlugosc=s1.length();
  size_t dlugosc1=s2.length();
  if(dlugosc > dlugosc1){
    return -1;
  }
  else if(dlugosc < dlugosc1){
    return 1;
  }
  else{
    return 0; 
  }
}