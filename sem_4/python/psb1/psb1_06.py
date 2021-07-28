number = int(input("Enter a number: "))
ans = dict()

for i in range(1, number + 1):
    ans[i] = int(i)**2

print(ans)