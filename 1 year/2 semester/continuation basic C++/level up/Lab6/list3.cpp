#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int* randomNumber(const unsigned int num);
void delete_Table(int* t);

int main(int argc, char* argv[]){
    if(argc != 3){
        cerr<<"Bledna ilosc argumentow. Podaj argumenty: nazwaProgramu nazwaPlikuWczytaj nazwaPlikuWypisz";
        return -1;
    }

    srand(time(NULL));

    ifstream wejsciowy(argv[1]);
    ofstream wyjsciowy(argv[2]);
    
    int liczbaKuponow;
    wejsciowy >> liczbaKuponow;

    
    for(int i=0; i<liczbaKuponow; i++){
        string nazwaGry;
        int num = 0;
        wejsciowy >> nazwaGry;
        if(nazwaGry=="maly_lotek_5"){
            num=5;
            int* wyl = randomNumber(num);
            delete_Table(wyl);
        } 
        else if(nazwaGry=="duzy_lotek_6"){
            num=6;
        } 
        else if(nazwaGry=="multilotek_10"){
            num=10;
        }  
        else cout<<"Bledne dane.\n";
    }

    return 0;
}
int* randomNumber(const unsigned int num){
    int* t = new int[num];
    t[0] = 1 + rand()% num*num;
    for(unsigned int i=1; i<num; i++){
        t[i] = 1 + rand()% num*num;
        int j=i-1;
        while(j>=0){
            while(t[i]==t[j]){
                t[i] = 1 + rand()% num*num;
                }
                j--;
            }
        }
        for(unsigned int i=0; i<num;i++){
            cout<<t[i]<<" ";
        }
        cout<<endl;
    return t;
}
void delete_Table(int* t){
    if(t){
        delete [] t;
        t=0;
    }
}