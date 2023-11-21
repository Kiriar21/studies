disp('Zadanie 1');
disp('');
disp('Transponowanie macierzy');
disp('');
A=[3,1;2,4;1,3;2,2;5,6];
[l_w,l_k] = size(A)
disp('');
B=zeros(l_k,l_w);
C=[-1,2,6,-3,-1;6,4,-5,1,5];
D=zeros(l_k, l_w);
disp('Macierz pierwsza');
disp(A);
disp('');
disp('Macierz druga');
disp(C);
disp('');
for i=1:l_w
  for j=1:l_k
    B(j,i)=A(i,j);
  end;
end;
disp('Macie pierwsza po transponowaniu');
disp(B);
disp('');
[l_w,l_k] = size(C)
disp('');
if size(B) == size(C)
  for i=1:l_w
    for j=1:l_k
      D(i,j)=B(i,j)-C(i,j);
      %fprintf(" D(%x,%x)=%x",i,j,D(i,j));
    end;
    %fprintf('\n');
  end;
else
  disp("Nie mozna niestety odjac tych macierzy, sprawdz poprawnosc danych");
end;
disp('');
disp('Rozwiazanie:');
disp('');
display(D);

