inputString = input("Enter the string: ")

n = len(inputString)
i = 0
while i < n - 1:
    count = 1
    while(i < n-1 and inputString[i] == inputString[i + 1]):
        count += 1
        i += 1
    i += 1

    print(str(count) + inputString[i - 1], end="")     