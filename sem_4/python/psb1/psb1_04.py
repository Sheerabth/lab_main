S = input("Enter the string: ")
i = int(input("Enter the integer: "))
c = input("Enter the charachter: ")

newString = list(S)
newString[i] = c
S = ''.join(newString)

print(S)
