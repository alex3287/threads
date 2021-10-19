# сумму чисел от 1 до n
n = int(input('-> '))
s = 0
for i in range(1, n+1, 2):
    s += i
print(s)
# print(s)
# найти формулы нахождения суммы нечетных чисел