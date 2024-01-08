#include <iostream>

using namespace std;

int main()
{
    unsigned int a = 10;
    unsigned int b = 20;
    unsigned short g = 10;
    unsigned short gg;
    __asm {
        push ebx;
        xor ecx, ecx;
        mov ebx, ecx;
        mov eax, 0xaaff;
        mov eax, 0aaffh;
        mov ebx, eax;
        inc eax;
        inc eax;
        dec ecx;
        dec eax;
        cmp ebx, 0;
        //jnz skok;
        mov ax, g;
        inc ax;
        mov ebx, eax;
        mov gg, bx;
   // skok: mov eax, a;
        // mov ebx, b;
       // cmp eax, ebx;
        //sub eax, b;
        //mul ecx;
       // div eax;
        pop ebx;
    }
    cout << a << "; " << b << endl;
    system("PAUSE");
    return 0;
}
