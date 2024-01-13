#include <iostream>
using namespace std;

float fun_w1(float a, float b, float c, float d, float x) {
    float y=0.0;
    __asm {
        fld d; //d
        fld x; // x; d
        fld st; // x; x; d
        fmul st, st(1); // xx; x; d
        fld st(1);  // x; xx; x; d
        fmul st, st(1);  // xxx; xx; x; d
        fmul a; // axxx; xx; x; d
        faddp st(3), st; // xx; x; axxx+d
        fmul b; // bxx; x; axxx+d
        faddp st(2), st; //x; axxx+d+bxx
        fmul c; // cx; axxx+d+bxx
        fadd; // axxx+d+bxx+cx
        fstp y;
    }
    return y;
}

double fun_w2(double* x, double* z, int N)
{
    double wynik;
    __asm {
        mov ecx, N; //rozmiar
        mov esi, x;
        mov edi, z;
        fld qword ptr[esi]; //x
        fld qword ptr[edi]; //z; x
        fmul; //;s=x*z
        dec ecx;
    label1:
        add esi, 8; //kolejny element x
        add edi, 8; //kolejny element z
        fld qword ptr[esi]; //;x; s
        fmul qword ptr[edi]; //;x*z; s
        fadd;
        dec ecx;
        jnz label1
    fstp wynik;
    }
    return wynik;


}

double fun_w2_v2(double* x, double* z, int N)
{
    double wynik = 0.0;

    __asm {
        mov ecx, N; //rozmiar
        mov esi, x;
        mov edi, z;
        xorpd xmm0, xmm0 // Zerowanie sumy

            label1 :
        movapd xmm1, [esi]; // Wczytanie dwóch kolejnych elementów x
        movapd xmm2, [edi]; // Wczytanie dwóch kolejnych elementów z

        mulpd xmm1, xmm2; // Mnożenie dwóch wektorów SIMD

        addpd xmm0, xmm1; // Dodanie wyniku do sumy

        add esi, 16; // Przesunięcie wskaźnika x o 16 bajtów (2 * sizeof(double))
        add edi, 16; // Przesunięcie wskaźnika z o 16 bajtów (2 * sizeof(double))

        sub ecx, 2;
        jnz label1;

        haddpd xmm0, xmm0; // Horizontalne sumowanie wyników
        movsd qword ptr[wynik], xmm0; // Zapisanie wyniku do zmiennej wynikowej
    }

    return wynik;
}


int main()
{
    cout << "Hello World!\n";
    float a = 7, b = 13, c = 14, d = 15, x = 55, wynikCPP = 0, wynikASM = 0;
    wynikCPP = (a * (x * x * x)) + (b * (x * x)) + (c * x) + d;
    cout << "ax^3+ax^2+cx+d\n";
    cout << "Wynik cpp:" << wynikCPP << endl;
    wynikASM = fun_w1(a, b, c, d, x);
    cout << "Wynik asm:" << wynikASM << endl;




    cout << "4/3pir^3" << endl;
    float pi = 3.14 , r = 5.1;
    float objKulicpp = (4.0 / 3.0) * pi * pow(r,3);
    float objKuliasm = 0.0;
    int pom1 = 3, pom2 = 4;
    __asm {
        fld r; // r
        fld r;
        fmul st, st; // r*r; r
        fmulp st(1), st; // r*r*r
        fld pi; // pi ; r*r
        fmulp st(1), st; // pi*r*r
        fild pom2;  // 4 ; pirr
        fild pom1; // 3; 4; pirr
        fdiv; // 4/3 ; pirr
        fmul; // 4/3*pirr
        fstp objKuliasm;
    }
    cout << "Objetosc cpp: " << objKulicpp << "\nObjetosc asm: " << objKuliasm << endl;

    cout << "4pir^2";
    float poleKulicpp = 4.0 * pi * pow(r,2);
    float poleKuliasm = 0.0;
    __asm {
        fld r; // r 
        fmul st, st; // r*r
        fld pi; // pi; r*r
        fmulp st(1), st;  // pirr
        fild pom2; // 4 ; pirr
        fmul st, st(1); // 4; 4*pirr
        fstp st(1);
        fstp poleKuliasm;
    }
    cout << "Kula pole cpp: " << poleKulicpp << "\n Kula pole asm: " << poleKuliasm << endl;



    //Wrzuta inta w kodzie 32 bit assembler ukochany nasz <3
    cout << "TESTTESTTESTTESTTESTTESTTEST\n";
    float test = 0.0;
    __asm {
        mov eax, 1111;
        push eax;
        fild [esp];
        pop eax;
        fstp test;
    }
    cout << test;
    cout << "\nTESTTESTTESTTESTTESTTESTTEST\n";

    cout << " zad 4 lab 9 \n";

    double zad5 = (pow((a - 1), 2) * x) + ((c * b) - (a * c)) + ((a * c) - (a * b));
    double zad5_asm = 0.0;
    __asm {
        // st st(1) st(2) st(3)...
        

        //((a * c) - (a * b))
        fld a; // a
        fld c; // c; a
        fmulp st(1), st; // a*c;
        fld b; // b; a*c
        fld a; // a; b; a*c
        fmulp st(1), st; // a*b; a*c;
        fsubp st(1), st; // a*c-a*b;
        

        //((c * b) - (a * c))
        fld c; // c; a*c-a*b;
        fld b; // b; c; a*c-a*b;
        fmulp st(1), st; // b*c; a*c-a*b;
        fld a; // a; b*c; a*c-a*b;
        fld c; // c; a; b*c; a*c-a*b;
        fmulp st(1), st; // b*c; a*c; a*c-a*b;
        fsubp st(1), st; // b*c-a*c; a*c-a*b;


        // ((c * b) - (a * c)) + ((a * c) - (a * b))
        faddp st(1), st; // (b*c-a*c)+(a*c-a*b)
        
        //pow((a - 1), 2) * x)
        
        fld a; // a;  (b*c-a*c)+(a*c-a*b)
        fld1;  // 1; a;  (b*c-a*c)+(a*c-a*b)
        fsubp st(1), st; // a-1;  (b*c-a*c)+(a*c-a*b)
        fmul st, st; // (a-1)*(a-1);  (b*c-a*c)+(a*c-a*b)
        fld x; // x;  (a-1)*(a-1);  (b*c-a*c)+(a*c-a*b)
        fmulp st(1), st; //  (a-1)*(a-1)*x;  (b*c-a*c)+(a*c-a*b)


        //(pow((a - 1), 2) * x) + ((c * b) - (a * c)) + ((a * c) - (a * b))
        faddp st(1), st; //(a-1)*(a-1)*x + (b*c-a*c)+(a*c-a*b)
        fstp zad5_asm;

        
    }
    cout << "cpp:" << zad5 << " asm: " << zad5_asm << endl;


    cout << "zad5\n";

    float prostopadloscianV = a * b * c;
    float prostopadloscianVass = 0.0f;
    float ppbp = 2 * ( (a * b) + (a * c) + (b * c));
    float ppbpass = 0.0f;
    __asm {
        fld a; // a
        fld b; // b; a;
        fmulp st(1), st; // a*b
        fld c; // c; ab
        fmulp st(1), st; //a*b*c
        fstp prostopadloscianVass;
        fld a; // a
        fld b;  // b; a;
        fmulp st(1), st; // b*a
        fld a; // a; ba
        fld c; // c; a; ba
        fmulp st(1), st; // ca; ba
        faddp st(1), st; // ca+ba
        fld b; // b; ca+ba
        fld c; // c; b; ca+ba
        fmulp st(1), st; // cb; ca+ba
        faddp st(1), st; // cb+ca+ba
        mov eax, 2;
        push eax;
        fild[esp]; // 2;cb+ca+ba 
        pop eax;
        fmulp st(1), st; // 2* cb + ca + ba
        fstp ppbpass;
    }
    cout << "prostopadloscian c++ \n" << prostopadloscianV << " " << ppbp << endl;
    cout << "prostopadloscian assembler \n" << prostopadloscianVass << " " << ppbpass << endl;


    cout << "zad6\n";

    int n = 10;
    double* tab = new double[n];
    double* tab1 = new double[n];

    for (int i = 0; i < n; i++) {
        tab[i] = (double)rand()/1000;
        tab1[i] = (double)rand()/1000;
    }

    //test wstawienia randa 
    for (int i = 0; i < n; i++) {
        cout << tab[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << tab1[i] << "\t";
    }
    cout << endl;

    double sumaWektorowDoubleRozwiazanie1 = fun_w2(tab, tab1, n);
    double sumaWektorowDoubleRozwiazanie2 = fun_w2_v2(tab, tab1, n);

    cout << "Suma rozwiazania z labow: " << sumaWektorowDoubleRozwiazanie1 << endl;
    cout << "Suma rozwiazania z labow v2: " << sumaWektorowDoubleRozwiazanie2 << endl;

    delete[] tab;
    delete[] tab1;
}
