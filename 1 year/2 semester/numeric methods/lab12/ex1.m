%Dane
poczatekZakres=-5;
koniecZakres=15;
n=25;
nn=100;
nnn=1000;


function rysuj(n,poczatekZakres,koniecZakres,ktory)
Fx=[0.5,-5.5,35];
subplot(3,2,ktory);
x=linspace(poczatekZakres,koniecZakres,n);
y=polyval(Fx,x);
plot(x,y);
grid on;
hold on;
for i=1:length(x)
  xx=[x(i),x(i)];
  yy=[0,y(i)];
  plot(xx,yy);
end;
title({"Wykres pola dla n="; n});
ylabel("OS OY");
xlabel("OS OX");

endfunction

function duzyX = wyliczX(x)
  duzyX=0.5*x^2-5.5*x^1+35;
endfunction
%metoda prostokatow
disp("");
disp("Metoda prostokatow");
disp("");
function metPros(n,poczatekZakres,koniecZakres,ktory)
  x=(koniecZakres-poczatekZakres)/n;
  pole=0.00;
  srodek=poczatekZakres+(koniecZakres-poczatekZakres)/(2.0*n);

  for i=1:n
    duzyX=wyliczX(srodek);
    pole=pole+duzyX;
    srodek=srodek+x;
  endfor
  disp('Dla n');
  disp(n);
  disp("Pole wynosi:");
  PoleOst=pole*x;
  disp(PoleOst);
  rysuj(n,poczatekZakres,koniecZakres,ktory);
endfunction
metPros(n,poczatekZakres,koniecZakres,1)
metPros(nn,poczatekZakres,koniecZakres,3)
metPros(nnn,poczatekZakres,koniecZakres,5)
disp("");
disp("Metoda trapezow");
disp("");%metoda trapezow
function metTrap(n,poczatekZakres,koniecZakres,ktory)
  p=(koniecZakres-poczatekZakres)/n;
  pole=0.00;
  podstawa_a=wyliczX(poczatekZakres);

  for i=1:n
    podstawa_b=wyliczX(poczatekZakres+p*i);
    pole=pole+(podstawa_a+podstawa_b);
    podstawa_a=podstawa_b;
  endfor
  disp('Dla n');
  disp(n);
  disp("Pole wynosi:");
  PoleOst=pole*0.5*p;
  disp(PoleOst);
  rysuj(n,poczatekZakres,koniecZakres,ktory);
endfunction
metTrap(n,poczatekZakres,koniecZakres,2)
metTrap(nn,poczatekZakres,koniecZakres,4)
metTrap(nnn,poczatekZakres,koniecZakres,6)
