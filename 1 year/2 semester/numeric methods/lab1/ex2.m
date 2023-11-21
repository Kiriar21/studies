function [C] = Zadanie2(A,B,X)
  [l_wA,l_kA] = size(A);
  [l_wB,l_kB] = size(B);
% sprawdzenie czy macierze mozna pomnozyc (w==k)
  if l_kA == l_wB
% mnozenie macierzy przez dowolnie podana liczbe
      for i=1:l_wA
        for j=1:l_kA
          A(i,j) = X*A(i,j);
        endfor
      endfor
      for i=1:l_wA
        for j=1:l_kB
          suma=0;
% iteracja po kazdym elemencie do wymnozenia
          for k=1:l_kA
             suma=suma+(A(i,k)*B(k,j));
          end;
% przypisanie wartosci sumy z mnozenia macierzy do nowej tablicy
          C(i,j)=suma;
        end;
      end;
% przypadek, gdy niespelniony zostal warunek ze liczba_kolumnA==liczba_wierszyB
  else
    disp('Nie mozna wymnozyc tych macierzy.');
  end;
endfunction;
  

