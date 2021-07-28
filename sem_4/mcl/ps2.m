% Problem Sheet 2

% 1
row_vector = [3, 4, 2.55, 68/16, 45, 100^(1/3), cosd(25), 0.05]

% 2
column_vector = [32/3.2^2; (sind(35))^2; 6.1; (log(29))^2; 133]

% 3
row_vector = linspace(12, 81, 12)

% 4
column_vector = linspace(-21, 12, 15)'

% 5
a = [zeros(1,8), 7.5]

% 6
vecA = 49: -3: 10
vecB = 1:8
vecB(1:4) = vecA(1:4)
vecB(5:8) = vecA(end-3:end)

% 7
A = [linspace(0, 30, 6); linspace(600, 0, 6); linspace(0, 5, 6)]

% 8
a = [7 2 -3 1 0]
b = [-3 10 0 7 -2]
c = [1 0 4 -6 5]

% a
A = [a; b; c]

% b
B = [a', b', c']

% 9
a = [7 2 -3 1 0]
b = [-3 10 0 7 -2]
c = [1 0 4 -6 5]

% a
A = [a(1:3); b(1:3); c(1:3)]

% b
B = [a(end-2:end)' b(end-2:end)' c(end-2:end)']

% 10
A = [(2:6)', (5:9)', (8:12)', (11:15)', (14:18)', (17:21)']
B = [linspace(5, 30, 6); linspace(30, 55, 6); linspace(55, 80, 6)]
v = 99:-1:91
A(:,end-4+1:end) = [B(1,1:4) ; A(2,end-4+1:end) ; B(2,1:4) ; v(5:8) ; B(3,3:end)]