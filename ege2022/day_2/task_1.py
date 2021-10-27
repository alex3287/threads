# 4567 -> 4 + 5 + 6 + 7 22
# 123 -> 6
# 3 -> 3

def sum_digits_number(number):
    s = str(number)
    summa = 0
    for i in s:
        summa += int(i)
    return summa


def sum_digits_number2(number):
    summa = 0
    while number > 0:
        digit = number % 10
        summa += digit
        number //= 10
    return summa


x = int(input('-> '))
print(sum_digits_number(x))
print(sum_digits_number2(x))