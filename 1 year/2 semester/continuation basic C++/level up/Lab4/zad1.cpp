#include<iostream>
#include<cstring>
using namespace std;
/*int dlugosc(const char* str){
	int index = 0;
	while(str[index]!='\0'){
		index++;
	}
	return index;
}*/
char* wstaw(const char* zrodlo, char symbol){
	int index = 0;
	while(zrodlo[index]!='\0'){
		index++;
	}
	char* tempstr = new char[index+1];
	for(int i=0; i<index; i++){
		if((i+1)%3==0) tempstr[i]=symbol;
		else tempstr[i] = zrodlo[i];
	}
	tempstr[index]='\0';
	return tempstr;
}
void wstaw(char* cel, const char* zrodlo, char symbol){
	int index = 0;
	while(zrodlo[index]!='\0'){
		index++;
	}
	cel = new char[index+1];
	for(int i=0; i<index; i++){
		if((i+1)%3==0) cel[i]=symbol;
		else cel[i] = zrodlo[i];
	}
	cel[index]='\0';
}
void wstaw1(char*& cel, const char* zrodlo, char symbol){
	int index = 0;
	while(zrodlo[index]!='\0'){
		index++;
	}
	cel = new char[index+1];
	for(int i=0; i<index; i++){
		if((i+1)%3==0) cel[i]=symbol;
		else cel[i] = zrodlo[i];
	}
	cel[index]='\0';
}
int szukaj(const char* str, const int symbol){
	int s=0, index=0;
	while(str[index]!='\0'){
		if(str[index]==symbol) s++;
		index++;
		}		
	return s;
}
char* kopiuj(const char* str){
	int index = 0;
	while(str[index]!='\0'){
		index++;
	}
	char* tempstr = new char[index+1];
	for(int i=0; i<index; i++){
		tempstr[i] = str[i];
	}
	tempstr[index]='\0';
	return tempstr;
}
void usun(const char* str){
	if(str){
		delete [] str;
		str = 0;
	}
}
int main(int argc, char* argv[]){  // ./nazwa ciagZnakow symbol 
	if(argc!=3){
		cerr<<"Nieprawidlowa ilosc parametrow uruchomienia programu.\n";
		return 1;
	}
	
	//...
	char* a = wstaw(argv[1], argv[2][0]);
	char* b, *c;
	//...
	wstaw(b, argv[1], argv[2][0]);
	wstaw1(c, argv[1], argv[2][0]);
	//...
	cout << a << endl;
	cout << szukaj(a, 's') << endl;
	//...
	a = kopiuj(argv[1]);
	cout << a << endl;
	//...
	usun(a);
	usun(b);
	usun(c);
	return 0;
}
