#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void kopiuj(const string src, char *&dest){
    size_t dl = src.length();
    dest = new char[dl+1];
    for (size_t i = 0; i < dl; i++){
        dest[i] = src[i];
    }
    dest[dl] = '\0';
    //Lub
    // size_t x= src.copy(dest,src.size());
    // dest[x]='\0';
}
string wstaw(const string src, const char s, size_t p) {
    string napis;
    size_t dlsrc= src.length();
    size_t i = 0;
    for(;i<p;i++)   napis+=src[i];
    napis+=s;
    for(;i<dlsrc;i++) napis+=src[i];
    return napis;
}
string wstaw(const string src, const string s, size_t p) {
    string napis;
    size_t dlsrc = src.length();
    size_t i = 0;
    for (; i < p; i++)
        napis += src[i];
    napis += s;
    for (; i < dlsrc; i++)
        napis += src[i];
    return napis;
}
string wytnij(const string src, size_t n) {
    string napis = src;
    napis.erase(0,n);
    return napis;
}
int szukaj(const string src, const char *s) {
    for(size_t i=0;i<src.length();i++){
        if(src[i]==s[0]){
            return i;
        }
    }
    return -1;
}
int szukaj(const string src, const char s) {
    for (size_t i = 0; i < src.length(); i++)
    {
        if (src[i] == s)
        {
            return i;
        }
    }
    return -1;
}
int porownaj(const string s1, const string s2) {
    if(s1.length()>s2.length()) return -1;
    else if (s1.length()==s2.length()) return 0;
    else return 1; 
}
void usun(char *t)
{
    if (t){
        delete[] t;
        t = nullptr;
    }
}
int main(int argc, char **argv){
    if (argc != 5)
    {
        cerr << "Bledna ilosc argumentow. Powinno sie wpisac: nazwaPliku GlownyTekst Symbol/CiagZnakow MiejsceZnaku TekstDoPorownania" << endl;
        return 1;
    }
    string tekstZrodlowy = argv[1];
    size_t dlTekstZrodlowy = tekstZrodlowy.length();
    // Void kopiuj
    char *voidKopiuj;
    kopiuj(tekstZrodlowy, voidKopiuj);
    for (size_t i = 0; i < dlTekstZrodlowy; i++){
        cout << voidKopiuj[i] << "\t";
    }
    cout<<endl<<endl;
    usun(voidKopiuj);
    // Koniec void Kopiuj

    //Main kopiuj
    string tekstDesc = tekstZrodlowy;
    cout<<"Tekst po skopiowaniu main: "<<tekstDesc<<endl<<endl;
    //Koniec mainKopiuj
    string wstaw1 = wstaw(tekstZrodlowy,argv[2],atoi(argv[3]));
    cout<<"wstaw1: "<<wstaw1<<endl;
    string wytnij1 = wytnij(tekstZrodlowy,atoi(argv[3]));
    cout<<"Wytnij1: "<<wytnij1<<endl;
    int szukaj1 = szukaj(tekstZrodlowy, argv[2]);
    cout<<"Szukaj1: "<< szukaj1<< endl;
    int porownaj1 = porownaj(tekstZrodlowy,argv[4]);
    cout<<"Porownaj1 "<<porownaj1<<endl;
    return 0;
}