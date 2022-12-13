

%Funções
f1 = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);
f2 = @(x,y) -10*(x/5 - x.^3 - y.^5).*exp(-x.^2 - y.^2);
f3 = @(x,y) -1/3 * exp(-(x+1).^2 -y.^2);
%função principal
fxy = @(x,y) abs(f1(x,y) + f2(x,y) + f3(x,y));

 %Funções
        g1 = @(x,y) 9.*(1-x.^2).*exp(-x.^2 -(1+y).^2);
        g2 = @(x,y) -5*(x/5 - x.^3 - y.^5).*exp(-x.^2 - y.^2);
        g3 = @(x,y) -1/3 * exp(-(x+1).^2 -y.^2);
        %função principal
        gxy = @(x,y) abs(g1(x,y) + g2(x,y) + g3(x,y));



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

%variavel para trocar de função quando estabiliza
n=0;


%%vetores
vx = zeros(20,1);
vy = zeros(20,1);
vxy = zeros(20,1);
vT = zeros(20,1);
vp = zeros(20,1);

%%interações, Temperatura e d
it=1;
t_it = 1;
T=90;
d=1.5;%vizinhaça

while(n ~= 1) %criterio: n iterações
    if (t_it == 10)
        t_it = 0;
        T = T * 0.86;
        if (T < 0)
            T = 0;
        end
    end
    
    %geração de novos pontos
    new_x= rx + (rand-0.5)*2*d;
    new_y= ry + (rand-0.5)*2*d;

    %limitador de coordenadas
    while new_y < -3
        new_y= ry + (rand-0.5)*2*d;
    end
    while new_x < -3
        new_x= rx + (rand-0.5)*2*d;
    end
    while new_y > 3
        new_y= ry + (rand-0.5)*2*d;
    end
    while new_x > 3
        new_x= rx + (rand-0.5)*2*d;
    end
    
    %diferença dos pontos 
    %calculo da probabilidade apartir dele e da
    %Temperatura da interação
    deltaE= fxy(new_x,new_y) - fxy(rx,ry);
    p = exp(deltaE / T);

     if T < 20 %diminui a vizinhança
        d= 0.25;
    end

    if T < 5 %diminui a vizinhança
        d= 0.05;
    end

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

   
    %estabilização
     if(it>10 && vxy(it-10)==vxy(it))
         maximo_func1 = fxy(rx,ry)
        n = 1;
        
     end

     t_it = t_it + 1; %iterador temperatura
    it = it + 1; %iterador principal
end

figure

x=linspace(-3,3,100);
y=linspace(-3,3,100);

[X,Y]=meshgrid(x,y);

GX=gxy(X,Y);

contour(X,Y,GX,20)
hold on

t_it = 1;
T=90;
d=1.5;

while(n ~= 2) %criterio: n iterações
    if (t_it == 10)
        t_it = 0;
        T = T * 0.86;
        if (T < 0)
            T = 0;
        end
    end
    
    %geração de novos pontos
    new_x= rx + (rand-0.5)*2*d;
    new_y= ry + (rand-0.5)*2*d;
    
    %limitador de coordenadas
    while new_y < -3
        new_y= ry + (rand-0.5)*2*d;
    end
    while new_x < -3
        new_x= rx + (rand-0.5)*2*d;
    end
    while new_y > 3
        new_y= ry + (rand-0.5)*2*d;
    end
    while new_x > 3
        new_x= rx + (rand-0.5)*2*d;
    end


    %diferença dos pontos 
    %calculo da probabilidade apartir dele e da
    %Temperatura da interação
    deltaE= gxy(new_x,new_y) - gxy(rx,ry);
    p = exp(deltaE / T);

    
   if T < 20 %diminui a vizinhança
        d= 0.25;
    end

    if T < 5 %diminui a vizinhança
        d= 0.05;
    end

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
    vxy(it) = gxy(rx,ry);
    vT(it) = T;
    vp(it) = p;
    

    %colocar os pontos no grafico
    plot(rx,ry,'go')
    hold on

   
    %estabilização
     if(it>10 && vxy(it-10)==vxy(it))
         maximo_func2 = gxy(rx,ry)
        n = 2;
        
     end

     t_it = t_it + 1; %iterador temperatura
    it = it + 1; %iterador principal
end



%graficos de x e y


figure
plot(vx,'r')
legend("x")

figure
plot (vy,'b')
legend("y")


%grafico da função
figure
plot(vxy,'C')
legend("fxy");

%Grafico da probabilidade
figure
plot(vp,'mo')
legend("p");

%grafico da Temperatura
figure
plot(vT,'yp')
legend("Temperatura");

hold off
