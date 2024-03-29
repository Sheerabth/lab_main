% 1 a
(14.8^2 + 6.5^2)/3.8^2 + 55/(sqrt(2) + 14)
% ans = 21.663

% 1 b
(-3.5)^3 + (exp(6)/log(524)) + 206^(1/3)
% ans = 27.461

% 2 a
(16.5^2 * (8.4 - sqrt(70)))/(4.3^2 - 17.3)
% ans = 7.6412

% 2 b
(5.2^3 - 6.4^2 + 3)/(1.6^8 - 2) + (13.3/5)^1.5
% ans = 6.845

% 3 a
15 * ((sqrt(10) + 3.7^2) / (log10(1365) + 1.9))
% ans = 50.204

% 3 b
(2.5^3*(16 - 216/22)) / (1.7^4 + 14) + (2050)^(1/4)
% ans = 11.0501

% 4 a
(2.3^2 * 1.7) / sqrt((1 - 0.8^2)^2 + (2 - sqrt(0.87))^2)
% ans = 7.9842

% 4 b
2.34 + 2.7 * (5.9^2 - 2.4^2) / 2 + 9.8 * log(51)
% ans = 80.0894

% 5 a
sin(7 * pi/9 )/(cos(5 * pi/7))^2 + (tan(5 * pi/12)/7)
% ans = 2.1867

% 5 b
tand(64)/(cosd(14)^2) - (3*sind(80)) / 0.9^(1/3) + cosd(55) / sind(11)
% ans = 2.1238

% 6
x = 2.34

% a
2*x^4 - 6*x^3 + 14.8*x^2 + 9.1
% ans = 73.226

% b
exp(2*x) / sqrt(14 + x^2 - x)
% ans = 26.034

% 7
t = 6.8

% a
log(abs(t^2 - t^3))
% ans = 5.5917

% b
75 * cos(0.8 * t - 3) / (2 * t)
% ans = -4.2122

% 8
x = 8.3
y = 2.4

% a
x^2 + y^2 - (x^2 / y^2)
% ans = 62.6899

% b
sqrt(x * y) - sqrt(x + y) + ((x - y)/(x - 2*y))^2 - sqrt(x/y)
% ans = 2.1741

% 9
a = 13
b = 4.2
c = (4 * b)/a
d = (a * b * c) / (a + b + c)

% a
a * b /(c + d) + (d/c) * (a/b) - (a - b^2) * (c + d)
% ans = 43.529

% b
sqrt(a^2 + b^2) / (d - c) + log(abs(b - a + c - d))
% ans = 7.8410

% 10
a = 0.5;
x = (3*pi)/5;
x1 = 1/2*(x) - (sin(2*a*x) / (4*a));
x = pi/9;
x2 = 1/2*(x) - (sin(2*a*x) / (4*a));
x1 - x2
% ans = 0.4634

% 11 a
a = 9;
b = 3;
y = 2 * pi * sqrt((a^2 + b^2)/2)

% ans = 42.1489

% 11 b
syms a b
[sola, solb] = solve((2*pi)*sqrt((a^2 + b^2)/2) == 20 , 2*a == b, a>=0, b>=0)

% sola = (2*10^(1/2))/pi
% solb = (4*10^(1/2))/pi
 

% 12 a

x = pi/9
y = sin(4*x) == 4*sin(x)*cos(x) - 8*(sin(x))^3*cos(x)
sin(4*x)
4*sin(x)*cos(x) - 8*(sin(x))^3*cos(x)

% ans = 0.9848
% y = 0

% 12 b
y = pi/9
y = cos(2*x) == (1 - (tan(x))^2) / (1 + (tan(x))^2)
cos(2*x)
(1 - (tan(x))^2) / (1 + (tan(x))^2)

% ans = 0.7660
% y = 1

% 13 a
a = 16
c = 50
b = sqrt(c^2 - a^2)
% b = 47.3709

% 13 b
acosd(b/c)
% ans = 18.6629

% 14
A = 2
B = 23
C = 13
D = -24
x = 8
y = 3
z = -10
d = abs(A*x + B*y + C*z + D) / sqrt(A^2 + B^2 + C^2)
% d = 2.6042