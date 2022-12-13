fxy = @(x,y) 3.*(1-x.^2).*exp(-x.^2 -(1+y).^2);

xy_max = [3 3];
xy_min = [-3 -3];

sx=(rand-0.5)*2*3;
sy=(rand-0.5)*2*3;

hold on
plot(sx,sy,'b*')

x=linspace(-3,3,100);
y=linspace(-3,3,100);

[X,Y]=meshgrid(x,y);


FX=fxy(X,Y);

contour(X,Y,FX,20);



for i = 1:1000
    d=0.05;
    tx= sx + (rand-0.5)*2*d;
    ty= sy + (rand-0.5)*2*d;

    if fxy(sx,sy)<fxy(tx,ty) 
    sx=tx;
    sy=ty;
    end

plot(sx,sy,'bo')
 
end 
hold off