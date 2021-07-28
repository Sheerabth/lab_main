terminal = 0
websites = list()
print("Enter the websites: ")
while terminal != 'end':
    terminal = input()
    websites.append(terminal)
websites.pop(len(websites) - 1)

suffixes = set()
for website in websites:
    parsed = website.split('.')
    suffixes.add(parsed[len(parsed) - 1])

for suffix in suffixes:
    print(suffix, end=',')