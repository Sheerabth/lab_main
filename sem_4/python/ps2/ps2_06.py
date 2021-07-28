import numpy as np

def inverse(array):
    print(np.linalg.inv(A))

if __name__ == "__main__":
    row = int(input("Enter the number of rows: "))
    col = int(input("Enter the number of columns: "))
    print("Enter the matrix:")
    array = [[int(input()) for j in range(col)] for i in range(row)]
    A = np.array(array)
    inverse(A)