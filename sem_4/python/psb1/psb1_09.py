numbers = list()

print("Enter the list of numbers: ")
number = 0
while number != -1:
    number = int(input())
    numbers.append(number)

numbers.pop(len(numbers) - 1)

max_value = numbers[0]
min_value = numbers[0]
sum = 0
for x in numbers:
    max_value = max(max_value, x)
    min_value = min(min_value, x)
    sum += x

centered_avg =  (sum - max_value - min_value) / (len(numbers) - 2)
print(centered_avg)
