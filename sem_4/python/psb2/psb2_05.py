num = 0
nums = set()
print("Enter the numbers: ")
while num != -1:
    num = int(input())
    nums.add(num)
nums.remove(-1)

print("The number of elements in the set is ", len(nums))