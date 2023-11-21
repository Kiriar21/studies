disp("Wspolrzedne wezlow");

w1=[-5,5]
w2=[-3,1]
w5=[-2,4]
w3=[1,2]
w4=[2,-1]
w6=[4,-1]



X=[w1(1,1)^0, w1(1,1)^1, w1(1,1)^2, w1(1,1)^3, w1(1,1)^4, w1(1,1)^5;
   w2(1,1)^0, w2(1,1)^1, w2(1,1)^2, w2(1,1)^3, w2(1,1)^4, w2(1,1)^5;
   w3(1,1)^0, w3(1,1)^1, w3(1,1)^2, w3(1,1)^3, w3(1,1)^4, w3(1,1)^5;
   w4(1,1)^0, w4(1,1)^1, w4(1,1)^2, w4(1,1)^3, w4(1,1)^4, w4(1,1)^5;
   w5(1,1)^0, w5(1,1)^1, w5(1,1)^2, w5(1,1)^3, w5(1,1)^4, w5(1,1)^5;
   w6(1,1)^0, w6(1,1)^1, w6(1,1)^2, w6(1,1)^3, w6(1,1)^4, w6(1,1)^5];
   
disp("Macierz X");
disp(X);

Y=[w1(1,2); w2(1,2); w3(1,2); w4(1,2); w5(1,2); w6(1,2)];
disp("Macierz Y");
disp(Y);

A=inv(X)*Y;
disp("Macierz wspolczynnikow");
disp(A); 

fprintf(' W(x)=%f*x^5 +%f*x^4 +%f*x^3 +%f*x^2 + %f*x + %f \n', A(6,1), A(5,1), A(4,1), A(3,1), A(2,1), A(1,1));  

x=[-6:1:6];
y=zeros(1,13);
 y=A(1,1)+A(2,1)*x.+A(3,1)*x.^2+A(4,1)*x.^3+A(5,1)*x.^4+A(6,1)*x.^5;
plot(x,y); 
grid on;   
hold on;    

vector_x=[ w1(1,1), w2(1,1), w3(1,1), w4(1,1), w5(1,1), w6(1,1)]; 
vector_y=[0,0,0,0,0,0];
for i=1:6
  vector_y(1,1)=vector_y(1,1)+A(i,1)*w1(1,1)^(i-1);   
  vector_y(1,2)=vector_y(1,2)+A(i,1)*w2(1,1)^(i-1);   
  vector_y(1,3)=vector_y(1,3)+A(i,1)*w3(1,1)^(i-1);
  vector_y(1,4)=vector_y(1,4)+A(i,1)*w4(1,1)^(i-1);  
  vector_y(1,5)=vector_y(1,5)+A(i,1)*w5(1,1)^(i-1);
  vector_y(1,6)=vector_y(1,6)+A(i,1)*w6(1,1)^(i-1);
end

plot(vector_x,vector_y,'rx');
plot(w1(1,1),w1(1,2),'--gs');
plot(w2(1,1),w2(1,2),'--gs');  
plot(w3(1,1),w3(1,2),'--gs');  
plot(w4(1,1),w4(1,2),'--gs');
plot(w5(1,1),w5(1,2),'--gs');
plot(w6(1,1),w6(1,2),'--gs');

title('Interpolacja wielomianowa');
ylabel('Os y');
xlabel('Os x');