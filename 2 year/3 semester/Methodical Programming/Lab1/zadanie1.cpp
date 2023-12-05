#include<iostream>
#include<fstream>
using namespace std;

struct Student{
	string imie, nazwisko;
	unsigned nr_indexu;
};
Student* pobierz(istream& plik, unsigned &howManyStudent){
	plik>>howManyStudent;
	Student* studenci = new Student[howManyStudent];
	for(unsigned i=0;i<howManyStudent;i++){
		plik>>studenci[i].imie>>studenci[i].nazwisko>>studenci[i].nr_indexu;
	}
	return studenci;
}
void wyswietlJednego(Student &student,ostream& jak){
	jak<<"Imie i nazwisko: "<< student.imie<< " " << student.nazwisko<<endl;
	jak<<"Numer indeksu " << student.nr_indexu<<endl; 
}
void wyswietl(Student* studenci, const unsigned howManyStudent, ostream& jak){
		for(unsigned i=0;i<howManyStudent;i++){
			wyswietlJednego(studenci[i],jak);
		}
}
void zapisz(ostream& jak, const unsigned howManyStudent, Student* studenci){
	wyswietl(studenci,howManyStudent,jak);
}
void usun(Student* studenci){
	delete [] studenci;
	studenci = nullptr;
}
void edytuj(Student* studenci, const unsigned ktory){
	cout<<"Edycja imienia\n\n";
	cout<<studenci[ktory].imie<<endl;
	cin>>studenci[ktory].imie;
	cout<<studenci[ktory].nazwisko<<endl;
	cin>>studenci[ktory].nazwisko;
	cout<<studenci[ktory].nr_indexu<<endl;
	cin>>studenci[ktory].nr_indexu;
}
int main(int argc,char**argv){
	if(argc!=3){
		cerr<<"Blad"<<endl;
		return 0;
	}
	ifstream plikWejsciowy(argv[1]);
	if(!plikWejsciowy.good()){
		cout<<"Blad pliku"<<endl;
		plikWejsciowy.clear();
		plikWejsciowy.ignore();
		plikWejsciowy.close();
	}
	unsigned howManyStudent=0;
	Student* studenci=pobierz(plikWejsciowy,howManyStudent);
	ofstream plikWyjsciowy(argv[2]);
	if(!plikWyjsciowy.good()){
		cout<<"Blad.\n";
		plikWyjsciowy.clear();
		plikWyjsciowy.close();
	}
	int ktoryStudent=-1;
	wyswietl(studenci, howManyStudent, cout);
	cout<<"Ktorego studenta chcesz edytowac? (zeby wyjsc wcisnij 10) \n\n";
	cin>>ktoryStudent;
	edytuj(studenci, ktoryStudent-1);

	zapisz(plikWyjsciowy,howManyStudent,studenci);
	usun(studenci);
	plikWejsciowy.clear();
	plikWejsciowy.ignore();
	plikWejsciowy.close();
	plikWyjsciowy.clear();
	plikWyjsciowy.close();
	
	return  0;

}
