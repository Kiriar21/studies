%Dane 
n=2;
A=rand(n,n);
Y=rand(n,1);
X=zeros(n,1);

nn=4;
AA=rand(nn,nn);
YY=rand(nn,1);
XX=zeros(nn,1);

nnn=6;
AAA=rand(nnn,nnn);
YYY=rand(nnn,1);
XXX=zeros(nnn,1);

function [X] = Zad4(n,A,Y,X)
  if n>0
if det(A)!=0
  %tworzenie macierzy rozszerzonej
  R=[A Y];
  %wektor pomocniczy
  vec_pom=zeros(1,n+1);

 %procedury majace na celu zadbanie aby element R(1,1) byl rozny od 0
  if R(1,1)==0
    for i=1:n
      if R(i+1,1)!=0
        vec_pom=R(1,:);
        R(1,:)=R(i+1,:);
        R(i+1,:)=vec_pom;
      endif
    endfor
  endif
  
  %zerowanie - zamiana 0 na przekatnej
  for i=1:n-1
      for j=i+1:n
        if R(i,i)==0
            if R(j,i)!=0
              vec_pom=R(i,:);
              R(i,:)=R(j,:);
              R(j,:)=vec_pom;
            endif;
          endif;
    endfor
 endfor

  %zerowanie - obliczenia
 for i=1:n-1
   for j=i+1:n
      mnoznik=R(j,i)/R(i,i);
      for k=1:n+1;
          R(j,k)-=R(i,k)*mnoznik;
      endfor
   endfor
 endfor 

  %Obliczanie naszego xn
   X(n,1)=R(n,n+1)/R(n,n);
   %Obliczanie kazdego kolejnego xn-i
  for i=n:-1:1
     s=0;
     for j=i+1:n
       s+=R(i,j)*X(j,1);
     endfor
     X(i,1)=(R(i,n+1)-s)/R(i,i);
     i=i-1;
  endfor
   
  disp("Rozwiazanie rownania X");
  disp(X);
  disp("Sprawdzenie X=inv(A)*Y")
  disp(inv(A)*Y);
else
  disp("Podany uklad rownan nie jest ukladem oznaczonym (wyznacznik z macierzy wspolczynnikow rowny jest 0)");
end
else
  disp("N jest mniejsze od 0");
end
endfunction

Zad4(n,A,Y,X);
Zad4(nn,AA,YY,XX);
Zad4(nnn,AAA,YYY,XXX);