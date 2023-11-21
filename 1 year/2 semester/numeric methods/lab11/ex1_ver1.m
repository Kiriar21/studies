%t(x)=-x^4+2x^3-x+3
tx=[-1,2,0,-1,3];
%k(x)=3x*ln(2x+1)+(x^2/x+1)
kx=inline("3*x*log(2*x+1)+(x*x/x+1)");
x=3;
h=0.1;
x1=x+h;
x2=x-h;
warning("off");
disp("---------------------------------------");
disp("t(x)=-x^4+2x^3-x+3");
disp("Pierwsza pochodna w punkcie");
tprim=(polyval(tx,x1)-polyval(tx,x2))/(2*h);
disp(tprim);
disp("Sprawdzenie");
disp(polyval(polyder(tx),x));
disp("Druga pochodna w punkcie");
tprimprim=(polyval(tx,x1)+polyval(tx,x2)-2*polyval(tx,x))/h^2;
disp(tprimprim);
disp("Sprawdzenie");
disp(polyval(polyder(polyder(tx)),x));
disp("---------------------------------------");
disp("k(x)=3x*ln(2x+1)+(x^2/x+1)");
disp("Pierwsza pochodna w punkcie");
kprim=(kx(x1)-kx(x2))/(2*h);
disp(kprim);
disp("Sprawdzenie");
%((6*x)/(2*x+1))+3*log(2*x+1)+1
disp("k'(x)=6*3/2*3+1 + 3log(2*3+1)+1");
disp(6*x/(2*x+1)+3*log(2*x+1)+1);
disp("Druga pochodna w punkcie");
kprimprim=(kx(x1)+kx(x2)-2*kx(x))/h^2;
disp(kprimprim);
disp("Sprawdzenie");
%(12*(x+1)/(2*x+1)^2)
disp("k''(x)=12*(3+1)/(2*3+1)^2");
disp((12*(x+1))/(2*x+1)^2);
disp("---------------------------------------");
disp("5*(t''(x)-k''(x))^2+10/(t'(x)+k'(x))^2+1");
wynikdzialania=(5*(tprimprim-kprimprim)^2+10)/((tprim+kprim)^2+1);
disp("Wynik dzialania: ");
disp(wynikdzialania);
disp("---------------------------------------");
disp("Zadanie dodatkowe:");
disp("Oblicz t'''(x)-2*t''(x)+3*t'(x)-4*t(x)");
t=-x^4+2*x^3-x+3;
tprimprimprim=12-24*x;
%t'=-4*x^3+6*x^2-1
%t''=-12*(x-1)*x
wynikDodatkowe=tprimprimprim-2*tprimprim+3*tprim-4*tprim;
disp("Wynik dzialania:");
disp(wynikDodatkowe);
disp("---------------------------------------");