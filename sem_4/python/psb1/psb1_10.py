def has22(array):
    for i in range(len(array) - 1):
        if array[i] == 2 and array[i+1] == 2:
            return True

    return False

if __name__ == "__main__":
    numbers = list()

    print("Enter the list of numbers: ")
    number = 0
    while number != -1:
        number = int(input())
        numbers.append(number)
    numbers.pop(len(numbers) - 1)

    print(has22(numbers))

    