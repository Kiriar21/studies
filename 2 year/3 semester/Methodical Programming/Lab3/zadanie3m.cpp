#include <iostream>

using namespace std;

int main()
{
    punkt p(2, 3); 
    cout << p.x() << ' ' << p.y() << '\n'; 
    
    p.x() = 1; 
    p.y() = 1; 
    cout << p.x() << ' ' << p.y() << '\n'; 
    cout << p.odleglosc(punkt()) << '\n'; 
    
    punkt t[] = { punkt(0, 1), punkt(0, 0), punkt(1, 0), punkt(1, 1) }; 
    wielobok w1(t, t+4); 
    cout << w1.obwod() << '\n'; 
    
    w1.Punkt(1) = punkt(0.5, 0.5); 
    cout << w1.obwod() << '\n'; 
    
    wielobok w2; 
    w2.Punkty(t, t+3); 
    cout << w2.obwod() << '\n'; 
    for (int i = 0; i < w2.ilosc(); ++i) 
        cout << w2.Punkt(i).x() << ' ' << w2.Punkt(i).y() << '\n'; 

     return 0;
}
