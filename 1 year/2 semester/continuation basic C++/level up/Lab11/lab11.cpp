#include <iostream>
#include <fstream>

using namespace std;

struct Sobiektyw{
	string nazwa;
	float przeslona;
	unsigned ogniskowa;
};

struct SAparat{
	string nazwa;
	unsigned n;
	Sobiektyw* zestaw;
};

bool wczytaj(const string nazwa, SAparat& aparat){
	ifstream fin(nazwa);
	if(!fin.good()){
		cerr<<"Blad otwarcia pliku wejsciowego.\n";
		fin.clear();
		fin.close();
		return false;
	}
	else{
		fin>>aparat.nazwa>>aparat.n;
		aparat.zestaw= new Sobiektyw[aparat.n];
		for(unsigned i=0;i<aparat.n;i++){
			fin>>aparat.zestaw[i].nazwa>>aparat.zestaw[i].przeslona>>aparat.zestaw[i].ogniskowa;
			cout<<"Nazwa: "<<aparat.zestaw[i].nazwa<<", przeslona: "<<aparat.zestaw[i].przeslona<<", ogniskowa: "<<aparat.zestaw[i].ogniskowa<<endl;
		}
		cout<<"Wczytywano poprawnie \n";
		return true;
	}
}

bool wypisz(ostream& fin, SAparat& aparat){
	if(!fin.good()){
		cerr<<"Blad zapisu pliku wyjsciowego.\n";
		return false;
	}
	else{
		fin<<aparat.nazwa<<endl<<aparat.n<<endl;
		for(unsigned i=0;i<aparat.n;i++){
			fin<<aparat.zestaw[i].nazwa<<endl;
			fin<<aparat.zestaw[i].przeslona<<" : "<<aparat.zestaw[i].ogniskowa<<endl;
			}
		cout<<"Wczytywano poprawnie \n";
		return true;
	}
}

unsigned zlicz(SAparat& aparat){
	unsigned licznik=0;
	for(unsigned i=0; i<aparat.n;i++){
		if(aparat.zestaw[i].ogniskowa>50) licznik++;
	}
	return licznik;
}
void usun(SAparat& aparat){
	if(aparat.zestaw != 0) delete [] aparat.zestaw;
	aparat.zestaw=0;
}

int main(int argc, char** argv){

	SAparat aparat;
	if(wczytaj(argv[1], aparat)){
		wypisz(cout, aparat);
		cout << zlicz(aparat);
		ofstream plik(argv[2]);
		if(!plik)
			cerr << "Zapis zakonczony bledem";
		else
			wypisz(plik, aparat);
		usun(aparat);
	}
	return 0;
}
