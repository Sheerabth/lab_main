% 1 (i)
syms x;
f = (x^2 - 5)*(x^3-2*x+3);
diff(f,x)

% 1 (ii)
syms x
f = sin(x)*cos(x);
diff(f)

% 2
syms x y;
f = cos(2*x)-x^2*exp((5*y)) + 3*y^2;
diff(f,x)
diff(f,y)
diff(f,x,2)
diff(f,y,2)
diff(diff(f,y),x)
diff(diff(f,x),y)
diff(f,y,4)

% 3
syms x;
f = (x^2 - 5)*(x^3-2*x+3);
eval(subs(diff(f,x), x, 2))
f = (x^2 + 1)/(5*x - 3);
eval(subs(diff(f), 2))

% 4
syms x y;
f = cos(2*x)-x^2*exp((5*y)) + 3*y^2;
eval(subs(diff(f,x), [x,y], [2,3]))

% 5
syms x y z;
int(sin(2*x)* cos(x))
int(sqrt(9 - 4*x^2))
int(log(tan(x)), 0, pi/2)
int(int(int(x+y, z, 0, 4-x^2), x, 0, 2), y, 0, 1)

% 6
syms y(x);
dsolve(diff(y,x) == exp(3*x) + sin(x))
dsolve(diff(y,x,3) == x^2)
dsolve(diff(y,x) + cos(x)*y == sin(x)*cos(x))

% 7
syms y(x);
dx = diff(y,x);
dx_2 = diff(y,x,2);
dsolve(diff(y,x,3) == y - x*diff(y,x) + 4*diff(y,x,2), dx(2) == 2, dx_2(2) == 3)