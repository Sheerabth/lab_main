dimension = int(input("Enter the dimension of the vector: "))

print("Enter the vector u")
u = [int(input()) for i in range(dimension)]

print("Enter the vector v")
v = [int(input()) for j in range(dimension)]

distance = 0

for i in range(dimension):
    distance = distance + u[i]**2 + v[i]**2

distance = distance**(1/2)

print("The distance between u and v is", distance)