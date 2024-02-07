% zadanie 2 - zbior arg, zbior wartosci wykres funkcji 

function y = lab1_zad2(a,b,c)
x=a:b:c;
y=sin(2*x)+cos(0.5*x);
plot(x,y)
xlabel('oś X')
ylabel('oś Y')
title('Artur Matuszczyk')
end

% a - od ktorego argumentu
% b - co ile 
% c - do ktorego 
