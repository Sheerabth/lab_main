example = input("Enter the string: ")
alphabets = [False] * 26

example_list = list(example.lower())
for alphabet in example_list:
    if alphabet != ' ':
        alphabets[ord(alphabet) - 97] = True

for alphabet in alphabets:
    if alphabet == False:
        print("Its not a panagram")
        exit()

print("Its a panagram")

