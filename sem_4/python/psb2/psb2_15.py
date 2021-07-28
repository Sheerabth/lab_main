import random

upper_case = [chr(char) for char in range(65, 65+26)]
digits = [chr(char) for char in range(48, 48+10)]
lower_case = [chr(char) for char in range(97, 97+26)]
special_charachters = [chr(char) for char in range(33, 48)] + [chr(char) for char in range(58, 65)] + [chr(char) for char in range(91, 97)] + [chr(char) for char in range(123, 127)]

def generate_password(length:int):
    password = ''
    random_upper = random.choice(upper_case)
    random_digits = random.choice(digits)
    random_lower = random.choice(lower_case)
    random_special = random.choice(special_charachters)

    password = list(random_upper + random_digits + random_lower + random_special)
    password += random.sample((upper_case + digits + lower_case + special_charachters), length - 4)
    
    random.shuffle(password)
    return ''.join(password)

if __name__ == "__main__":
    length = int(input("Enter the length of password(min=4): "))
    print("Generated password:", generate_password(length))
