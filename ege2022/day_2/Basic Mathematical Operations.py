def basic_op(operator, value1, value2):
    if operator == '+':
        return value1 + value2
    if operator == '-':
        return value1 - value2
    if operator == '*':
        return value1 * value2
    return value1 / value2


A = '+', 4, 7 # 11
print(basic_op('+', 4, 7))