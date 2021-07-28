def most_frequent(sentence:str):
    letter_frequency = dict()
    for letter in sentence:
        if letter in letter_frequency:
            letter_frequency[letter] += 1
        else:
            letter_frequency[letter] = 1
    letter_frequency = dict(sorted(letter_frequency.items(), key=lambda item: item[1], reverse = True))
    for letter in letter_frequency.keys(): print(letter)

if __name__ == "__main__":
    sentence = input("Enter the sentence: ")
    most_frequent(sentence)