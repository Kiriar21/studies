#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	int a = 30, b = 20, w=0;
	if (a >= b) w = 10;
	cout << "zad1. C++ -> " << w << endl;
	w = 0;
	__asm {

		mov eax, a;
		mov ebx, b;
		cmp eax, ebx;
		jl koniec
			mov eax, w;
			add eax, 10; 
			mov w, eax;
		koniec:
		ret
	}
	cout << "zad1. assembly -> " << w << endl;
	w = 0;
	if (a != b) w = a * b;
	else w = 0;
	cout << "zad2. C++ -> " << w << endl;
	w = 0;
	__asm {
		mov eax, a;
		mov ebx, b;
		cmp eax, ebx;
		mov eax, 0;
		je koniec1
			imul eax, ebx;
			mov w, eax;
		koniec1:
		ret
	}
	cout << "zad2. assembly -> " << w << endl;
	system("PAUSE");
	return 0;
}
