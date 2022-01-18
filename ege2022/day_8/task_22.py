print('-> ', int('72111111', 9))
for i in range(1, 50000000):
    x = i
    a = 1
    b = 0
    while x > 0:
        d = x % 9 # 0,1,2,3,4,5,6,7,8
        a *= d
        if d < 5:
            b += d
        x //= 9
    if a == 14 and b == 8:
        print(i)

# a = 2 * 7
# b = 2 + 1 + 1 + 1 + 1 +1 + 1

#  72111111
