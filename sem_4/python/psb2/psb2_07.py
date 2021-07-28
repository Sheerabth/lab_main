A = [1, 2, 3, 4, 5]
B = [5, 8, 9, 2, 6, 4]

if A == B:
    print("The two sets are equal")
else:
    B1 = [num for num in B if num not in A]
    B2 = [num for num in A if num not in B]
    print(B1, B2)    