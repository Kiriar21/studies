#include <iostream>
using namespace std;

class adres{
	private:
		string _miasto,_kod,_ul;
		int _nr;
	public:
		adres(): _nr(0){}
		adres(const string &m, const string &k, const string &u, const int &nr):_miasto(m),_kod(k),_ul(u),_nr(nr){}
		friend ostream &operator<<(ostream &cout, const adres &a1);
};
ostream &operator<<(ostream &cout, const adres &a1){
	return cout << " Miasto: " << a1._miasto << " ul. " << a1._ul << " " << a1._nr << " kod pocztowy: " << a1._kod << endl;
}
class osoba{
	private:
		string _imie, _nazwisko;
		int _wiek;
		adres _a1;
	public:
		osoba():_wiek(0){}
		osoba(const string& i,const string& n, const int& w, const adres& a1):_imie(i),_nazwisko(n),_wiek(w),_a1(a1){}
		friend ostream &operator<<(ostream &cout, const osoba &a1);
}; 
ostream &operator<<(ostream &cout, const osoba &a1){
		return cout << "Imie: " << a1._imie << "\n Nazwisko: " << a1._nazwisko << "\n Wiek: " << a1._wiek << endl << a1._a1;
}

int main()
{
	adres* wsk = new adres("Czestochowa", "42-200", "Dabrowskiego", 73);
	cout<<"*wsk:\n";
	cout << *wsk << '\n';
	adres a1(*wsk);
	cout << "a1:\n";
	cout << a1 << '\n';
	delete wsk;

	const adres* wsk1 = new adres("Warszawa", "00-950", "Mysliwiecka", 357);
	cout << "a1:\n";
	cout << a1 << '\n';
	cout << "*wsk1:\n";
	cout << *wsk1 << '\n';

	adres a2;
	cout << "a2:\n";
	cout << a2 << '\n';
	a2 = a1;
	cout << "drugie a2:\n";
	cout << a2 << '\n';

	osoba o("Jan", "Kos", 25, *wsk1);
	cout << "o:\n";
	cout << o << '\n';
	osoba o1(o);
	cout << "o1:\n";
	cout << o1 << '\n';

	osoba o2;
	cout << "o2:\n";
	cout << o2 << '\n';
	o2 = o1;
	cout << "drugie o2:\n";
	cout << o2 << '\n';
	delete wsk1;
	
	return 0;
}
