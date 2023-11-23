#include <iostream>
using namespace std;
unsigned int **tworz2d(const unsigned int wiersze, const unsigned int kolumny)
{
    unsigned int **tablica = new unsigned int *[wiersze];
    for (unsigned int  i = 0; i < wiersze; i++)
    {
        tablica[i] = new unsigned int[kolumny];
    }
    for (unsigned int i = 0; i < wiersze; i++)
    {
        for (unsigned int j = 0; j < kolumny; j++)
        {
            tablica[i][j] = rand() % 100;
        }
    }
    return tablica;
}
void wypisz_tablice_2d(unsigned int **tab, const unsigned int wiersze, const unsigned int kolumny){
    for(unsigned int i=0; i<wiersze;i++){
        for(unsigned int j=0;j<kolumny;j++){
            cout<<"["<<tab[i][j]<<"]"<<" ";
        }
        cout<<endl;
    }
}
unsigned int ile_wystapien_znaku(const string zrodlo, const char znak){
    unsigned int counter=0;
    for(size_t i=0;i<zrodlo.length();i++){
        if(zrodlo[i]==znak) counter++;
    } 
    return counter;
}
unsigned int znak_na_numer(const char znak){
    return znak >= 'a' && znak <= 'z' ? znak - 'a' : 111;
}
void usun(unsigned int** tab, const unsigned int wiersze){
    if(tab){
        for(unsigned int i=0;i<wiersze;i++){
            delete [] tab[i];
            tab[i]=nullptr;
        }
        delete [] tab;
        tab=nullptr;
    }
}
void usun(unsigned int* tab){
    if(tab){
        delete [] tab;
        tab=nullptr;
    }
}
void statystyka(unsigned int* tablica, const string napis){
    for(int i=0;i<26;i++){
        tablica[i]=0;
    }
    for (int i = 0; i < 26; i++)
    {
        tablica[i]=ile_wystapien_znaku(napis,'a'+i);
    }
}
unsigned int** statystyki(const string napisy[],const unsigned int rozmiar){
    unsigned int** tablica = new unsigned int*[rozmiar];
    for(unsigned int i=0;i<rozmiar;i++){
        tablica[i]=new unsigned int[26];
    }
    for (unsigned int i = 0; i < rozmiar; i++)
    {
        for (unsigned int j = 0; j < 26; j++)
        {
            tablica[i][j] = 0;
        }
    }
    for(unsigned int i=0;i<rozmiar;i++){
        for(unsigned int j=0;j<26;j++){
            tablica[i][j] = ile_wystapien_znaku(napisy[i], 'a' + j);
        }
    }
    return tablica;
}
int main(int argc, char **argv){
    // unsigned int** tablica=tworz2d(10,10);
    // wypisz_tablice_2d(tablica,10,10);
    // usun(tablica,10);

    // cout << "-----------------------------------------------\n\n";
    // cout<<ile_wystapien_znaku("Masakracja",'a')<<endl;
    // cout << "-----------------------------------------------\n\n";
    // cout<<"-----------------------------------------------\n\n";
    // cout<<znak_na_numer('a')<<endl;
    // cout << znak_na_numer('b') << endl;
    // cout << znak_na_numer('c') << endl;
    // cout << znak_na_numer('z') << endl;
    // cout<<znak_na_numer('X')<<endl;
    // cout << "-----------------------------------------------\n\n";

    // cout << "-----------------------------------------------\n\n";
    // unsigned int* tab=new unsigned int[26];
    // statystyka(tab,"kostarykapolnocnoamerykanska");
    // usun(tab);
    // cout << "-----------------------------------------------\n\n";

    string napisy[] = {"ala ma", "kota", "abcdefghijklmnopqrstuvwxyz"};
    int a = sizeof(napisy);
    cout<<a<<endl;
    unsigned **statsy = statystyki(napisy, 3);
    wypisz_tablice_2d(statsy, 3, 26);
    usun(statsy,3);

    return 0;
}

