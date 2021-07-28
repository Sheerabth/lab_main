a = int(input("Enter the integer: "))
print(a)


ans = 0
for i in range(0, 4):
    num = 0
    for j in range(i, -1, -1):
        num += a * 10**j
    ans += num

print(ans) 
