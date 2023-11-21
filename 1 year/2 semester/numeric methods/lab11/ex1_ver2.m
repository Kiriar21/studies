%t(x)=x^4+3x^3-x+2
tx=[1,3,0,-1,2];
%m(x)=2x*ln(2x+1)+(x^2/x+1)
mx=inline("2*x*log(2*x+1)+(x*x/x+1)");
x=3;
h=0.1;
x1=x+h;
x2=x-h;
warning("off");
disp("---------------------------------------");
disp("t(x)=x^4+3x^3-x+2");
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
disp("m(x)=2x*ln(2x+1)+(x^2/x+1)");
disp("Pierwsza pochodna w punkcie");
mprim=(mx(x1)-mx(x2))/(2*h);
disp(mprim);
disp("Sprawdzenie");
%((4*x)/(2*x+1))+2*log(2*x+1)+1
disp("k'(x)=((4*3)/(2*3+1)) + 2*log(2*3+1)+1");
disp(4*x/(2*x+1)+2*log(2*x+1)+1);
disp("Druga pochodna w punkcie");
mprimprim=(mx(x1)+mx(x2)-2*mx(x))/h^2;
disp(mprimprim);
disp("Sprawdzenie");
%(8*(x+1)/(2*x+1)^2)
disp("k''(x)=12*(3+1)/(2*3+1)^2");
disp((8*(x+1))/(2*x+1)^2);
disp("---------------------------------------");
disp("3*(t''(x)-m''(x))^2+25/(t'(x)+m'(x))^2+5");
wynikdzialania=(3*(tprimprim-mprimprim)^2+25)/((tprim+mprim)^2+5);
disp("Wynik dzialania: ");
disp(wynikdzialania);
disp("---------------------------------------");
disp("Zadanie dodatkowe:");
disp("Oblicz t'''(x)-3*t''(x)+2*t'(x)-3*t(x)");
t=x^4+3*x^3-x+2;
tprimprimprim=6*(4*x+3);
%t'=4*x^3+9*x^2-1
%t''=6*x*(2*x+3)
wynikDodatkowe=tprimprimprim-3*tprimprim+2*tprim-3*tprim;
disp("Wynik dzialania:");
disp(wynikDodatkowe);
disp("---------------------------------------");