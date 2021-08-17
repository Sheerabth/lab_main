def mapper(filename, target_word):
    map_result = []
    line_count = 0
    with open(filename, 'r') as file:
        for line in file:
            line = line.replace(".", " ").replace(",", " ")
            for word in line.split():
                if word == target_word:
                    map_result.append((word, line_count))
            line_count += 1
    return map_result


def sort_and_shuffle(map_result):
    sort_and_shuffle_result = {}
    for word_tuple in map_result:
        if word_tuple[0] in sort_and_shuffle_result:
            sort_and_shuffle_result[word_tuple[0]].append(word_tuple[1])
        else:
            sort_and_shuffle_result[word_tuple[0]] = [word_tuple[1]]
    return sort_and_shuffle_result


if __name__ == "__main__":
    target_word = input("Enter the word: ")
    print(sort_and_shuffle(mapper("Sample_file_2.txt", target_word)))
