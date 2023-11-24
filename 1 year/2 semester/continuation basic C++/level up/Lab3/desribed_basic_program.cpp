// kompilacja : clear; g++ -Wall -pedantic -g -o nazwa nazwa.cpp
// uruchamianie ze sprawdzaniem czy są wycieki pamięci:
// clear; valgrind --leak-check=full ./nazwa
// polecenie clear służy do czyszczenia konsoli i można jes stosować wedle uznania. 
#include <iostream>
#include <ctime> //time
#include <cstdlib> // srand, rand
#include <cmath> // abs

using namespace std;

void wypisz(const int* t, const unsigned n)
{
    for(unsigned i = 0 ; i < n; ++i)
    cout << t[i] << '\t';
    cout << endl;
}
int* utworz1(const unsigned int n)  //przyjmuje tylko rozmiar tablicy wewnątrz funkcji musimy przydzielić dynamicznie pamięć, tworzenie obiektów dynamicznych odbywa się za pomocą operatora new
{   // operator new zwraca adres tablicy, a jak wiemy adres może być przypisany tylko i wyłącznie pod wskaźnik
    int* t = new int [n]; // definiujemy sobie że t będzie wskaźnikiem na liczby całkowite, a skoro jest wskażnikiem to możemy przypisać do niego adres zwracany przez operator new, ten adres będzie wskazywał na ciągły obszar pamięci która będzie rezerwowana dla n liczb całkowitych.
    // Po stworzeniu dynamicznej tablicy możemy wyzerować wszystkie elementy tej tablicy:
    for(unsigned i = 0 ; i < n; ++i) // dlatego, że pamiętamy o tym że obiekty dynamiczne nie są zerowe i nie mają ustawionych wartości początkowych.
    t[i] = 0; //Dlatego zawsze trzeba zadbać o to aby dynamicznie tworzone obiekty od razu miały nadane wartości początkowe.
    return t; // pierwsza funkcja utworz1 zwraca t
}
void utworz2(int*& t, const unsigned int n) // funkcja nic nie zwraca, natomiast przyjmuje wskaźnik ale przez referencję i pod ten wskaźnik będziemy przydzielać pamieć oraz rozmiar tablicy.
{ // w przeciwieństwie do funkcji utwurz1 ta funkcja wskaźnik już przekazuje "*&" czyli ten wskaźnik pod który będziemy przypisywać adres // zwracamy przez operator new będzie, ten wskaźnik jest już znany więc w przeciwieństwie do naszej pierwszej funkcji utworz1 nie musimy go definiować, bo wiemy że jest to wskaźnik który wskazuje na "int *& t" obiekty typu całkowitego w związku z tym uzywamy tylko nazwy, bo ta nazwa jest znana
    t = new int[n]; // to co zwraca nam operator new czy;i adres do n elementów całkowitych i następnie poniżej zerujemy elementy tej tablicy.
    for(unsigned i = 0 ; i < n; ++i)
    t[i] = 0;
}
void utworz3(int* t, const unsigned int n) // ta funkcja różni się od utworz1 tylko tym że nie posiada referencji, czym te funkcje się różnią tym, że w funkcji utworz2 przypisanie " t=new int[n] " jest widoczne poza funkcją, gdyby nie było by referencji to tak jak w utworz3 to takie przypisanie nie było by widoczne .
{
    for(unsigned i = 0 ; i < n; ++i)
    t[i] = 0;
}

void usun( int* t) // zdefiniowaliśmy sobie funkcję która zwalnia zasoby przydzielone na stercie, czyli te zasoby na które wskazuje wskaźnik, przechowujący adresy zwracane przez operator new, dlatego tworzymu funkcje 'usun" usuwająca pamięć,
{ // żeby cokolwiek usunac z pod wskaźnika w pierwszej kolejności musimy sprawdzić czy pod tym wskaźnikiem coś jest
    if(t) // jeśli coś pod tym wskaźnikiem jest
    {
        delete[] t; // dopiero wstedy możemy usunac pamieć tablicy na, który wskazuje i
        t = nullptr; // oczywiście  od razu pamiętamu żeby wskaźnik wyzerować, czyli żeby znowu stał się bezpieczny.
    }
}
void wypelnij(int* t, const unsigned n)
{
    for(unsigned i = 0 ; i < n; ++i)
    t[i] = rand() % 100; // generujemy liczby z zakrasu 0-99
}
void wypelnij2(int* t, const unsigned n, const int a, const int b) // a i b będą to odpowiednio nasz dolna i górna granica przedziałuz którego bedziemy generować nasze liczby
{
    for(unsigned i = 0 ; i < n; ++i)
    t[i] = a+ rand() % abs(b - a); // dodajemy to co rand modulo zrwóci nam długość naszego przediału. (b-a) odejmujemy od końca przedziału początrk przediału. musimy pamiętać że długośc przedziału nie może być ujemna, tak samo jak rozmiar. Aby uzyskac wartosć dodatnia to musimy wykorzytać wartosć bezwzględna czyli w c++ to "abs".
}
int main()
{   // srand uruchamia generator liczb psełdolosowych uruchamiana jest zawsze z tak zwanym ziarnem  to ziarno trzeba ustawić, mówi nam ono o tym jak często i jak szybko zmienia nam się zapalnik do generatora, jak szybko zmieniają nam się wartości w naszym przypadku ziarnem będzie liczba bo domyślnie operujemy w programie na liczbach.
    srand(time(NULL));// żeby odwywało się to czesto uzywa się jako wywołanie funkcji "time"z wartością "NULL" - zero
    unsigned N, A, B;
    cout << "Podaj wartość N, A, B:" << endl;
    cin >> N >> A >> B;
    int* T = utworz1(N); // definiujemy sobie wskaźnik na liczbę całkowitą oraz nadajemy mu nazwę, wewnątrz funkcji main pod naszym T będzie znajdować się adres.
    wypelnij(T, N);
    wypisz(T, N);
    
    int* T1 = nullptr; // definiujemy sobie wskaźnik który będzie się nazywał T1, ten wskażnik ustawiamy na niczym czyli nullptr(podstawiamy zero) //nullptr jest to specjalna zmiennaktóra utworzona służy do zerowania wskaźnika , oznacza to, że dzięki tej operacji wskażnik nie wskazuje na żaden obszar pamięci w komputerze. W konsekwencji taki wskaźnik jest bezpieczny i można go użyć w dowolnym miejscu naszego programu.
    utworz2(T1, N); // majać już wskaźnik wywołujemy funkcję utworz2 i przekazujemy do niej wskaźnik i rozmiar
    wypisz(T1, N); // wypisujemy sobie to co uzyskaliśmy.
    
    int* T2 = nullptr; // powinno być nullptr
    utworz2(T2, N);
    wypelnij2(T1, N, A, B); // przekazujemy T1 czyli ta którą stworzyliśmy , rozmiar, przekazyjemy dolna granicze czyli "A" oraz górną granicę czyli "B"
    wypisz(T2, N);
    
    usun(T); // wywołujemy funkcjię usuń i musimy najpeirw usunać wskaźnik T
    usun(T1); // potem usuwamy wskaźnik T1
    usun(T2); // oraz usuwamy wskaźnik T2
    
    return 0;
}

