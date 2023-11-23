#include <iostream>
#include <fstream>
using namespace std;
void selector(){
    ofstream fout("adresyEmail.txt",ios::app);
    if(!fout.good()){
        cout<<"Blad otwarcia pliku do zapisania.\n";
        fout.clear();
        fout.close();
        exit(0);
    }
    string wczytanie, email[100];
    int counter=0;
    while(counter<100){
        cout<<"Imie:\n";
        cin>>wczytanie;
        if(wczytanie=="END") break;
        cout << "nazwisko:\n";
        cin >> wczytanie;
        if (wczytanie == "END")
            break;
        cout << "numergg:\n";
        cin >> wczytanie;
        if (wczytanie == "END")
            break;
        cout << "email:\n";
        cin >> wczytanie;
        if (wczytanie == "END")
            break;
        for(int i=0; wczytanie[i]!='\0';i++){
            if(wczytanie[i]=='@'){
                fout<<wczytanie<<";";
                email[counter]=wczytanie;
                counter++;
                break;
            }
        }

    }
    for(int i=0;i<counter;i++){
        cout<<email[i]<<";\n";
    }
    fout.clear();
    fout.close();
}
int main(int argc, char** argv){
    cout<<"Podaj dane osobowe do wczytania:\n";
    selector();
    return 0;
}