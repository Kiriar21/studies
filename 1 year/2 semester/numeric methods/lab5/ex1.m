%wspolrzedne punktow
x=[-10,-5,1,6,9,11];
y=[3,-5,1,9,0,4];
if length(x)==length(y)
%ustalamy stopien wielomianu aproksymacyjnego
stopien=2;
n=length(x);

X=zeros(stopien+1,stopien+1);
A=zeros(stopien+1,1);
Y=zeros(stopien+1,1);

%obliczanie macierzy X
for i=1:stopien+1
  for j=1:stopien+1
    for k=1:n
      %algorytm ustalaj¹cy wartoœci macierzy X
      X(i,j)=X(i,j)+x(k)^(i+j-2);
    end
  end  
end  
disp("Macierz X");
disp(X);
%obliczanie macierzy Y
for i=1:stopien+1
  for k=1:n
    Y(i,1)=Y(i,1)+(x(k)^(i-1))*y(k);    
  end
end  
disp("Macierz Y");
disp(Y);
A=inv(X)*Y;
disp("Macierz A - wspolczynnikow");
disp(A);

%obliczanie wartoœci funkcji na podstawie obliczonych wartoœci wspó³czynników wielomianu
yi=zeros(1,n);

for i=1:n
  for j=1:stopien+1
    yi(1,i)=yi(1,i) + A(j,1)*x(i)^(j-1);
  end
end  
disp("Macierz yi")
disp(yi);
plot(x,y, 'gx--');
grid on;
hold on;
plot(x,yi, 'rs--');
%title("Niebieskie - punkty rzeczywiste, czerwone - punkty obliczone na podstawie uzyskanego wielomianu");
tytul_rys=sprintf('Niebieskie - punkty rzeczywiste, czerwone - punkty obliczone na podstawie uzyskanego wielomianu %d stopnia',stopien);
%sprintf - zapisuje tekst sformatowany do wskazanego bufora znakowego
title(tytul_rys);
else
  disp("Liczba wspolrzednych x nie jest równa liczbie wspolrzednych y");
end


