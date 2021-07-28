import numpy as np

def is_symmetric(array):
    return (array == np.transpose(array)).all()

def is_stochastic(array):
    array = np.transpose(array)
    for nums in array:
        for num in nums:
            if num < 0: return False
        if sum(nums) != 1: return False
    return True

def is_orthogonal(array):
    return (np.identity(np.size(array, 0)) == np.dot(array, np.transpose(array))).all()

if __name__ == "__main__":
    row = int(input("Enter the number of rows: "))
    col = int(input("Enter the number of columns: "))
    print("Enter the matrix:")
    array = [[int(input()) for j in range(col)] for i in range(row)]
    A = np.array(array)
    if is_stochastic(A):
        print("The matrix is Stochastic")
    else:
        print("Matrix is not Stochastic")

    if is_orthogonal(A):
        print("The matrix is Orthogonal")
    else:
        print("Matrix is not Orthogonal")

    if is_symmetric(A):
        print("The matrix is Symmetric")
    else:
        print("Matrix is not Symmetric")