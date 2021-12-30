def sum_digit_35(n):
    summa = 0
    while n:
        summa += n % 10
        n //= 10
    return summa
    # return n % 10 + n // 1000 + n // 100 % 10 + n // 10 % 10


A = [int(i) for i in open('input.txt')]
# print(A)

sum_35 = 0
for i in A:
    if i % 35 == 0:
        sum_35 += sum_digit_35(i)
print(sum_35)

count = 0
sum_min = 20001
for i in range(len(A)-1):

    if (A[i] > sum_35 and hex(A[i+1])[-2:] == 'ef' and A[i+1] <= sum_35) or (A[i+1] > sum_35 and hex(A[i])[-2:] == 'ef'and A[i] <= sum_35):
        count += 1
        if A[i] + A[i+1] < sum_min:
            sum_min = A[i] + A[i+1]

print(count, sum_min)