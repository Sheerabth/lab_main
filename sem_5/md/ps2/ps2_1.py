def map(file_content):
    sentence_list = file_content.split("\n")
    intermediate_list = [1 for _ in sentence_list]
    return intermediate_list


def reduce(intermediate_list):
    return sum(intermediate_list)


if __name__ == "__main__":
    file = open("Sample_file_1.txt")
    intermediate_list = map(file.read())
    print(reduce(intermediate_list))
