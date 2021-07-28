num = 0
A = set()
print("Enter the numbers in set 1: ")
while num != -1:
    num = int(input())
    A.add(num)
A.remove(-1)

num = 0
B = set()
print("Enter the numbers in set 2: ")
while num != -1:
    num = int(input())
    B.add(num)
B.remove(-1)

print("Intersection is ", A.intersection(B))
print("Uninon is ", A.union(B))
print("Difference is ", A-B)
print("Symmetric Difference is ", (A-B).union(B-A))