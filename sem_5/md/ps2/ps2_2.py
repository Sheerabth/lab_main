intermediate_list = []


def map_func(file):
    map_list = [(x, 1) for x in file.read() if x.isalpha()]
    intermediate_list.extend(map_list)


def sort_and_shuffle():
    dictionary = {}
    for char_tuple in intermediate_list:
        if char_tuple[0] in dictionary.keys():
            dictionary[char_tuple[0]].append(char_tuple[1])
        else:
            dictionary[char_tuple[0]] = [char_tuple[1]]
    return dictionary


def reduce_func(character, count_list):
    return character, sum(count_list)


if __name__ == "__main__":
    file_1 = open("Sample_file_1.txt")
    file_2 = open("Sample_file_2.txt")
    map_func(file_1)
    map_func(file_2)
    dictionary = sort_and_shuffle()
    for key, value in dictionary.items():
        print(reduce_func(key, value))
