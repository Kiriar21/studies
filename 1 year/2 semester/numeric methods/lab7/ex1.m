wspolczynniki=[3, -4, 2, 1, 0, 3, -5];
%Metoda Newtona (stycznych)

function SzacowanyBlad = MetodaNewtona(wspolczynniki)
%---------------------------Tytul------------------------------  
disp("Metoda Newtona tzw. Metoda Stycznych (szukanie szacowanego bledu przyblizenia)");
%-------------------------Wypisanie danych---------------------
disp("Funkcja: f(x)= 3x^6 - 4x^5 + 2x^4 + x^3 + 3x - 5 = 0 ");
disp("");
disp("Wspolczynniki wielomianu f(x):");
disp(wspolczynniki);
disp("");
disp("Pierwiastki rownania f(x)=0");
disp(roots(wspolczynniki));
%Podajemy wartosc pierwszego przyblizena
x0=15; 
%Podajemy dokladnosc obliczen
dokladnoscSigma=0.1;
%Podajemy maksymalna ilosc iteracji 
nMax=25;
n=1;
disp(['Pierwsze przyblizenie wynosi ', num2str(x0)]);
disp("");
%polyder - oblicza pochodna -> wektor wspolczynnikow wielomianu pochodnej
pochodna=polyder(wspolczynniki);
pom=0;
%Iteracja while liczaca nam szacowany blad
while n<nMax
  pom=x0;
  x0=x0-polyval(wspolczynniki,x0)/polyval(pochodna,x0);
  %Liczenie szacowanego bledu ze wzoru  delta = x(n)-x(n-1)
  SzacowanyBlad=x0-pom;
  disp(['Przyblizenie obliczone w ramach ', num2str(n), ' iteracji wynosi: ',num2str(x0),
  'Szacowany blad tej iteracji wynosi: ', num2str(SzacowanyBlad)]);
  n=n+1;
end 

endfunction;

MetodaNewtona(wspolczynniki);


disp("");
disp("");
disp("");


wspolczynniki1=[1, 2, -88, -320];

%Metoda Bisekcji
function SzacowanyBlad1 = MetodaBisekcji(wspolczynniki1)
%---------------------------Tytul------------------------------  
disp("Metoda Bisekcji");
disp("Funkcja: f(x)= x^3 + 2*x^2 - 88*x -320 = 0 ");
disp("");
disp("Pierwiastki rownania f(x)=0 ");
disp(roots(wspolczynniki1));
disp("");
%-------------------------Wypisanie danych---------------------
%Podajemy dok?adno?c obliczen
dokladnoscSigma1=0.01;
%Zakres x'ow
x1=-2;
x2=20;
fprintf("Dokladnosc sigma: %f, zakres przedzialu < %f , %f >", dokladnoscSigma1, x1, x2); 
disp("");
disp("");
n=1;

roznica=abs(x2-x1);

while roznica>dokladnoscSigma1
    x=(x1+x2)/2;
    n=n+1;
    if polyval(wspolczynniki1,x)*polyval(wspolczynniki1,x2) <= 0
      x1=x;
    else
      x2=x;
    end
    roznica=(x2-x1);
    SzacowanyBlad1=1/2^n*abs(x2-x1);
    disp(['Przyblizenie dla ', num2str(n), ' iteracji to: ', num2str(x),
    ' . Szacowany blad tej iteracji wynosi: ', num2str(SzacowanyBlad1)]);
end

endfunction;

MetodaBisekcji(wspolczynniki1);

wspolczynniki2=[1,-3,-9,-5,0];

disp("");
disp("");
disp("");

%Metoda Siecznych
function SzacowanyBlad2 = MetodaSiecznych(wspolczynniki2)
%---------------------------Tytul------------------------------  
disp("Metoda Siecznych");
disp("Funkcja: f(x)= x^4 - 3*x^3 - 9*x^2 - 5*x = 0 ");
disp("");
disp("Pierwiastki rownania f(x)=0 ");
disp(roots(wspolczynniki2));
disp("");
%-------------------------Wypisanie danych---------------------
%Dwa pierwsze przyblizenia
x1=30;
x2=25;
%Dokladnosc obliczen
dokladnoscSigma2=0.001;
n=1;
nMax=25;
x=zeros(n);
while n<nMax
  x=x2-polyval(wspolczynniki2,x2)*((x-x1)/(polyval(wspolczynniki2,x2)-polyval(wspolczynniki2,x1)));
  x1=x2;
  x2=x;  
  SzacowanyBlad2=x2-x1;
  n=n+1;
  disp(['Przyblizenie dla ', num2str(n), ' iteracji to: ', num2str(x),' . Szacowany blad tej iteracji wynosi: ', num2str(SzacowanyBlad2)]);
end

endfunction

MetodaSiecznych(wspolczynniki2);

