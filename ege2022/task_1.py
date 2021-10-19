# сумму чисел от 1 до n
n = int(input('-> '))
s = 0
# s + 1 + 2 + 3 +... + 10  -> n * (n + 1) / 2
for i in range(1, n+1):
    s += i  # s = s + i
print(s)
print(n*(n+1)//2)