#include <iostream> 
using namespace std;
unsigned int potega_10(const unsigned int argument){
    unsigned int potega=1;
    for(unsigned int i=1;i<=argument;i++){
        potega*=10;
    }
    return potega;
}
unsigned int ile_cyfr(unsigned int cyfra){
    int i=0;
    for(;cyfra>1;i++){
        cyfra/=10;
        // cout<<cyfra<<endl;
    }
    return i+1;
}
unsigned int ile_cyfr(unsigned int cyfra, const int a)
{
   return to_string(cyfra).length();
}
unsigned int doklej_do_liczby(const unsigned int zrodlo, const unsigned int cyfra, bool na_poczatek=true){
    if(cyfra>9 || cyfra<0){
        return zrodlo;
    }
    if(na_poczatek){
        unsigned int a=ile_cyfr(zrodlo,1);
        a=potega_10(a);
        a*=cyfra;
        a+=zrodlo;
        return a;
    }
    else{
        unsigned int a = zrodlo*10+cyfra;
        return a;
    }
}
unsigned int znak_na_cyfre(const char znak){
    switch(znak){
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 7;
        break;
    case '8':
        return 8;
        break;
    case '9':
        return 9;
        break;
    default:
        return 0;
    break;
    }
}
unsigned int zamien_na_liczbe(const string tekst){
    int dl=tekst.length();
    unsigned liczba=0;
    for(int i=0;i<dl;i++){
        int x = znak_na_cyfre(tekst[i]);
        if(x==0 && tekst[i]!='0')   cerr<<"Ostrzezenie. Wykryto znak niebedacy cyfra. Jest to znak: " <<tekst[i]<< " Zamieniono go na 0.\n";
        x*=potega_10(dl-i-1);
        liczba+=x;
    }
    return liczba;
}
int main(int argc, char** argv){
    if(argc>2){
        cerr<<"Bledna ilosc parametrow. Wpisz albo sama nazwe programu albo nazwaProgramu ciagTekstu\n";
        return -1;
    }
    if(argc==1){
        string tekst;
        cout<<"Podaj ciag tekstu:\n";
        cin>>tekst;
        cout<<zamien_na_liczbe(tekst);
    }
    else{
        string tekst1=argv[1];
        cout<<zamien_na_liczbe(tekst1);
    }
    cout<<endl<<endl<<endl;
    unsigned jakas_liczba = 6572;
    cout << doklej_do_liczby(jakas_liczba, 5) << endl;
    // 56572
    cout << doklej_do_liczby(jakas_liczba, 1, false) << endl;
    // 65721
    unsigned jakas_druga_liczba = zamien_na_liczbe("1234");
    cout << jakas_druga_liczba << endl;
    // 1234
    jakas_druga_liczba = zamien_na_liczbe("1ert234");
    cout << jakas_druga_liczba << endl;
    // 1000234
    return 0;
}