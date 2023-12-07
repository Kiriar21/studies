#include <iostream>
using namespace std;

int main()
{
  Osoba o1;
  cout << "---- 1 ----" << endl;
  cout << o1 << endl;

  Osoba o2("Jan", "Kowalski", 11111111111);
  cout << "---- 2 ----" << endl;
  cout << o2 << endl;
      
  cout << "---- 3 ----" << endl;
  cout << boolalpha << (o1 == o2) << endl;

  BazaDanych db1;
  cout << "---- 4 ----" << endl;
  cout << db1;
  
  db1 = db1 + o1;
  cout << "---- 5 ----" << endl;
  cout << db1;
  
  ifstream plik_we("zadanie6.txt");
  if(!plik_we)
  {
    cout << "---- 6 ----" << endl;
    return 1;
  }
  
  while(plik_we >> o2)
  {
      db1 = db1 + o2;
  }
  cout << "---- 7 ----" << endl;
  cout << db1;
  
  {
      BazaDanych db2(db1);
      cout << "---- 8 ----" << endl;
      cout << db2;
  }
  cout << "---- 9 ----" << endl;
  cout << db1;
  
  BazaDanych db3;
  db3 = db1 + db1
  cout << "---- 10 ----" << endl;
  cout << db3;
  
  for(int i=0; i<db3.liczbaOsob(); ++i)
  {
      cout << db3[i] << endl; 
  }
  cout << "---- 11 ----" << endl;  
  
  db1 = db1 - o1;
  cout << "---- 12 ----" << endl;
  cout << db1;
  
  cout << "---- 13 ----" << endl;
  cout << db3;
  cout << "---- 14 ----" << endl;
  
  return 0;
}
