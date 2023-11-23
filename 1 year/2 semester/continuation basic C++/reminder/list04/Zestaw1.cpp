#include <iostream>
using namespace std;
int suma(const int a, const int b){
    return a+b;
}
int roznica(const int a, const int b){
    return a-b;
}
int iloczyn(const int a, const int b){
    return a*b;
}
int iloraz(const int a, const int b){
    if(b!=0) return a/(double)b;
    else return 0;
}
bool sprawdz(int (*wfun)(const int a, const int b), const int a, const int b){
    return (*wfun)(a,b)>=0 ? 1 : 0;
}
int main(int argc, char** argv){
    int a, b;
    cout << "Podaj dwie liczby caªkowite: " << endl;
    cin >> a >> b;
    if (sprawdz(suma, a, b))
        cout << "Suma jest wieksza lub rowna 0" << endl;
    else
        cout << "Suma jest mniejsza od 0" << endl;
    if (sprawdz(roznica, a, b))
        cout << "Roznica jest wieksza lub rowna 0" << endl;
    else
        cout << "Roznica jest mniejsza od 0" << endl;
    if (sprawdz(iloczyn, a, b))
        cout << "Iloczyn jest wiekszy lub rowna 0" << endl;
    else
        cout << "Iloczyn jest mniejszy od 0" << endl;
    if (sprawdz(iloraz, a, b))
        cout << "Iloraz jest wiekszy lub rowna 0" << endl;
    else
        cout << "Iloraz jest mniejszy od 0" << endl;
    return 0;

}
