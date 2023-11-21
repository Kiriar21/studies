x=[-13,-10,-8,-5,-2,1,3,5,8,10,12];
Fy=[1,8,-2,9,11,6,-2,-9,3,7,11];
stopien=4;
stopien1=2;
stopien2=8;
function lab6(x,Fy,stopien)
if length(x)==length(Fy)
  n=length(x);
  if stopien<n-1
    A=polyfit(x,Fy,stopien);
    disp(A);
    Wy=zeros(1,n);
    for i=1:n
      for j=1:stopien+1
        Wy(1,i)=Wy(1,i)+A(1,j)*x(1,i)^(stopien+1-j);     
      end 
    end
    figure(stopien);
    plot(x,Fy,'rx');
    grid on;
    hold on;
    plot(x, Wy);
    fprintf("Stopien: %f",stopien);
    disp("");
    disp("Obliczenia:");
    disp("Blad bezwzgledny");
    bww=0;
    for i=1:n
      bww=bww+abs(Fy(i)-Wy(i));
    endfor
    disp(bww);
    disp("Blad kwadratowy");
    bkk=0;
    for i=1:n
      bkk=bkk+(Fy(i)-Wy(i))^2;
    endfor
    disp(bkk);
    disp("Sredni blad procentowy");
    sbpp=0;
    for i=1:n
      sbpp=sbpp+(1/n)*abs((Fy(i)-Wy(i))/Fy(i))*100;
    endfor
    disp(sbpp);
    disp("Srednie odchylenie od krzywej");
    sookk=0;
    for i=1:n
      sookk=sookk+(Fy(i)-Wy(i))^2/(n-stopien-1);
    endfor
    sookk=sqrt(sookk);
    disp(sookk);
    opis=sprintf("Stopien=%f, Bw=%f, Bk=%f, Sbp=%f, Sook=%f",stopien, bww, bkk, sbpp, sookk);
    title(opis);
    disp("");
    disp("");
    disp("");
    disp("Sprawdzenie naszych obliczen dzialaniami na wektorach: ");
    disp("Blad bezwzgledny");
    bw=sum(abs(Fy-Wy))
    disp("Blad kwadratowy");
    bk=sum((Fy-Wy).^2)
    disp("Sredni blad procentowy");
    sbp=1/n*sum(abs((Fy-Wy)./Fy))*100
    disp("Srednie odchylenie od krzywej");
    sook=sqrt(sum((Fy-Wy).^2)/(n-stopien-1))  
    disp("");
    disp("");
    disp("");
    
    step=(max(x)-min(x))/1000; 
    Ry=zeros(1,1001);
    Rx=zeros(1,1001);
    for i=1:1001
      Rx(1,i)=min(x)+(i-1)*step;      
      for j=1:stopien+1
         Ry(1,i)=Ry(1,i)+A(1,j)*Rx(1,i)^(stopien+1-j);     
      end 
    end
    plot(Rx, Ry,'--r'); 
    grid on;
    hold on;

  else
    disp("Za duzy stopien wielomianu aproksymujacego");  
  end
else
disp("Liczba wspolrzednych x nie jest rootswna liczbie wspolrzednych Fy");  
end  
endfunction

lab6(x,Fy,stopien);
lab6(x,Fy,stopien1);
lab6(x,Fy,stopien2);

