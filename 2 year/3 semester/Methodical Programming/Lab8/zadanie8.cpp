#include <iostream>
using namespace std;

class Osoba{
	private:
		string _nazwisko;
		int _liczba_lat;
	public:
		Osoba(){}
		Osoba(string n, int w):_nazwisko(n), _liczba_lat(w){}
		string &nazwisko(){ return _nazwisko; }
		int liczba_lat(){ return _liczba_lat; }
		const string &nazwisko() const  { return _nazwisko; }
		const int &liczba_lat() const { return _liczba_lat; }
		void pokaz()
		{
			cout<<this->_nazwisko<<"\t"<<_liczba_lat<<endl;
		}
};
class Pracownik: public Osoba{
	private:
		string _stanowisko;
		float _placa;
	public:
		Pracownik(){}
		// Pracownik(string n, int w, string s, int p){
		// 	Osoba(n,w);
		// 	_stanowisko = s;
		// 	_placa = p;
		// }
		Pracownik(string n, int w, string s, float p):Osoba(n,w),_stanowisko(s),_placa(p){}
		string &stanowisko() { return _stanowisko; }
		float placa() { return _placa; }
		const string &stanowisko() const { return _stanowisko; }
		const float &placa() const { return _placa; }
		void pokaz(){
			cout << this->_stanowisko << "\t" << this->_placa << " " << this->nazwisko() << " " << this->liczba_lat() << endl;
		}
};
int main()
{
	Osoba os("Dolas", 26);
	cout << " -------------- 1 ------------------\n";
	os.pokaz();
	const Pracownik pr1("Dyzma", 35, "mistrz", 1250.0);
	cout << " -------------- 2 ------------------\n";
	cout << pr1.nazwisko() << " " << pr1.liczba_lat() << " ";
	cout << pr1.stanowisko() << " " << pr1.placa() << endl;
	Pracownik pr2(pr1);
	cout << " -------------- 3 ------------------\n";
	pr2.pokaz();
	Pracownik pr3("Kos", 45, "kierownik", 2260.0);
	cout << " -------------- 4 ------------------\n";
	pr3.pokaz();
	pr3 = pr2;
	cout << " -------------- 5 ------------------\n";
	pr3.pokaz();
	Osoba* w = &os;
	cout << " -------------- 6 ------------------\n";
	w->pokaz();
	w = &pr3;
	cout << " -------------- 7 ------------------\n";
	w->pokaz();
	cout << " -------------- 8 ------------------\n";
	static_cast<Pracownik*>(w)->pokaz();
	
	return 0;
}
