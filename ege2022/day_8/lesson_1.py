# задача №17
A = [int(i) for i in open('input.txt')]
print(A)

count = 0
summ = 0
for i in A:
    if i % 2 != 0:
        count += 1
        summ += i
averange = summ / count
print(averange)

count_pair = 0
max_sum = 0

for i in range(len(A)-1):
    if (A[i] % 5 == 0 or A[i+1] % 5 == 0) and (A[i+1] < averange or A[i] < averange):
        count_pair += 1
        if A[i] + A[i+1] > max_sum:
            max_sum = A[i] + A[i+1]


print(count_pair, max_sum)