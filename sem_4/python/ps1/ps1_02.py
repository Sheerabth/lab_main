def maximum(nums:list):
    if len(nums) == 1:
        return nums[0]
    else:
        current_max = maximum(nums[1:])
        if nums[0] > current_max:
            return nums[0]
        else:
            return current_max

if __name__ == "__main__":
    num = 0
    nums = list()
    print("Enter the numbers: ")
    while num != -1:
        num = int(input())
        nums.append(num)
    nums.remove(-1)
    print("Maximum is ", maximum(nums))