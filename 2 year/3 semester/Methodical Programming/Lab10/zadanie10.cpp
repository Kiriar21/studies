#include <iostream>

using namespace std;

class operacja{
	private:
		string _operacja;
		int _iloscRuch;
	public:
		operacja(){}
		operacja(string o, int i):_operacja(o), _iloscRuch(i){}
		string &co() { return _operacja; }
		int &ilosc() { return _iloscRuch; }
		const string &co() const { return _operacja; }
		const int &ilosc() const { return _iloscRuch; }
};

class robot{
	private:
		
	public:
		robot(){}
		virtual ~robot(){}
		virtual void praca(){}
};

class podajnik: public robot{
	private:
		int _id;
	public:
		podajnik(){}
		podajnik(int id):_id(id) {}
		~podajnik(){}
		int id(){ return _id; }
		const int id() const { return _id; }
		void praca(){
			cout << "\n--------------------------------------\nIdentyfikator podajnika: " << this->_id << "\n--------------------------------------\n";
		}
};

class robot1R: public robot{
	private:
		int _id, _ilosc;
		operacja* _akcje;
	public:
		robot1R(){}
		robot1R(int id, operacja* poczatek, operacja* koniec){
			this->_id = id;
			this->_ilosc = koniec - poczatek;
			this->_akcje = new operacja[_ilosc];
			for (int i = 0; i < this->_ilosc; i++)
			{
				this->_akcje[i] = *poczatek;
				poczatek++;
			}
		}
		~robot1R(){ delete [] _akcje;}
		void praca(){
			cout<<"\nIdentyfikator ramienia: "<<this->_id<<endl;
			for (int i = 0; i < this->_ilosc; i++)
			{
				cout<<"Ramie wykonuje ruch: "<<this->_akcje[i].co()<<" o liczbe jednostek: "<<this->_akcje[i].ilosc()<<endl;
			}
			cout<<"\nKoniec pracy tego robota.\n\n\n";
		}
};

class robot2R: public robot{
	private:
		int _id, _ilosc1R, _ilosc2R;
		operacja* akcja1R;
		operacja* akcja2R;
	public:
		robot2R(){}
		robot2R(int id, operacja* poczatek1, operacja* koniec1, operacja* poczatek2, operacja* koniec2){
			this->_id = id;
			this->_ilosc1R = koniec1 - poczatek1;
			this->_ilosc2R = koniec2 - poczatek2;
			this->akcja1R = new operacja[this->_ilosc1R];
			this->akcja2R = new operacja[this->_ilosc2R];
			for (int i = 0; i < this->_ilosc1R; i++){
				this->akcja1R[i] = *poczatek1;
				poczatek1++;
			}
			for (int i = 0; i < this->_ilosc1R; i++){
				this->akcja2R[i] = *poczatek2;
				poczatek2++;
			}
		}
		~robot2R(){ delete [] akcja1R; delete [] akcja2R; }
		void praca(){
			cout << "\nIdentyfikator ramienia: " << this->_id << endl;
			for (int i = 0; i < this->_ilosc1R; i++){
				cout << "Lewie ramie wykonuje ruch: " << this->akcja1R[i].co() << " o liczbe jednostek: " << this->akcja1R[i].ilosc() << endl;
			}
			for (int i = 0; i < this->_ilosc2R; i++){
				cout << "Prawe ramie wykonuje ruch: " << this->akcja2R[i].co() << " o liczbe jednostek: " << this->akcja2R[i].ilosc() << endl;
			}
			cout << "\nKoniec pracy tego robota.\n\n\n";
		}
};
void wykonaj(robot** poczatek, robot** koniec){
	int ile = koniec-poczatek;
	for(int i=0; i<ile; i++){
		poczatek[i]->praca();
	}
}
int main()
{
	operacja o[] = {
		operacja("w lewo", 12), operacja("obrot", 8),
		operacja("w gore", 32), operacja("obrot", 10),
		operacja("w prawo", 5), operacja("w dol", 25),
		operacja("obrot", 32), operacja("w gore", 21),
		operacja("obrot", 11), operacja("w prawo", 6)
	};
	
	robot* linia[] = {
		new podajnik(0), new robot1R(1, o, o+3),
		new podajnik(2), new robot2R(3, o+2, o+5, o+3, o+6),
		new podajnik(4), new robot2R(5, o, o+4, o+2, o+6),
		new podajnik(6), new robot1R(7, o+7, o+10),
		new podajnik(8)
	};
	
	wykonaj(linia, linia+9);
	size_t rozmiar = sizeof(linia) / sizeof(linia[0]);
	for (size_t i = 0; i < rozmiar; i++)
	{
		delete linia[i];
	}
	return 0;
}
