# количество положительных и сумму

from random import randint as rnd

# A = []
# for i in range(10):
#     A.append(rnd(-20, 20))

A = [rnd(-10, 10) for i in range(6)]
print(A)

summ = 0
multy = 1
count_positive = 0
count_negative = 0
for i in A:
    if i > 0:
        count_positive += 1
        summ += i
    elif i < 0:
        count_negative += 1
        multy *= i
print('answer', count_positive, summ)
print('answer2', count_negative, multy)