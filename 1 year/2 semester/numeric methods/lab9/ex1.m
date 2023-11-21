% Zadanie 5
% rozmiar wektora b jest adekwatny do rozmiaru macierzy A
% obliczenia realizowane sa dla 12-stu iteracji
disp("Zadanie 5 realizowane z listy zadan Lab9 ");
A=[20,-5,4,-4; 3,10,-3,2-1; 2,0,4,0; 2,-1,-2,8];
b=[12; 20; 28; 52];
numer1=1;

AA=[0,10,3,-1;20,3,2,10;2,3,0,10;2,-1,8,2];
bb=[35; 103; 27; 23];
numer2=2;

AAA=[1, 2, 3, 4;2, 0, 5, 2;1, 1, 4, 2;2, 1, 1, 1];
bbb=[40; 34; 31; 16];
numer3=3;

function UkladLiniowy(A,b,numer)
disp("");
fprintf('Rozwiazanie dla rownania o numerze %f ',numer);
disp("");
n=length(b);
L=zeros(n);
D=zeros(n);
U=zeros(n);

for i=1:n-1
  if A(i,i)==0
    pom=A(i,:);
    A(i,:)=A(i+1,:);
    A(i+1,:)=pom;
    i=1;
  else
    continue;
  endif
end

for i=1:n
  for j=1:n
    if i>j             
       L(i,j)=A(i,j);
    elseif i<j       
       U(i,j)=A(i,j);
    else                
       D(i,j)=A(i,j);
    end
  end
end

N=inv(D);
H=zeros(n);
for i=1:n
  for j=1:n
    if i!=j
      H(i,j)=-A(i,j)/A(i,i); 
    end
  end
end

%if max(sum(abs(H)))<1 || max(sum(abs(H')))<1

  x=zeros(n,1);
  r=1;
  danyWiersz=1;
  t=1;
  while r>0.3 && t<13
    disp(['Wynik dla iteracji nr ',num2str(t)]);
    x=-N*(L+U)*x+N*b;
    r=sum(abs((A*x)-b));
    disp("r: ");
    disp(r);
    t=t+1;
    disp(x);
  end
  disp("Sumaryczny blad rozwiazania");
  disp(sum(abs((A*x)-b)));
  disp("Sprawdzenie - wynik dokladny");
  disp(inv(A)*b);


endfunction

UkladLiniowy(A,b,numer1);
UkladLiniowy(AA,bb,numer2);
UkladLiniowy(AAA,bbb,numer3);
