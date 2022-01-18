A = [0, 1]
for i in range(2, 16):
    if i < 3 and i < 11 or i == 11:
        A.append(A[i-1])
    elif i % 3 == 0 and i < 11:
        A.append(A[i-1]+A[i-2]+A[i//3])
    else:
        A.append(A[i - 1] + A[i - 2])
print(A)