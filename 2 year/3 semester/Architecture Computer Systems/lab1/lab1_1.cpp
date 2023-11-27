#include <iostream>

#include <bitset>

#include <limits>

#include <iomanip>

#include <cmath>

#include <cstdlib>

template<typename T>

void show_32_bits(T tmp) {

 const unsigned int tmpSize =32;

 unsigned long int bits = *(unsigned long int*) (&tmp);

 std::bitset<(tmpSize)> tmpBits(bits);

 std::cout<<tmpBits <<"\t"<<tmpSize <<" bits"<<"\t"<<std::fixed<<std::setprecision(20)<<tmp<<std::endl;

}

template<typename T>

void show_64_bits(T tmp) {

 const unsigned int tmpSize = 64;

 unsigned long long int bits = *(unsigned long long int*) (&tmp);

 std::bitset<(tmpSize)> tmpBits(bits);

 std::cout<<tmpBits <<"\t"<<tmpSize <<" bits"<<"\t"<<std::fixed<<std::setprecision(20)<<tmp<<std::endl;

}

int main() {

 //modyfykujemy poniższy kod

//ZADANIE 1

 std::cout<<"\n\n\n-----------------------------------   Zadanie 1   ----------------------------------------------------\n\n\n";

 int a = -1;

 int b = 1;

 int c = std::numeric_limits<int>::min();

 int d = std::numeric_limits<int>::min();

 double aa = -100;

 double bb = 100;

 double cc = std::numeric_limits<double>::min();

 double dd = std::numeric_limits<double>::min();

 float aaa = -200;

 float bbb = 200;

 float ccc = std::numeric_limits<float>::min();

 float ddd = std::numeric_limits<float>::min();

 std::cout<<"\n\n\n-----------------------------------   INT 32-bit   \n\n\n";

 show_32_bits(a);

 show_32_bits(b);

 show_32_bits(c);

 show_32_bits(d);

 std::cout<<"\n\n\n-----------------------------------   INT 64-bit  \n\n\n";

 show_64_bits(a);

 show_64_bits(b);

 show_64_bits(c);

 show_64_bits(d);

 std::cout<<"\n\n\n-----------------------------------   DOUBLE 32-bit  \n\n\n";

 show_32_bits(aa);

 show_32_bits(bb);

 show_32_bits(cc);

 show_32_bits(dd);

 std::cout<<"\n\n\n-----------------------------------   DOUBLE 62-bit   \n\n\n";

 show_64_bits(aa);

 show_64_bits(bb);

 show_64_bits(cc);

 show_64_bits(dd);

 std::cout<<"\n\n\n-----------------------------------   FLOAT 32-bit   \n\n\n";

 show_32_bits(aaa);

 show_32_bits(bbb);

 show_32_bits(ccc);

 show_32_bits(ddd);

 std::cout<<"\n\n\n-----------------------------------   FLOAT 64-bit  \n\n\n";

 show_64_bits(aaa);

 show_64_bits(bbb);

 show_64_bits(ccc);

 show_64_bits(ddd);

 std::cout<<"\n\n\n-----------------------------------   Zadanie 2   ----------------------------------------------------\n\n\n";

 int x = -100;

 int yyyy = 91;

 int z=60;

 std::cout<<"-100 w U2 : 10011100 , z programu: ";

 show_32_bits(x);

 std::cout<<"91 w U2 : 1011011 , z programu: ";

 show_32_bits(yyyy);

 std::cout<<"60 w U2 : 111100 , z programu: ";

 show_32_bits(z);

 

 std::cout<<"Roznica pojawia sie tylko w momencie gdy zamieniamy w kompilatorze liczbe ujemna, wtedy puste (niezajete) bity kompilator zamienia z 0 na 1, w przypadku liczb dodatnich kompilator puste niezajete bity zostawia wyzerowane, przyklady wyswietlone bardzo dobrze to prezentuja\n\n\n";

  std::cout<<"\n\n\n-----------------------------------   Zadanie 3   ----------------------------------------------------\n\n\n";

 double xa = 0.1;

 double xb = 0.2;

 double xc = xa + xb;

 double xblad = 0.0000000001;

 std::cout <<std::fixed<<std::setprecision(20);

//  std::cout<<xc<<std::endl;

 if(fabs(xc - 0.3)<xblad) {

     std::cout<<"suma="<<xc<<std::endl;

 }


  std::cout<<"\n\n\n-----------------------------------   Zadanie 4   ----------------------------------------------------\n\n\n";

 float suma = 0.0;

    for(int i=0; i<100; ++i)

        suma+=0.1f;

 std::cout <<std::fixed<<std::setprecision(20);

 std::cout <<"suma="<<suma<<" natomiast wynik powinien wynosic 10.0, roznica bledu: "<<suma-10.0<<std::endl;

 

 std::cout<<"\n\n\n-----------------------------------   Zadanie 5   ----------------------------------------------------\n\n\n";
 double tablica[5] = {1.00E+21, 17.0, -10.0, 130.0, -1.00E+21}, suma5 = 0;
 int licznik=1;
 std::cout <<std::fixed<<std::setprecision(5);
 for (int i=0;i<5;i++)
    for(int j=0;j<5;j++){
        if(j!=i){
            for(int k=0;k<5;k++){
                if(k!=j && k!=i){
                    for(int m=0;m<5;m++){
                        if(m!=i && m!=j && m!=k){
                            for(int n=0;n<5;n++){
                                if(n!=i && n!=j && n!=m && n!=k){
                                     suma5=tablica[i]+tablica[j]+tablica[k]+tablica[m]+tablica[n];
                                     if(suma5==137.0){
                                        std::cout<<licznik<<". Wynik dodawania liczb: "<<tablica[i]<<"   +   "<<tablica[j]<<"   +   "<<tablica[k]<<"   +   "<<tablica[m]<<"   +   "<<tablica[n]<<" = "<<suma5<<std::endl;
                                        licznik++;
                                     }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    

 std::cout<<"\n\n\n-----------------------------------   Zadanie 6   ----------------------------------------------------\n\n\n";

 

 float tmp = 5.0;

 show_32_bits(tmp);

 

 unsigned long int* tmp_as_int = (unsigned long int*) (&tmp);

 show_32_bits(*tmp_as_int);

 

 unsigned long int bit_1 = (unsigned long int) (tmp);

 show_32_bits(bit_1);

 

 unsigned long int new_as_int = (*tmp_as_int - bit_1);

 show_32_bits(new_as_int);

 

 float new_tmp = *(float*)(&new_as_int);

 show_32_bits(new_tmp);

 

 

 return 0;

}