def find_base_frequency(DNA:str):
    base_frequency = dict()
    for base in DNA:
        if base not in base_frequency:
            base_frequency[base] = 1
        else:
            base_frequency[base] += 1
    return base_frequency

if __name__ == "__main__":
    print(find_base_frequency(input("Enter the DNA string: ")))