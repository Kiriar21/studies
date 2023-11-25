#include <iostream>
#include <fstream>
using namespace std;

bool czyMail(const string dane);
void selektor();

int main() {
  cout << "Podaj dane osobowe: \n";
  selektor();
  return 0;
}
bool czyMail(const string dane){
    size_t dlugosc=dane.length();
    size_t i=0;

  for(; i < dlugosc; i++){
    if(dane[i] == '@'){
      return 1;
    }
  } 
  return 0;
}
void selektor(){
  string dane, mail;
  do{
    cin >> dane;
    if(czyMail(dane) == 1){
      mail += dane;
      mail += ';';
    }
  }while(dane != "END");
  fstream plik("maile.txt");
  plik << mail << endl;
  plik.close();
}