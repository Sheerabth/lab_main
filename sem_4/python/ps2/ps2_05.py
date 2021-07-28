def formula(xi, min_num, max_num):
    return (xi-min_num)/(max_num-min_num)

def normalize(nums):
    min_num = min(nums)
    max_num = max(nums)
    normalized_nums = [formula(i, min_num, max_num) for i in nums ]
    return normalized_nums

if __name__ == "__main__":
    size = int(input("Enter the size of the vector: "))

    print("Enter the vector:")
    u = [int(input()) for i in range(size)]
    
    print(normalize(u))