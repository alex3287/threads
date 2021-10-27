def multiple_of_index(arr):
    A = []
    for i in range(1, len(arr)):
        if arr[i] % i == 0:
            A.append(arr[i])
    return A


def multiple_of_index2(arr):
    A = []
    for i, j in enumerate(arr):
        if i != 0 and j % i == 0:
            A.append(j)
    return A


A = [22, -6, 32, 82, 9, 25]  # [-6, 32, 25]
print(multiple_of_index2(A))