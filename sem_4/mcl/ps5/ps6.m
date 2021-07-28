syms t;
f = (t+1)^2*exp(3*t);
laplace(f)

syms t
subplot(2, 2, 1)
fplot(t*cos(2*t))
subplot(2, 2, 2)
fplot(laplace(t*cos(2*t)))

t = linspace(0,10*pi);
f = (t<2*pi).*0 + (t>2*pi).*sin(t);
f(t==2*pi) = NaN;
plot(t,f);

t = -10:1:10;
t1 = (t>4 & t<6);
f(t>4 & t<6) = t1-1;

f(t>6) = 0;


