import json


def mapper(filename):
    map_result = []
    with open(filename, 'r') as file:
        train_data = json.loads(file.read())
        for train_info in train_data:
            map_result.append((train_info['train_name'], 1))
    return map_result


def shuffle_sort(map_result):
    shuffle_sort_result = {}
    for train_info in sorted(map_result):
        if train_info[0] in shuffle_sort_result:
            shuffle_sort_result[train_info[0]].append(train_info[1])
        else:
            shuffle_sort_result[train_info[0]] = [train_info[1]]
    return shuffle_sort_result


def reducer(sort_and_shuffle_result):
    reducer_result = []
    for train_name in sort_and_shuffle_result:
        reducer_result.append((train_name, sum(sort_and_shuffle_result[train_name])))
    reducer_result.sort(key=lambda kv: -kv[1])
    return reducer_result


if __name__ == "__main__":
    k = int(input('Enter the value of k: '))
    reducer_result = reducer(shuffle_sort(mapper("schedules.json")))[:k]
    print(reducer_result)
