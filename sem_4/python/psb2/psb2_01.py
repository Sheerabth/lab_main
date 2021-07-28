sentence = input("Enter the sentence: ")
words = set(sentence.split())
sorted_words = ' '.join(sorted(words))

print(sorted_words)