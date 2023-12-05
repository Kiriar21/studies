#include <iostream>
#include <cmath>
using namespace std;
class punkt{
    private:
        float _x,_y;
    public:
        punkt(){ _x=0;_y=0; }
        punkt(const float &x,const float &y){ _x=x;_y=y; }
        float &x(){ return _x; }
        float &y(){ return _y; }
        const float &x() const { return _x; }
        const float &y() const { return _y; }
        float odleglosc(punkt p){ return sqrt(pow(p._x-_x,2)+pow(p._y-_y,2)); }
        const float odleglosc(punkt p) const{ return sqrt(pow(p._x-_x,2)+pow(p._y-_y,2)); }
};
class wielobok{
    private:
        size_t _s;
        punkt* _p;
    public:
        wielobok(){ _s=0; _p = 0;}
        wielobok(const punkt *_poczatek, const punkt *_koniec){
            if(_koniec-_poczatek>0){
                 _s=_koniec-_poczatek; _p= new punkt[_koniec-_poczatek];
                for(size_t i=0;i<_s; i++){ _p[i]=_poczatek[i]; }
            }
        }
        float obwod(){
            float sum=0;
            for(size_t i=0; i<_s-1; i++){
                sum+=_p[i].odleglosc(_p[i+1]);
            }
            sum+=_p[0].odleglosc(_p[_s-1]);
            return sum;
        }
        punkt &Punkt(const int _i){
            return _p[_i];
        }
        void Punkty(const punkt *_poczatek, const punkt *_koniec)
        {
            if (_koniec - _poczatek > 0)
            {
                _s = _koniec - _poczatek;
                _p = new punkt[_koniec - _poczatek];
                for (size_t i = 0; i < _s; i++)
                {
                    _p[i] = _poczatek[i];
                }
            }
        }
        int ilosc(){
            return _s;
        }
};

int main()
{
    punkt p(2, 3); 
    cout<<"Punkty poczatkowe 2 i 3\n";
    cout << p.x() << ' ' << p.y() << '\n'; 
    
    p.x() = 1; 
    p.y() = 1;
    cout << "Punkty po zmianie 1 i 1\n";
    cout << p.x() << ' ' << p.y() << '\n'; 
    cout <<"Odleglosc punktow 1 i 1 "<< p.odleglosc(punkt()) << '\n'; 
    
    punkt t[] = { punkt(0, 1), punkt(0, 0), punkt(1, 0), punkt(1, 1) };
    wielobok w1(t, t+4); 
    cout <<"Obwod pierwszy : "<< w1.obwod() << '\n';
    cout << "Punkty przed zmiana:\n";
    for (int i = 0; i < w1.ilosc(); ++i)
        cout << w1.Punkt(i).x() << ' ' << w1.Punkt(i).y() << '\n';
    w1.Punkt(1) = punkt(0.5, 0.5);
    cout << "Obwod po zmianie punkty na 0.5, 0.5 : " << w1.obwod() << '\n';
    cout<<"Punkty po zmianie:\n";
    for (int i = 0; i < w1.ilosc(); ++i)
        cout<< w1.Punkt(i).x() << ' ' << w1.Punkt(i).y() << '\n';
    wielobok w2; 
    w2.Punkty(t, t+3); 
    cout << "Obwod w2 poczatkowy " << w2.obwod() << '\n'; 
    cout<<"Ilosc rekordow w tabeli: "<<w2.ilosc()<<endl;
    cout << "Punkty w w2:\n";
    for (int i = 0; i < w2.ilosc(); ++i) 
        cout << w2.Punkt(i).x() << ' ' << w2.Punkt(i).y() << '\n'; 

     return 0;
}
