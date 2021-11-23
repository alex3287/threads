A = [int(i) for i in open('17_1.txt')]
print(A)

count = 0
min_sum = 20001

for i in range(len(A)-1):
    if A[i] % 7 == 0 and A[i+1] % 17 != 0 or A[i] % 17 != 0 and A[i+1] % 7 == 0:
        count += 1
        if A[i] + A[i+1] < min_sum:
            min_sum = A[i] + A[i+1]

print(count, min_sum)