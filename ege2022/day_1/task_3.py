# максимум из 3-х
x1 = int(input('->'))
x2 = int(input('->'))
x3 = int(input('->'))

if x1 > x2:
    maxi = x1
else:
    maxi = x2
if maxi < x3:
    maxi = x3

print(maxi)