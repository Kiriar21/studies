x=[0,0.0526316,0.105263,0.157895,0.210526,0.263158,0.315789,0.368421,0.421053,0.473684,0.526316,0.578947,0.631579,0.684211,0.736842,0.789474,0.842105,0.894737,0.947368,1];
y=[-481.417,-482.92,-501.606,-443.647,-438.929,-626.749,-472.809,-214.559,-699.632,-795.636,40.6906,-383.716,-1335.6,-128.182,405.786,-1562.33,-1055.31,1169.76,-842.536,-2435.03];

x1=linspace(0,1,10)
y1 = -436.951*x1 -345.743

plot(x,y,'--k',x1,y1,'-r'); 
grid on;
title("Wykres aproksymacji. Czarna przerywana linia - laczy punkty rzeczywiste/ nasza funkcja, czerwona linia - wykres funkcji aproksymujacej");
xlabel('OS OX')
ylabel('OS OY')