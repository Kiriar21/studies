A=[4,3,0.5;1, -1, 5;-0.5, 2, 2];
B=[-2,1.5,4;-2, 1, 2.5;-1, -2, -1];
disp("Macierz A");
disp("");
disp(A);
disp("");
disp("Macierz B");
disp("");
disp(B);
disp("");
[lw,lk] = size(A);
C=zeros(lw,lk);
% mnozymy dwie macierze
for i=1:lw
    for j=1:lk
      for k=1:lw
        C(i,j) += A(i,k)*B(k,j); 
      endfor
    endfor
endfor
disp("Po wymnozeniu otrzymujemy macierz: ");
disp("");
disp(C);
disp("");
%obliczamy wyznacznik macierzy 
detC = C(1,1)*C(2,2)*C(3,3)+C(1,2)*C(2,3)*C(3,1)+C(1,3)*C(2,1)*C(3,2)-C(1,3)*C(2,2)*C(3,1)-C(1,1)*C(2,3)*C(3,2)-C(1,2)*C(2,1)*C(3,3);
disp("Wyznacznik macierzy to: ");
disp("");
disp(detC);
disp("");
%sprawdzenie czy mozna wyznaczyc odwotna macierz (wyznacznik nie moze byc równy 0)
if detC!=0
  % tworzymy tablice o jeden rozmiar mniejsza od lw i lk aby wpisywac do niej kopie naszej glownej macierzy
  % z ktorej bedziemy mogli obliczac swoje wyznaczniki stopnia 2
   D=zeros(lw-1,lk-1);
   % petla od i oraz od j to petla potrzebna do obliczenia ostatecznego wyznacznika
  for i=1:lw
     for j=1:lk
          % zmienna w oraz zmienna k pomaga nam dostac sie do elementow tablicy D (lw-1, lk-1) o indexie w,k i wpisac do nich wartosc
          % z prawidlowego miejsca tablicy C (naszej glownej)
          w=1;
            for p=1:lw
                % warunki ifów w tym wypadku pomagaj? nam pomin?c ten wiersz i kolumne z glownej macierzy
                % aby wartosci wpisywane do tablicy D byly poprawne
                if p!=i
                   k=1;
                      for t=1:lk
                          if t!=j
                              %w koncu wpisujemy odpowiednie wartosci do tablicy dla i=1,j=1 powinnismy pominac lw=1 i lk=1 i wpisac wartosci 
                              % z indexow (2,2)(2,3)(3,2)(3,3) itd w kolejnych przypadkach
                              D(w,k)=C(p,t);
                              k=k+1;
                          endif
                      endfor
                   w=w+1;
                 endif
             endfor
       % w tablicy F obliczamy wyznacznik z naszej pomocniczej tablicy i wpisujemy go w pole o indeksie i,j (lw,lk) 
          F(i,j)=D(1,1)*D(2,2)-D(1,2)*D(2,1);
      % oraz obliczamy ze wzoru na wskaznik wartosc*(-1) do sumy indeksu wiersza i kolumny
          F(i,j)=F(i,j)*(-1)^(i+j);
     endfor
  endfor
  % Transponowanie macierzy z naszymi wynikami wyznacznikow drugiego stopnia
  disp("");
  G=zeros(lw,lk);
  for i=1:lw
    for j=1:lk
      G(j,i)=F(i,j);
    endfor
  endfor
  % obliczanie ostatecznej tablicy z nasza macierza odwrotn?
  Wynik=(1/detC)*G;
  disp("Macierz odwrotna:");
  disp("");
  disp(Wynik);
  disp("");
  disp("Sprawdzenie za pomoca wbudowanej funkcji Octave:");
  disp("");
  % polecenie inv(nazwa_Tablicy) pozwala nam policzyc odwrotna macierz, w tym samym przypadku - gdy wyznacznik jest rozny od 0
  % funkcja ta sluzy tylko do sprawdzenia poprawnosci naszego programu
  disp(inv(C));
  disp("");
  Do_spr = inv(C);
  %dodatkowy kawa?ek kodu pozwalaj?cy na sprawdzenie czy nasze tablice sa na pewno takie same (te same wartosci na tych samych indeksach)
  pomocnicza=0;
  pom1 = lw*lk;
  %przejscie po kazdej wartosci z tablicy i porownanie jej do siebie 
  for i=1:lw
    for j=1:lk
      if(Do_spr(i,j) = Wynik(i,j))
          pomocnicza++;  
      end
    endfor
  endfor
  %je?eli wszystkie elementy s? takie same wyskoczy nam komunikat, ?e sprawdzenie jest sko?czone i albo macierze sa takie same albo wystapil blad
  if(pomocnicza==pom1) 
      disp("Sprawdzenie przebieglo poprawnie. Macierze sa takie same. ");
      disp("");
  else
      disp("Wystapil b??d. Macierze nie s? takie same");
      disp("");
  end
% jezeli wyznacznik macierzy jest rowny 0 nie mozemy wyznaczyc odwrotnej macierzy 
else
  disp("Nie mozna obliczyc macierzy odwrotnej, wyznacznik rowny 0.");
  disp("");
end

