def remove_duplicates(nums:list):
    return list(set(nums))

if __name__ == "__main__":
    num = 0
    nums = set()
    print("Enter the numbers: ")
    while num != -1:
        num = int(input())
        nums.add(num)
    nums.remove(-1)

    print(remove_duplicates(nums))
