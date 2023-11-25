#include<iostream>
#include <fstream>

using namespace std;

void selector();

int main(){
    cout<<"Podaj dane osobowe do wczytania: \n";
    selector();
    return 0;
}
void selector(){
    cout<<"Podaj swoje dane osobowe: \n";
    //char* dane = new char[256];
    char* dane[64];
    while(dane!=end)
    {
        cin>>dane;
    }
    cout<<dane;
    //delete [] dane; 
    cout<<dane[1];
}