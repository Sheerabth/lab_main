import numpy

def cos_angle(vector1, vector2):
    return numpy.dot(vector1, vector2)/numpy.linalg.norm(vector1)*numpy.linalg.norm(vector2)

if __name__ == "__main__":
    dimension = int(input("Enter the dimension of the vector: "))

    print("Enter the vector u")
    u = [int(input()) for i in range(dimension)]

    print("Enter the vector v")
    v = [int(input()) for j in range(dimension)]

    print(cos_angle(u, v))