def kreprekar(number):
    number_list = [int(x) for x in str(number**2)] 
    list1 = number_list[:len(number_list)//2]
    list2 = number_list[len(number_list)//2:]

    num1 = int(''.join([str(i) for i in list1]))
    num2 = int(''.join([str(i) for i in list2]))
    if number == num1 + num2:
        return True
    return False

if __name__ == "__main__":
    num = int(input("Enter a number: "))
    print(kreprekar(num))