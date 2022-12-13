
%Funções
f1 = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);
f2 = @(x,y) -10*(x/5 - x.^3 - y.^5).*exp(-x.^2 - y.^2);
f3 = @(x,y) -1/3 * exp(-(x+1).^2 -y.^2);
%função principal
fxy = @(x,y) abs(f1(x,y) + f2(x,y) + f3(x,y));


%%fxy = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);

close all;

xy_max = [3 3];
xy_min = [-3 -3];


%Geração de ponto aleatorio
rx=(rand-0.5)*2*3;
ry=(rand-0.5)*2*3;

hold on


x=linspace(-3,3,100);
y=linspace(-3,3,100);

[X,Y]=meshgrid(x,y);


FX=fxy(X,Y);

contour(X,Y,FX,20);

n=5000;


%%vetores
vx = zeros(n,1);
vy = zeros(n,1);
vxy = zeros(n,1);
vT = zeros(n,1);
vp = zeros(n,1);

%%interações, Temperatura e d
it=1;
t_it = 1;
T=90;
d=0.05;

while(it < n) %criterio: n iterações
    if (t_it == 10)
        t_it = 0;
        T = T * 0.9;
        if (T < 0)
            T = 0;
        end
    end
    
    %geração de novos pontos
    new_x= rx + (rand-0.5)*2*d;
    new_y= ry + (rand-0.5)*2*d;
    
    %diferença dos pontos 
    %calculo da probabilidade apartir dele e da
    %Temperatura da interação
    deltaE= fxy(new_x,new_y) - fxy(rx,ry);
    p = exp(deltaE / T);


    if (p < 0)
        p = 0; % probabilidade
    end
    if   deltaE > 0 %maximização
        rx = new_x;
        ry = new_y;
        p=1;
    elseif rand < p
        rx = new_x;
        ry = new_y;
    end

    %Guardar pontos nos vetores
    vx(it) = rx;
    vy(it) = ry;
    vxy(it) = fxy(rx,ry);
    vT(it) = T;
    vp(it) = p;
    

    %colocar os pontos no grafico
    plot(rx,ry,'bo')
    hold on

    t_it = t_it + 1; %iterador temperatura
    it = it + 1; %iterador principal

end

%graficos de x e y
figure
plot(vx,'r')
xlabel("it");
hold on
plot (vy,'b')
ylabel("x,y");
legend('x','y');

%grafico da função
figure
plot(vxy,'b')
legend("fxy");

%Grafico da probabilidade
figure
plot(vp,'bo')
legend("p");

%grafico da Temperatura
figure
plot(vT,'p')
legend("Temperatura");

hold off
%plot do p e do t