#include <iostream>
#include <emmintrin.h>
#include <immintrin.h>
int main() {

    // Zadanie 1
    //  char tmp;
    // int tmp;
    // float tmp;
    // double tmp;
    //__m128i tmp;
    // __m256i tmp; 
    // unsigned int tmp;
    std::string tmp;
    

    for(int i = 0; i<8; ++i) {
        int granica = 1 << i;

        //pobieramy adres zmiennej „tmp” i zapisujemy jego wartość w zmiennej „adres”
        long long adres = (long long)&tmp;
        
        std::cout<<"Czy adres: ";
        std::cout<<adres;
        std::cout<<" jest dopasowany do granicy ";
        std::cout<<granica;
        std::cout<<" bajtow? ";
        std::cout<<std::endl;
        if(adres % granica) {
            std::cout<<"Adres nie jest dopasowany do badanej granicy "<<granica<<" bajtow.";
        } else {
            std::cout<<"Adres jest dopasowany do badanej granicy "<<granica<<" bajtow.";
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
    }

    // --------------- char ---------------
    // Adres jest dopasowany do granicy 1 bajta
    // --------------- int ---------------
    // Adres jest dopasowany do granicy 4 bajtów
    // --------------- float ---------------
    // Adres jest dopasowany do granicy 4 bajtów
    // --------------- double ---------------
    // Adres jest dopasowany do granicy 8 bajtów
    // --------------- __m128i ---------------
    // Adres jest dopasowany do granicy 16 bajtów
    // --------------- __m256i ---------------
    // Adres jest dopasowany do granicy 64 bajtów

    return 0;
}