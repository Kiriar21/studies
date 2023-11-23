#include<iostream>
#include<cmath>

using namespace std;

struct SPunkt{
    double x,y;
};
struct SProsta{
    double a,b;
};
struct SOkrag{
    double a,b,r;
};
struct SRownanie{
    double a,b,c;
};
int rozw_rown(const SRownanie &r, SPunkt &p1, SPunkt &p2){
    double x1=0,x2=0, delta=((r.b*r.b)-(4*r.a*r.c)),pierwDelta=sqrt(delta);
    if(delta>=0){
        if(r.a!=0){
            x1 = (-r.b - pierwDelta) / (2 * r.a), x2 = (-r.b + pierwDelta) / (2 * r.a);
        }
    }
    p1 = {x1, 0}, p2 = {x2, 0};
    if(delta>0){
        return 2;
    } 
    else if(delta<0){
        return 0;
    }
    else{
        return 1;
    }
}
int pkt_przec(const SProsta &p, const SOkrag &o, SPunkt &p1, SPunkt &p2){
    //Do zrobienia
}
bool czy_prostopadle(const SProsta p1, const SProsta p2){
    //czy rownolegle
    // if(p1.a==p2.a){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    

    //czy prostopadle
    int iloczynWspolczynnikow=p1.a*p2.a;
    if(iloczynWspolczynnikow==-1){
        return true;
    }
    else{
        return false;
    }
}
int main(int argc, char **argv){
    SRownanie proba={1,10,3};
    SPunkt p1={0,0},p2={0,0};
    int iloscM0=rozw_rown(proba,p1,p2);
    cout<<"ilosc miejsc zerowych: "<<iloscM0<<endl;
    if(iloscM0>0){
        if(iloscM0==2){
            cout << "Miejsca zerowe: (" << p1.x << "," << p1.y << ") i (" << p2.x << "," << p2.y << ")\n";
        }
        else if(iloscM0==1){
            cout << "Miejsca zerowe: (" << p1.x << "," << p1.y << ")\n";
        }
        else{
            cout<<"Brak miejsc zerowych\n";
        }
    }

    SProsta prosta1 = {1.0, 3.0};
    SProsta prosta2 = {-1.0, -33};
    SProsta prosta3 = {1.0, -3};
    // { a, b, r}
    SOkrag okrag = {0.0, 1.0, 2.0};
    if(czy_prostopadle(prosta1,prosta2)) 
        cout<<"prosta: "<<prosta1.a<<" x + "<<prosta1.b<<" i prosta: "<<prosta2.a<<" x + "<<prosta2.b <<" sa prostopadle\n";
    if(czy_prostopadle(prosta2,prosta3))
        cout << "prosta: " << prosta2.a << " x + " << prosta2.b << " i prosta: " << prosta3.a << " x + " << prosta3.b << " sa prostopadle\n";
    if(czy_prostopadle(prosta1,prosta3))
        cout << "prosta: " << prosta1.a << " x + " << prosta1.b << " i prosta: " << prosta3.a << " x + " << prosta3.b << " sa prostopadle\n";
    return 0;
}