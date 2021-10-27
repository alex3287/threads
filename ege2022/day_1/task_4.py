# функция максимум из 3-х
def max_3(x1, x2, x3):
    if x1 > x2:
        maxi = x1
    else:
        maxi = x2
    if maxi < x3:
        maxi = x3
    return maxi


x1 = int(input('-> '))
x2 = int(input('-> '))
x3 = int(input('-> '))

print(max_3(x1, x2, x3))