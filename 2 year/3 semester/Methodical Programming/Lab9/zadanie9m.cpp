#include <iostream>
using namespace std;

int main()
{
  Paczka p[] = {
    Paczka("Dabrowskiego 33", 123.00), 
    Paczka("NMP 12", 40.00),
    Paczka("Armii Krakowej 4", 30.00), 
    Paczka("Andersa 6", 51.00),
    Paczka("Kukuczki 13", 12.00), 
    Paczka("Skrzyneckiego 5", 40.00), 
  };

  Osoba o1("Jan", "Kowalski");
  cout << "---- 1 ----" << endl;
  cout << o1 << endl;
  
  {
      Osoba o2(o1);
      cout << "---- 2 ----" << endl;
      cout << o2 << endl;
      
      cout << "---- 3 ----" << endl;
      cout << boolalpha << (o1 == o2) << endl;
      
      Osoba o3;
      cout << "---- 4 ----" << endl;
      cout << o3 << endl;

      o3 = o2;
      cout << "---- 5 ----" << endl;
      cout << o3 << endl;
      
  }   

  cout << "---- 6 ----" << endl;
  cout << o1 << endl;
      
  Kurier k1(p, p+3);
  cout << "---- 7 ----" << endl;
  cout << k1.wartosc() << endl;

  Kurier k2;
  cout << "---- 8 ----" << endl;
  cout << k2.wartosc() << endl;

  {
    Kurier k3(k1);
    cout << "---- 9 ----" << endl;
    cout << k3.wartosc() << endl;

    k2 = k3;
    cout << "---- 10 ----" << endl;
    cout << k2.wartosc() << endl;

    k1 = k1 + p[4]; 
    k1 = k1 + p[5];

    cout << "---- 11 ----" << endl;
    cout << k1.wartosc() << endl;

  }

  cout << "---- 12 ----" << endl;
  cout << k2.wartosc() << endl;

  try{
    Kurier k4(p, p+3);
    cout << "---- 13 ----" << endl;
    for(int i=0; i<10; ++i){
      cout << k4[i] << ",";
    }
    cout << endl;
  }
  catch(...){
    cout << "---- 14 ----" << endl;
    cout << "Wyjatek" << endl;
  }

  return 0;
}
