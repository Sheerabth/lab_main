def mapper(filename):
    map_result = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.replace(".", " ").replace(",", " ").lower()
            for word in line.split():
                map_result.append((word, 1))
    return map_result


def shuffle_sort(map_result):
    shuffle_sort_result = {}
    for word_tuple in sorted(map_result):
        if word_tuple[0] in shuffle_sort_result:
            shuffle_sort_result[word_tuple[0]].append(word_tuple[1])
        else:
            shuffle_sort_result[word_tuple[0]] = [word_tuple[1]]
    return shuffle_sort_result


def reducer(sort_and_shuffle_result):
    reducer_result = []
    for word in sort_and_shuffle_result:
        reducer_result.append((word, sum(sort_and_shuffle_result[word])))
    return reducer_result


if __name__ == "__main__":
    print(reducer(shuffle_sort(mapper("Sample_file_2.txt"))))

