% ZADANIE 3
% Napisać funkcję która dla zadanego zakresu i rozdzielczości określi zbiór
% argumentów, a następnie wyliczy zbiór wartości y=sin(2x)+cos(0.5x),
% oraz wyliczy zbiór wartości dla dowolnej innej
% funkcji. Wykresy obu funkcji należy wyświetlić w jednym oknie, 
% przy czym dla pełnego zakresu
% argumentów dla pierwszej funkcji oraz dla ograniczonego zakresu argumentów
% i wartości dla
% drugiej funkcji (polecenie axis), opisując przy tym osie i tytuł wykresu.
% Tytuły wykresów i druga
% funkcja wg własnego pomysłu – inne niż w filmie instruktarzowym.


function [x,y,z] = lab1_zad3(a,b,c)
x=a:b:c;
y=sin(2*x)+cos(0.5*x);
plot(x,y);
xlabel('Oś X - zad3');
ylabel('Oś Y - zad3');
title('Artur Matusczyk lab1_Zad3 - pierwszy wykres')
figure; % tworzenie drugiego wykresu na jednym
z=2*cos(10*x)+sin(3.5*x)-1;
plot(x,z);
title('Artur Matuszczyk lab1_Zad3 - drugi wykres')
figure;
subplot(2,1,1);
plot(x,y);
title('Artur Matuszczyk - wykres 1')
subplot(2,1,2);
plot(x,z);
title('Artur Matuszczyk - wykres 2')
minx=min(x);
maxx=max(x);
miny=min(z);
maxy=max(z);
axis([minx-1, maxx+1, miny-1, maxy+1]);
end