f1 = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);
f2 = @(x,y) -10*(x/5 - x.^3 - y.^5).*exp(-x.^2 - y.^2);
f3 = @(x,y) -1/3 * exp(-(x+1).^2 -y.^2);

fxy = @(x,y) abs(f1(x,y) + f2(x,y) + f3(x,y));


%%fxy = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);

close all;

xy_max = [3 3];
xy_min = [-3 -3];

sx=(rand-0.5)*2*3;
sy=(rand-0.5)*2*3;

hold on
%plot(sx,sy,'b*')

x=linspace(-3,3,100);
y=linspace(-3,3,100);

[X,Y]=meshgrid(x,y);


FX=fxy(X,Y);

contour(X,Y,FX,20);

n=10;

x = zeros(n,1);
y = zeros(n,1);
xy = zeros(n,1);

Tmax = 90;


aux= 0;
t=0;
T=90;
d=0.05;

while(t ~=n)
   h=1;
   while h<=100

  tx= sx + (rand-0.5)*2*d;
    ty= sy + (rand-0.5)*2*d;

       deltaE= fxy(sx,sy) - fxy(tx,ty);
       p = exp(-deltaE) / T;
       if   deltaE < 0
            sx=tx;
            sy=ty;
           
       elseif rand < p
            sx=tx;
            sy=ty;
       end
       plot(sx,sy,'bo')
       h=h+1;
   end
T=T-10;
t=t+1;
end




%%hold off


%%figure
%%plot(x,'r')
%%hold on
%%plot (y,'b')

%%figure
%%plot(xy,'g')