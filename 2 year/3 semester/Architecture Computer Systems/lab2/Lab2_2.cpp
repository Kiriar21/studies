#include <iostream>
#include <emmintrin.h>
#include <immintrin.h>
struct tmpData{
    unsigned int id;
    std::string imie;
    std::string nazwisko;
    
};

int main() {
    tmpData r;
    r.imie="x", r.nazwisko="xx", r.id=1;
    size_t rozmiar = sizeof(r.imie)+sizeof(r.nazwisko)+sizeof(r.id);
    std::cout<<"Rozmiar miejsca dla int double int = "<<rozmiar<<" bajtów. Natomiast dla struktury wynosi: ";
    std::cout<<sizeof(tmpData)<<std::endl;
    // Z moich obserwacji wynika, że rozmiar struktury przyjmuje (rezerwuje miejsce) na zmienne tyle bitów ile potrzeba dla najcieższej zmiennej (najwięcej bajtów potrzeba do zapisania w pamięci)  
    // Z przypadku, gdy mamy int double int, to int przyjmie 8 B double 8 B int 8 B  i wyjdzie rozmiar 24 B - inty zostaną zapisane w pamięci na 8 B pomimo że potrzebują tylko 4, i z racji tego, że kolejna zmienna potrzebuje 8B to zostanie się puste miejsce pomiędzy tym intem i doublem
    // Natomiast w przypadku, gdy mamy int int double, to rozmiar struktury wynosi 16 B , dlatego, że dwa inty zmieszczą się w jednej zarezerwowanej pamięci 8 Bajtów a na drugie 8 B wejdzie ostatni double 
    // To samo będzie w przypadku, gdy double zrobimy pierwsze a potem int int
    // Wniosek: zapis zmiennych w strukturze jest bardzo ważny, tak aby nie rezerwować niepotrzebnego miejsca, więc trzeba je rozsądnie zapisywać

    return 0;
}