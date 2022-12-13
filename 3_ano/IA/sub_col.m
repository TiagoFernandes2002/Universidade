
%Funções
f1 = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);
f2 = @(x,y) -10*(x/5 - x.^3 - y.^5).*exp(-x.^2 - y.^2);
f3 = @(x,y) -1/3 * exp(-(x+1).^2 -y.^2);
%Funçao principal
fxy = @(x,y) abs(f1(x,y) + f2(x,y) + f3(x,y));

%%fxy = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);

close all;

xy_max = [3 3];
xy_min = [-3 -3];

%Geração de ponto aleatorio
rx=(rand-0.5)*2*3;
ry=(rand-0.5)*2*3;

hold on
%plot(sx,sy,'b*')

%parametros da figura
vx=linspace(-3,3,100);
vy=linspace(-3,3,100);

[X,Y]=meshgrid(vx,vy);


FX=fxy(X,Y);

%desenho da figura
contour(X,Y,FX,20);

%nº de iterações 
n=1000;

%vetores
vx = zeros(n,1);
vy = zeros(n,1);
vxy = zeros(n,1);
vmax = zeros(2,1);

aux= 1;

for it = 1:n
d=0.05;%vizinhança

%geração de novos pontos
  new_x= rx + (rand-0.5)*2*d;
  new_y= ry + (rand-0.5)*2*d;

   
    %verifica se está mais alto que o guardado
    if fxy(rx,ry)<fxy(new_x,new_y) 
              
        rx=new_x;
        ry=new_y;
        plot(rx,ry,'bo') % colocar pontos no grafico
    end
 
    %guardar pontos no vetor
    vx(it) = rx;
    vy(it) = ry;
    vxy(it) = fxy(rx,ry);

    %verificar se estabilizou
    if(it>10 && vxy(it-10)==vxy(it))
        
        aux
        vmax(aux) = fxy(rx,ry);
        fxy(rx,ry)
        rx
        ry
        aux = aux + 1;
        %criar novo ponto aleatorio
        rx=(rand-0.5)*2*3;
        ry=(rand-0.5)*2*3;
        
    end

end 



hold off

%grafico de x
figure
plot(vx,'r')
%grafico de y
figure
plot (vy,'b')
%grafico dos maximos
figure
plot(vxy,'g')
legend("fxy");