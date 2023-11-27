#include <iostream>
#include <emmintrin.h>
#include <immintrin.h>
struct tmpData{
    int c;
    char a;
    char e;
    //Pierwsze 3 zmienne zajmą miejsce 6 B na miejscu 8 B i kolejne będa 2x double
    double b;
    double d;
    //Lub
    // double b;
    // double d;
    // int c;
    // char a;
    // char e;
};
//Łącznie ten zapis zajmie 24 B
// Pierwszy główny zapis zajmował 40B

int main() {
    std::cout<<sizeof(tmpData)<<std::endl;
    return 0;
}