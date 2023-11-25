#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int* randomNumber(const unsigned int num);
void delete_Table(int* t);
bool spr(const int* random, const int* uzyt, int num, int& strzaly);
void totalizator(int strzaly);

int main(int argc, char* argv[]){
    if(argc != 3){
        cerr<<"Bledna ilosc argumentow. Podaj argumenty: nazwaProgramu nazwaPlikuWczytaj nazwaPlikuWypisz";
        return -1;
    }

    srand(time(NULL));

    ifstream wejsciowy;
    ofstream wyjsciowy;

    wejsciowy.open(argv[1]);
    wyjsciowy.open(argv[2]);

    if(wejsciowy.good() && wyjsciowy.good()){

    int liczbaKuponow;
    wejsciowy >> liczbaKuponow;


    for(int i=0; i<liczbaKuponow; i++){
        string nazwaGry;
        int num = 0;
        int strzaly=0;
        wejsciowy >> nazwaGry;
        if(nazwaGry=="maly_lotek_5"){
            wyjsciowy<<"maly_lotek_5\nWylosowane liczby: \n";
            num=5;
            int* pseudoLos5 = randomNumber(num);
            for(int i=0; i<num; i++) wyjsciowy<<pseudoLos5[i]<<" ";
            int liczbyUz[5] ={0};
            for(int i=0; i<num; i++){
                wejsciowy>>liczbyUz[i];
            }
            bool wyn = spr(pseudoLos5,liczbyUz,num,strzaly);
            wyjsciowy<<"\nIlosc trafionych liczb: \n "<<strzaly<<endl;
            wyjsciowy<<"Trafione liczby: \n";
            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    if(pseudoLos5[i]==liczbyUz[j]){
                    wyjsciowy<<pseudoLos5[i]<<" ";
                     } 
                }
            }
            wyjsciowy<<endl;
            if(wyn) totalizator(strzaly);
            else cout<<"Nie udalo Ci sie nic wygrac\n";
            wyjsciowy<<endl;
            delete_Table(pseudoLos5);
        } 
        else if(nazwaGry=="duzy_lotek_6"){
            wyjsciowy<<"duzy_lotek_6\nWylosowane liczby: \n";
            num=6;
            int* pseudoLos6 = randomNumber(num);
            for(int i=0; i<num; i++) wyjsciowy<<pseudoLos6[i]<<" ";
            int liczbyUz[6] ={0};
            for(int i=0; i<num; i++){
                wejsciowy>>liczbyUz[i];
            }
            bool wyn = spr(pseudoLos6,liczbyUz,num, strzaly);
            wyjsciowy<<"\nIlosc trafionych liczb: \n"<<strzaly<<endl;
            wyjsciowy<<"Trafione liczby: \n";
            for(int i=0; i<6; i++){
                for(int j=0; j<6; j++){
                    if(pseudoLos6[i]==liczbyUz[j]){
                    wyjsciowy<<pseudoLos6[i]<<" ";
                     } 
                }
            }
            wyjsciowy<<endl;
            if(wyn) totalizator(strzaly);
            else cout<<"Nie udalo Ci sie nic wygrac\n";
            wyjsciowy<<endl;
            delete_Table(pseudoLos6);
        } 
        else if(nazwaGry=="multilotek_10"){
            wyjsciowy<<"multitotek_10\n";
            num=10;
            int* pseudoLos10 = randomNumber(num);
            for(int i=0; i<num; i++) wyjsciowy<<pseudoLos10[i]<<" ";
            int liczbyUz[10] ={0};
            for(int i=0; i<num; i++){
                wejsciowy>>liczbyUz[i];
            }
            bool wyn = spr(pseudoLos10,liczbyUz,num, strzaly);
            wyjsciowy<<"\nIlosc trafionych liczb: \n "<<strzaly<<endl;
            wyjsciowy<<"Trafione liczby: \n";
            for(int i=0; i<10; i++){
                for(int j=0; j<10; j++){
                    if(pseudoLos10[i]==liczbyUz[j]){
                    wyjsciowy<<pseudoLos10[i]<<" ";
                     } 
                }
            }
            wyjsciowy<<endl;
            if(wyn) totalizator(strzaly);
            else cout<<"Nie udalo Ci sie nic wygrac\n";
            wyjsciowy<<endl;
            delete_Table(pseudoLos10);
        }  
        else cout<<"Bledne dane.\n";
    }
    wejsciowy.close();
    wyjsciowy.close();
    }
    else{
        cout<<"Blad odczytu pliku. \n";
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
    return t;
}
void delete_Table(int* t){
    if(t){
        delete [] t;
        t=0;
    }
}
bool spr(const int* random, const int* uzyt, int num, int& strzaly){
        strzaly=0;
        for(int i=0; i<num; i++){
            for(int j=0; j<num; j++){
                if(random[i]==uzyt[j]){
                    strzaly++;
                    cout<<random[i]<<" ";
                } 
            }
    }
    if(strzaly>3) return 1;
    else return 0;
    
}
void totalizator(int strzaly){
    switch(strzaly){
        case 4:
            cout<<"Wygrana: "<<strzaly*10/2<<endl;
        break;
        case 5:
            cout<<"Wygrana: "<<strzaly*30/2<<endl;
        break;
        default:
            cout<<"Wygrana: "<<strzaly*100/2<<endl;
        break;
    }
}